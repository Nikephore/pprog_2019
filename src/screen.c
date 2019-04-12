/**
 * @brief It defines a screen
 *
 * @file screen.h
 * @author Profesores PPROG
 * @version 1.0
 * @date 11-01-2017
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "screen.h"

#pragma GCC diagnostic ignored "-Wpedantic"

#define ROWS 23
#define COLUMNS 80
#define TOTAL_DATA (ROWS * COLUMNS) + 1

#define BG_CHAR '~'
#define FG_CHAR ' '
#define PROMPT " prompt:> "

#define ACCESS(d, x, y) (d + ((y) * COLUMNS) + (x))

struct _Area{
  int x, y, width, height;
  char *cursor;
};

char *__data;

/****************************/
/*     Funciones privadas   */
/****************************/
/*
*
* @brief: inforam si el cursor esta fuera de los limites
* @params1: el area en el cual debe estar el cursor
* @return: devuelve el lugar donde se encuentra el cursor
*
*/

int  screen_area_cursor_is_out_of_bounds(Area* area);

/*
*
* @brief: imprime la información del set por pantalla
* @params1: el set que se va a imprimir
* @return: devuelve ERROR si no se ha impreso correctamente, u OK si lo ha hecho correctamente
*
*/
void screen_area_scroll_up(Area* area);

/*
*
* @brief: sutituye los caracteres especiales
* @params1: la cadena de caracteres a sustituir si fuese necesario
* @return
*
*/
void screen_utils_replaces_special_chars(char* str);

/*
*@brief inicializa la pantalla
*@return
*/
void screen_init(){
  screen_destroy(); /* Dispose if previously initialized */
  __data = (char *) malloc(sizeof(char) * TOTAL_DATA);

  if (__data){
    memset(__data, (int) BG_CHAR, TOTAL_DATA); /*Fill the background*/
    *(__data + TOTAL_DATA - 1) = '\0';         /*NULL-terminated string*/
  }
}
/*
*@brief libera la memoria reservada para pantalla
*@return
*/
void screen_destroy(){
  if (__data)
    free(__data);
}
/*
*@brief  imprime la pantalla
*@return
*/
void screen_paint(){
  char *src = NULL;
  char dest[COLUMNS + 1];
  int i=0;

  memset(dest, 0, COLUMNS + 1);

  if (__data){
    /* puts(__data); */ /*Dump data directly to the terminal*/
    /*It works fine if the terminal window has the right size*/

    puts("\033[2J"); /*Clear the terminal*/
    for (src=__data; src < (__data + TOTAL_DATA - 1); src+=COLUMNS){
      memcpy(dest, src, COLUMNS);
      /* printf("%s\n", dest); */
      for (i=0; i<COLUMNS; i++){
	if (dest[i] == BG_CHAR){
	  printf("\033[0;34;44m%c\033[0m", dest[i]); /* fg:blue(34);bg:blue(44) */
	}else{
	  printf("\033[0;30;47m%c\033[0m", dest[i]); /* fg:black(30);bg:white(47)*/
	}
      }
      printf("\n");
    }
  }
}
/*
*@brief pide una cadena de caracteres por teclado
*@param1 str. Cadena de caracteres en la cual se almacena una nueva cadena
*@return
*/
void screen_gets(char *str){
  fprintf(stdout, PROMPT);
  if (fgets(str, COLUMNS, stdin))
    *(str + strlen(str) - 1) = 0; /* Replaces newline character with '\0' */
}
/**
*@brief inicializa el area necesaria para la pantalla
*@param1 x. La coordenada x del area
*@param2 y. La coordenada y del area
*@param3 width. La anchura del area
*@param4 height. La altura del area
*@return devuelve la direccion del area o NULL si a sucedido algun error
*/
Area* screen_area_init(int x, int y, int width, int height){
  int i = 0;
  Area* area = NULL;

  if ( (area  = (Area*) malloc (sizeof(struct _Area))) ){
    *area = (struct _Area) {x, y, width, height, ACCESS(__data, x, y)};

    for (i=0; i < area->height; i++)
      memset(ACCESS(area->cursor, 0, i), (int) FG_CHAR, (size_t) area->width);
  }

  return area;
}
/*
*@brief libera la memoria reservada  para area
*@param1 area. Area que se quiere destruir
*@return
*/
void screen_area_destroy(Area* area){
  if(area)
    free(area);
}
/*
*@brief se limpia el area  de la pantalla
*@param1 area. Area que se quiere limpiar
*@return
*/
void screen_area_clear(Area* area){
  int i = 0;

  if (area){
    screen_area_reset_cursor(area);

    for (i=0; i < area->height; i++)
      memset(ACCESS(area->cursor, 0, i), (int) FG_CHAR, (size_t) area->width);
  }
}
/*
*@brief resetea el cursor  en el area
*@param1 area. Estructura area de la cual se quiere resetear el cursor
*@return
*/
void screen_area_reset_cursor(Area* area){
  if (area)
    area->cursor = ACCESS(__data, area->x, area->y);
}
/*
*@brief imprime el area
*@param1 area. Area para imprimir
*@param2 str. Cadena de caracteres a remplazar si tiene algun carcter especial
*@return
*/
void screen_area_puts(Area* area, char *str){
  int len = 0;
  char *ptr = NULL;

  if (screen_area_cursor_is_out_of_bounds(area))
    screen_area_scroll_up(area);

  screen_utils_replaces_special_chars(str);

  for (ptr = str; ptr < (str + strlen(str)); ptr+=area->width){
    memset(area->cursor, FG_CHAR, area->width);
    len = (strlen(ptr) < area->width)? strlen(ptr) : area->width;
    memcpy(area->cursor, ptr, len);
    area->cursor += COLUMNS;
  }
}

int screen_area_cursor_is_out_of_bounds(Area* area){
  return area->cursor > ACCESS(__data,
			       area->x + area->width,
			       area->y + area->height - 1);
}

void screen_area_scroll_up(Area* area){
  for(area->cursor = ACCESS(__data, area->x, area->y);
      area->cursor < ACCESS(__data, area->x + area->width, area->y + area->height - 2);
      area->cursor += COLUMNS){
    memcpy(area->cursor, area->cursor+COLUMNS, area->width);
  }
}

void screen_utils_replaces_special_chars(char* str){
  char *pch = NULL;

  /* Replaces acutes and tilde with '??' */
  while ((pch = strpbrk (str, "ÁÉÍÓÚÑáéíóúñ")))
    memcpy(pch, "??", 2);
}
