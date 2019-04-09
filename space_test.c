/**
 * @brief It tests space module
 *
 * @file space_test.c
 * @author Victor Perea
 * @version 1.0
 * @date 01/04/2019
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "space.h"
#include "space_test.h"
#include "test.h"

#define MAX_TESTS 58

/**
 * @brief Funcion principal de pruebas para el modulo Space.
 *
 * Dos modos de ejecucion:
 *   1.-Si se ejecuta sin parametros se ejecutan todas las pruebas
 *   2.-Si se ejecuta con un numero entre 1 y el numero de pruebas solo ejecuta
 *      la prueba indicada
 *
 */
int main(int argc, char** argv) {

    int test = 0;
    int all = 1;

    if (argc < 2) {
        printf("Running all test for module Space:\n");
    } else {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
	if (test < 1 && test > MAX_TESTS) {
	  printf("Error: unknown test %d\t", test);
	  exit(EXIT_SUCCESS);
        }
    }


    if (all || test == 1) test1_space_create();
    if (all || test == 2) test2_space_create();
    if (all || test == 3) test1_space_set_name();
    if (all || test == 4) test2_space_set_name();
    if (all || test == 5) test3_space_set_name();
    if (all || test == 6) test1_space_set_north();
    if (all || test == 7) test2_space_set_north();
    if (all || test == 8) test3_space_set_north();
    if (all || test == 9) test1_space_set_south();
    if (all || test == 10) test2_space_set_south();
    if (all || test == 11) test3_space_set_south();
    if (all || test == 12) test1_space_set_east();
    if (all || test == 13) test2_space_set_east();
    if (all || test == 14) test3_space_set_east();
    if (all || test == 15) test1_space_set_west();
    if (all || test == 16) test2_space_set_west();
    if (all || test == 17) test3_space_set_west();
    if (all || test == 18) test1_space_get_name();
    if (all || test == 19) test2_space_get_name();
    if (all || test == 20) test1_space_get_object();
    if (all || test == 21) test2_space_get_object();
    if (all || test == 22) test1_space_get_north();
    if (all || test == 23) test2_space_get_north();
    if (all || test == 24) test1_space_get_south();
    if (all || test == 25) test2_space_get_south();
    if (all || test == 26) test1_space_get_east();
    if (all || test == 27) test2_space_get_east();
    if (all || test == 28) test1_space_get_west();
    if (all || test == 29) test2_space_get_west();
    if (all || test == 30) test1_space_get_id();
    if (all || test == 31) test2_space_get_id();
    if (all || test == 32) test1_space_set_description();
    if (all || test == 33) test2_space_set_description();
    if (all || test == 34) test3_space_set_description();
    if (all || test == 35) test1_space_get_description();
    if (all || test == 36) test2_space_get_description();
    if (all || test == 37) test1_space_add_object();
    if (all || test == 38) test2_space_add_object();
    if (all || test == 39) test3_space_add_object();
    if (all || test == 40) test1_space_delete_object();
    if (all || test == 41) test2_space_delete_object();
    if (all || test == 42) test3_space_delete_object();
    if (all || test == 43) test1_space_add_link();
    if (all || test == 44) test2_space_add_link();
    if (all || test == 45) test3_space_add_link();
    if (all || test == 46) test1_space_set_gdesc();
    if (all || test == 47) test2_space_set_gdesc();
    if (all || test == 48) test3_space_set_gdesc();
    if (all || test == 49) test4_space_set_gdesc();
    if (all || test == 50) test1_space_get_gdesc_illustration();
    if (all || test == 51) test2_space_get_gdesc_illustration();
    if (all || test == 52) test3_space_get_gdesc_illustration();
    if (all || test == 53) test1_space_check_object();
    if (all || test == 54) test2_space_check_object();
    if (all || test == 55) test3_space_check_object();
    if (all || test == 56) test4_space_check_object();
    if (all || test == 57) test1_space_destroy();
    if (all || test == 58) test2_space_destroy();
    PRINT_PASSED_PERCENTAGE;

    return 1;
}

/**
 * @test Prueba la función de creación de un espacio
 * @pre Un identificador como parámetro
 * @post Un puntero no nulo al espacio creado
 */
void test1_space_create() {
  int result = space_create(5)!=NULL ;
  PRINT_TEST_RESULT(result);
}

/**
 * @test Prueba la función de creación de un espacio
 * @pre Un identificador como parámetro
 * @post El identificador del espacio es el introducido
 */
void test2_space_create() {
    Space *s;
    s = space_create(4);
    PRINT_TEST_RESULT(space_get_id(s) == 4);
}

/**
 * @test Prueba la función para establecer el nombre de un espacio
 * @pre Nombre que establecer al espacio
 * @post La salida debe ser OK
 */
void test1_space_set_name() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_name(s, "hola") == OK);
}
/**
 * @test Prueba la función para establecer el nombre de un espacio
 * @pre El espacio al que establecer el nombre es un puntero a NULL
 * @post La salida debe ser ERROR
 */
void test2_space_set_name() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_set_name(s, "hola") == ERROR);
}

/**
 * @test Prueba la función para establecer el nombre de un espacio
 * @pre El espacio es un puntero no NULL, pero el nombre a establecer es NULL
 * @post La salida debe ser ERROR
 */
void test3_space_set_name() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_name(s, NULL) == ERROR);
}

/**
 * @test Prueba la función para establecer el enlace al norte de un espacio
 * @pre El espacio es un puntero no NULL
 * @post La salida debe ser OK
 */
void test1_space_set_north() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_north(s, 4) == OK);
}

/**
 * @test Prueba la función para establecer el enlace al norte de un espacio
 * @pre El espacio es un puntero NULL
 * @post La salida debe ser ERROR
 */
void test2_space_set_north() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_set_north(s, 4) == ERROR);
}

/**
 * @test Prueba la función para establecer el enlace al sur de un espacio
 * @pre El espacio es un puntero no NULL
 * @post La salida debe ser OK
 */
void test3_space_set_north() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_north(s, NO_ID) == ERROR);
}

/**
 * @test Prueba la función para establecer el enlace al sur de un espacio
 * @pre El espacio es un puntero no NULL
 * @post La salida debe ser OK
 */
void test1_space_set_south() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_south(s, 4) == OK);
}

/**
 * @test Prueba la función para establecer el enlace al sur de un espacio
 * @pre El espacio es un puntero NULL
 * @post La salida debe ser ERROR
 */
void test2_space_set_south() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_set_south(s, 4) == ERROR);
}

/**
 * @test Prueba la función para establecer el enlace al sur de un espacio
 * @pre El espacio es un puntero no NULL, pero el ID del enlace es NO_ID
 * @post La salida debe ser ERROR
 */
void test3_space_set_south() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_south(s, NO_ID) == ERROR);
}

/**
 * @test Prueba la función para establecer el enlace al este de un espacio
 * @pre El espacio es un puntero no NULL
 * @post La salida debe ser OK
 */
void test1_space_set_east() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_east(s, 4) == OK);
}

/**
 * @test Prueba la función para establecer el enlace al este de un espacio
 * @pre El espacio es un puntero NULL
 * @post La salida debe ser ERROR
 */
void test2_space_set_east() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_set_east(s, 4) == ERROR);
}

/**
 * @test Prueba la función para establecer el enlace al este de un espacio
 * @pre El espacio es un puntero no NULL, pero el ID del enlace es NO_ID
 * @post La salida debe ser ERROR
 */
void test3_space_set_east() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_east(s, NO_ID) == ERROR);
}

/**
 * @test Prueba la función para establecer el enlace al oeste de un espacio
 * @pre El espacio es un puntero no NULL
 * @post La salida debe ser OK
 */
void test1_space_set_west() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_west(s, 4) == OK);
}

/**
 * @test Prueba la función para establecer el enlace al oeste de un espacio
 * @pre El espacio es un puntero NULL
 * @post La salida debe ser ERROR
 */
void test2_space_set_west() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_set_west(s, 4) == ERROR);
}

/**
 * @test Prueba la función para establecer el enlace al oeste de un espacio
 * @pre El espacio es un puntero no NULL, pero el ID del enlace es NO_ID
 * @post La salida debe ser ERROR
 */
void test3_space_set_west() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_west(s, NO_ID) == ERROR);
}

/**
 * @test Prueba la función para recibir el nombre del espacio
 * @pre El espacio es un puntero no NULL
 * @post La salida debe ser 0
 */
void test1_space_get_name() {
    Space *s;
    s = space_create(1);
    space_set_name(s, "adios");
    PRINT_TEST_RESULT(strcmp(space_get_name(s), "adios") == 0);
}

/**
 * @test Prueba la función para recibir el nombre del espacio
 * @pre El espacio es un puntero NULL
 * @post La salida debe ser NULL
 */
void test2_space_get_name() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_name(s) == NULL);

}

/**
 * @test Prueba la función obtener el objeto
 * @pre El espacio es un puntero a la creacion del espacio
 * @post La salida debe ser un puntero a set
 */

void test1_space_get_object() {
    Space *s;
    s = space_create(1);
    PRINT_TEST_RESULT(space_get_object(s) == set*);

}

/**
 * @test Prueba la función para recibir objetos del espacio
 * @pre El espacio es un puntero NULL
 * @post La salida debe ser FALSE
 */
void test2_space_get_object() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_object(s) == FALSE);
}

/**
 * @test Prueba la función para recibir el link del espacio del norte
 * @pre El espacio es un puntero no NULL
 * @post La salida debe ser 4
 */
void test1_space_get_north() {
    Space *s;
    s = space_create(5);
    space_set_north(s, 4);
    PRINT_TEST_RESULT(space_get_north(s) == 4);
}

/**
 * @test Prueba la función para recibir el link del espacio del norte
 * @pre El espacio es un puntero NULL
 * @post La salida debe ser NO_ID
 */
void test2_space_get_north() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_north(s) == NO_ID);
}

/**
 * @test Prueba la función para recibir el link del espacio del sur
 * @pre El espacio es un puntero no NULL
 * @post La salida debe ser 2
 */
void test1_space_get_south() {
    Space *s;
    s = space_create(5);
    space_set_south(s, 2);
    PRINT_TEST_RESULT(space_get_south(s) == 2);
}

/**
 * @test Prueba la función para recibir el link del espacio del sur
 * @pre El espacio es un puntero NULL
 * @post La salida debe ser NO_ID
 */
void test2_space_get_south() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_south(s) == NO_ID);
}

/**
 * @test Prueba la función para recibir el link del espacio del este
 * @pre El espacio es un puntero no NULL
 * @post La salida debe ser 1
 */
void test1_space_get_east() {
    Space *s;
    s = space_create(5);
    space_set_east(s, 1);
    PRINT_TEST_RESULT(space_get_east(s) == 1);
}

/**
 * @test Prueba la función para recibir el link del espacio del este
 * @pre El espacio es un puntero NULL
 * @post La salida debe ser NO_ID
 */
void test2_space_get_east() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_east(s) == NO_ID);
}

/**
 * @test Prueba la función para recibir el link del espacio del oeste
 * @pre El espacio es un puntero no NULL
 * @post La salida debe ser 6
 */
void test1_space_get_west() {
    Space *s;
    s = space_create(5);
    space_set_west(s, 6);
    PRINT_TEST_RESULT(space_get_west(s) == 6);
}

/**
 * @test Prueba la función para recibir el link del espacio del oeste
 * @pre El espacio es un puntero NULL
 * @post La salida debe ser NO_ID
 */
void test2_space_get_west() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_west(s) == NO_ID);
}

/**
 * @test Prueba la función para recibir el id del espacio
 * @pre El espacio es un puntero no NULL con ID = 25
 * @post La salida debe ser 25
 */
void test1_space_get_id() {
    Space *s;
    s = space_create(25);
    PRINT_TEST_RESULT(space_get_id(s) == 25);
}

/**
 * @test Prueba la función para recibir el id del espacio
 * @pre El espacio es un puntero NULL
 * @post La salida debe ser ERROR
 */
void test2_space_get_id() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_id(s) == NO_ID);
}

/**
 * @test Prueba la función para escribir la descripcion del espacio
 * @pre El espacio es un puntero no NULL
 * @post La salida debe ser OK
 */
void test1_space_set_description(){
  Space *s;
  s = space_create(4);
  PRINT_TEST_RESULT(space_set_description(s, "description"); == OK);
}

/**
 * @test Prueba la función para escribir la descripcion del espacio
 * @pre El espacio es un puntero no NULL, pero la descripcion a introducir es NULL
 * @post La salida debe ser ERROR
 */
void test2_space_set_description(){
  Space *s;
  s = space_create(4);
  PRINT_TEST_RESULT(space_set_description(s, '\0') == ERROR);
}

/**
 * @test Prueba la función para escribir la descripcion del espacio
 * @pre El espacio es un puntero NULL
 * @post La salida debe ser ERROR
 */
void test3_space_set_description(){
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_description(s, "description") == ERROR);
}

/**
 * @test Prueba la función para recibir la descripcion del espacio
 * @pre El espacio es un puntero no NULL
 * @post La salida debe ser 0, ya que hay que comparar la cadena de caracteres que se le había puesto y ese resultado tiene que ser 0
 */
void test1_space_get_description(){
  Space *s;
  s = set_create(5);
  space_set_description(s, "description");
  PRINT_TEST_RESULT(strcmp(space_get_description(s), "description") == 0);
}

/**
 * @test Prueba la función para recibir la descripcion del espacio
 * @pre El espacio es un puntero NULL
 * @post La salida debe ser ERROR
 */
void test2_space_get_description(){
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_description(s) == NULL);
}

/**
* @test Prueba la función para añadir un objeto
* @pre El espacio es un puntero no NULL y la id introducida es 2
* @post La salida debe ser OK
*/
void test1_space_add_object(){
  Space *s;
  s = space_create(3);
  PRINT_TEST_RESULT(space_add_object(s, 2) == OK);
}

/**
 * @test Prueba la función para añadir un objeto
 * @pre El espacio es un puntero no NULL y la id introducida es NO_ID
 * @post La salida debe ser ERROR
 */
void test2_space_add_object(){
  Space *s;
  s = space_create(3);
  PRINT_TEST_RESULT(space_add_object(s, NO_ID) == ERROR);
}

/**
 * @test Prueba la función para añadir un objeto
 * @pre El espacio es un puntero NULL y la id introducida es 6
 * @post La salida debe ser ERROR
 */
void test3_space_add_object(){
  Space *s == NULL;
  PRINT_TEST_RESULT(space_add_object(s, 6) == ERROR);
}

/**
 * @test Prueba la función para eliminar un objeto
 * @pre El espacio es un puntero no NULL y la id introducida es 6
 * @post La salida debe ser OK
 */
void test1_space_delete_object(){
  Space *s;
  s = space_create(6);
  space_add_object(s, 6);
  PRINT_TEST_RESULT(space_delete_object(s, 6) == OK);
}

/**
 * @test Prueba la función para eliminar un objeto
 * @pre El espacio es un puntero NULL y la id introducida es 6
 * @post La salida debe ser ERROR
 */
void test2_space_delete_object(){
  Space *s = NULL;
  space_add_object(s, 6);
  PRINT_TEST_RESULT(space_delete_object(s, 6) == ERROR);
}

/**
 * @test Prueba la función para eliminar un objeto
 * @pre El espacio es un puntero NULL y la id introducida es NO_ID
 * @post La salida debe ser ERROR
 */
void test3_space_delete_object(){
  Space *s;
  s = space_create(6);
  space_add_object(s, 6);
  PRINT_TEST_RESULT(space_delete_object(s, NO_ID) == ERROR);
}

/**
 * @test Prueba la función para añadir un link al espacio
 * @pre El espacio es un puntero no NULL y la id introducida es 3
 * @post La salida debe ser OK
 */
void test1_space_add_link(){
  Space *s;
  s = space_create(4);
  PRINT_TEST_RESULT(space_add_link(s, 3) == OK);
}

/**
 * @test Prueba la función para añadir un link al espacio
 * @pre El espacio es un puntero no NULL y la id introducida es NO_ID
 * @post La salida debe ser ERROR
 */
void test2_space_add_link(){
  Space *s;
  s = space_create(4);
  PRINT_TEST_RESULT(space_add_link(s, NO_ID) == ERROR);
}

/**
 * @test Prueba la función para añadir un link al espacio
 * @pre El espacio es un puntero NULL y la id introducida es 3
 * @post La salida debe ser ERROR
 */
void test3_space_add_link(){
  Space *s = NULL;
  PRINT_TEST_RESULT(space_add_link(s, 3) == ERROR);
}

/**
 * @test Prueba la función para generrar la descripcion grafica del espacio
 * @pre El espacio es un puntero no NULL, la cadena de caracteres es "illu" y la id introducida es 2
 * @post La salida debe ser OK
 */
void test1_space_set_gdesc(){
  Space *s;
  s = space_create(4);
  PRINT_TEST_RESULT(space_set_gdesc(s, "illu", 2) == OK);
}

/**
 * @test Prueba la función para generrar la descripcion grafica del espacio
 * @pre El espacio es un puntero no NULL, la cadena de caracteres es "illu" y la id introducida es -1
 * @post La salida debe ser ERROR
 */
void test2_space_set_gdesc(){
  Space *s;
  s = space_create(4);
  PRINT_TEST_RESULT(space_set_gdesc(s, "illu", -1) == ERROR);
}

/**
 * @test Prueba la función para generrar la descripcion grafica del espacio
 * @pre El espacio es un puntero no NULL, la cadena de caracteres es NULL y la id introducida es 1
 * @post La salida debe ser ERROR
 */
void test3_space_set_gdesc(){
  Space *s;
  s = space_create(4);
  PRINT_TEST_RESULT(space_set_gdesc(s, NULL, 1) == ERROR);
}

/**
 * @test Prueba la función para generrar la descripcion grafica del espacio
 * @pre El espacio es un puntero NULL, la cadena de caracteres es "illu" y la id introducida es 1
 * @post La salida debe ser ERROR
 */
void test4_space_set_gdesc(){
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_gdesc(s, "illu", 1) == ERROR);
}

/**
 * @test Prueba la función para ilustrar los objetos
 * @pre El espacio es un puntero no NULL y la id introducida es 1
 * tiene que devolver "gdesc" que es lo que se le habia introducido y al compararla tiene que dar 0
 * @post La salida debe ser 0
 */
void test1_space_get_gdesc_illustration(){
  Space *s;
  s = space_create(4);
  space_set_gdesc(s->gdesc[1], "gdesc");
  PRINT_TEST_RESULT(strcmp(space_get_gdesc_illustration(s, 1), "gdesc") == 0);
}

/**
 * @test Prueba la función para ilustrar los objetos
 * @pre El espacio es un puntero NULL y la id introducida es 1
 * @post La salida debe ser NULL
 */
void test2_space_get_gdesc_illustration(){
  Space *s = NULL;
  space_set_gdesc(s->gdesc[1], "gdesc");
  PRINT_TEST_RESULT(strcmp(space_get_gdesc_illustration(s, 1), "gdesc") == NULL);
}

/**
 * @test Prueba la función para ilustrar los objetos
 * @pre El espacio es un puntero no NULL y la id introducida es menor que 0
 * @post La salida debe ser NULL
 */
void test3_space_get_gdesc_illustration(){
    Space *s;
    s = space_create(4);
    space_set_gdesc(s->gdesc[1], "gdesc");
    PRINT_TEST_RESULT(strcmp(space_get_gdesc_illustration(s, -1), "gdesc") == NULL);
  }

  /**
   * @test Prueba la función para comprobar los objetos del espacio
   * @pre El espacio es un puntero no NULL y la id introducida es 3
   * @post La salida debe ser OK
   */
void test1_space_check_object(){
  Space *s;
  s = space_create(5);
  space_add_object(s, 3);
  PRINT_TEST_RESULT(space_check_object(s, 3) == OK);
}

/**
 * @test Prueba la función para comprobar los objetos del espacio
 * @pre El espacio es un puntero NULL y la id introducida es 2
 * @post La salida debe ser ERROR
 */
void test2_space_check_object(){
  Space *s = NULL;
  PRINT_TEST_RESULT(space_check_object(s, 2) == ERROR);
}

/**
 * @test Prueba la función para comprobar los objetos del espacio
 * @pre El espacio es un puntero no NULL y la id introducida es NO_ID
 * @post La salida debe ser ERROR
 */
void test3_space_check_object(){
  Space *s;
  s = space_create(2);
  PRINT_TEST_RESULT(space_check_object(s, NO_ID) == ERROR);
}

/**
 * @test Prueba la función para comprobar los objetos del espacio
 * @pre El espacio es un puntero no NULL y la id introducida es 2 pero no coincide con la de ningun objeto en el espacio
 * @post La salida debe ser ERROR
 */
void test4_space_check_object(){
  Space *s;
  s = space_create(2);
  space_add_object(s, 3)
  PRINT_TEST_RESULT(space_check_object(s, 2) == ERROR);
}

/**
 * @test Prueba la función para comprobar que se destruye espacio
 * @pre El espacio es un puntero no NULL
 * @post La salida debe ser OK
 */
void test1_space_destroy(){
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_destroy(s) == OK);
}

/**
 * @test Prueba la función para comprobar que se destruye espacio
 * @pre El espacio es un puntero NULL
 * @post La salida debe ser ERROR
 */
void test2_space_destroy(){
  Space *s = NULL;
    PRINT_TEST_RESULT(space_destroy(s) == ERROR);
}
