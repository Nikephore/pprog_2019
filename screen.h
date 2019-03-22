/**
 * @brief It defines a screen
 *
 * @file screen.h
 * @author Profesores PPROG
 * @version 1.0
 * @date 11-01-2017
 * @copyright GNU Public License
 */

#ifndef __SCREEN__
#define __SCREEN__

#define SCREEN_MAX_STR 80

typedef struct _Area Area;

/*
*@brief inicializa la pantalla
*@return
*/
void  screen_init();

/*
*@brief libera la memoria reservada para pantalla
*@return
*/
void  screen_destroy();

/*
*@brief  imprime la pantalla
*@return
*/
void  screen_paint();

/*
*@brief pide una cadena de caracteres por teclado
*@param1 str. Cadena de caracteres en la cual se almacena una nueva cadena
*@return
*/
void  screen_gets(char *str);


/**
*@brief inicializa el area necesaria para la pantalla
*@param1 x. La coordenada x del area
*@param2 y. La coordenada y del area
*@param3 width. La anchura del area
*@param4 height. La altura del area
*@return devuelve la direccion del area o NULL si a sucedido algun error
*/
Area* screen_area_init(int x, int y, int width, int height);

/*
*@brief libera la memoria reservada  para area
*@param1 area. Area que se quiere destruir
*@return
*/
void  screen_area_destroy(Area* area);

/*
*@brief se limpia el area  de la pantalla
*@param1 area. Area que se quiere limpiar
*@return
*/
void  screen_area_clear(Area* area);

/*
*@brief resetea el cursor  en el area
*@param1 area. Estructura area de la cual se quiere resetear el cursor
*@return
*/
void  screen_area_reset_cursor(Area* area);

/*
*@brief imprime el area
*@param1 area. Area para imprimir
*@param2 str. Cadena de caracteres a remplazar si tiene algun carcter especial
*@return
*/
void  screen_area_puts(Area* area, char *str);

#endif
