/**
 * @brief Prueba del modulo link
 *
 * @file space_test.c
 * @author Victor Perea
 * @version 1.0
 * @date 29/03/2019
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link.h"
#include "link_test.h"
#include "test.h"

#define MAX_TESTS 21

/**
 * @brief Funcion principal de pruebas para el modulo Link.
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
        printf("Running all test for module Link:\n");
    } else {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
	if (test < 1 && test > MAX_TESTS) {
	  printf("Error: unknown test %d\t", test);
	  exit(EXIT_SUCCESS);
        }
    }

    if (all || test == 1) test1_link_create();
    if (all || test == 2) test2_link_create();
    if (all || test == 3) test1_link_destroy();
    if (all || test == 4) test2_link_destroy();
    if (all || test == 5) test1_link_set_id();
    if (all || test == 6) test2_link_set_id();
    if (all || test == 7) test3_link_set_id();
    if (all || test == 8) test1_link_get_id();
    if (all || test == 9) test2_link_get_id();
    if (all || test == 10) test1_link_set_name();
    if (all || test == 11) test2_link_set_name();
    if (all || test == 12) test3_link_set_name();
    if (all || test == 13) test1_link_get_name();
    if (all || test == 14) test2_link_get_name();
    if (all || test == 15) test1_link_get_space1_id();
    if (all || test == 16) test2_link_get_space1_id();
    if (all || test == 17) test1_link_get_space2_id();
    if (all || test == 18) test2_link_get_space2_id();
    if (all || test == 19) test1_link_change_state();
    if (all || test == 20) test2_link_change_state();
    if (all || test == 21) test3_link_change_state();


    PRINT_PASSED_PERCENTAGE;

    return 1;
}

/**
 * @test Prueba la función de creación de un link
 * @pre Un id de un link, y dos id de espacios como parámetros
 * @post Un puntero no nulo al link creado
 */
void test1_link_create(){
  Link *l;
  l = link_create(2, 4, 5);
  PRINT_TEST_RESULT(link_get_id(l) == 2);
}

/**
 * @test Prueba la función de creación de un link
 * @pre Un id de un link igua a NO_ID, y dos id de espacios como parámetros
 * @post Un puntero nulo al link creado
 */
void test2_link_create(){
  Link *l;
  l = link_create(NO_ID, 4, 5);
  PRINT_TEST_RESULT(link_get_id(l) == NULL);
}

/**
 * @test Prueba la función de destruccion de un link
 * @pre un puntero no nulo como parametro
 * @post La salida debe ser OK
 */
void test1_link_destroy(){
  Link *l;
  l = link_create(3, 4, 5);
  PRINT_TEST_RESULT(link_destroy(l) == OK);
}

/**
 * @test Prueba la función de destruccion de un link
 * @pre un puntero nulo como parametro
 * @post La salida debe ser ERROR
 */
void test2_link_destroy(){
  Link *l = NULL;
  PRINT_TEST_RESULT(link_destroy(l) == ERROR);
}

/**
 * @test Prueba la función de cambiar el id de un link
 * @pre un puntero no nulo y un id como parametros
 * @post La salida debe ser OK
 */
void test1_link_set_id(){
  Link *l;
  l = link_create(1, 1, 2);
  PRINT_TEST_RESULT(link_set_id(l, 2) == OK);
}

/**
 * @test Prueba la función de cambiar el id de un link
 * @pre un puntero no nulo y un id igual a NO_ID como parametros
 * @post La salida debe ser ERROR
 */
void test2_link_set_id(){
  Link *l;
  l = link_create(1, 1, 2);
  PRINT_TEST_RESULT(link_set_id(l, NO_ID) == ERROR);
}

/**
 * @test Prueba la función de cambiar el id de un link
 * @pre un puntero nulo y un id como parametros
 * @post La salida debe ser ERROR
 */
void test3_link_set_id(){
  Link *l = NULL;
  PRINT_TEST_RESULT(link_set_id(l, 2) == ERROR);
}

/**
 * @test Prueba la función de obtener el id de un link
 * @pre un puntero no nulo como parametro
 * @post La salida debe ser 1
 */
void test1_link_get_id(){
  Link *l;
  l = link_create(1, 1, 2);
  PRINT_TEST_RESULT(link_get_id(l) == 1);
}

/**
 * @test Prueba la función de obtener el id de un link
 * @pre un puntero nulo como parametro
 * @post La salida debe ser NO_ID
 */
void test2_link_get_id(){
  Link *l = NULL;
  PRINT_TEST_RESULT(link_get_id(l) == NO_ID);
}

/**
 * @test Prueba la función de nombrar a un link
 * @pre un puntero no nulo y el nombre como parametros
 * @post La salida debe ser OK
 */
void test1_link_set_name(){
  Link *l;
  l = link_create(1, 1, 2);
  PRINT_TEST_RESULT(link_set_name(l, "nombre") == OK);
}

/**
 * @test Prueba la función de nombrar a un link
 * @pre un puntero no nulo y el nombre nulo como parametros
 * @post La salida debe ser ERROR
 */
void test2_link_set_name(){
  Link *l;
  l = link_create(1, 1, 2);
  PRINT_TEST_RESULT(link_set_name(l, '\0') == ERROR);
}

/**
 * @test Prueba la función de nombrar a un link
 * @pre un puntero nulo y el nombre como parametros
 * @post La salida debe ser ERROR
 */
void test3_link_set_name(){
  Link *l = NULL;
  PRINT_TEST_RESULT(link_set_name(l, "nombre") == ERROR);
}

/**
 * @test Prueba la función de recibir el nombre de un link
 * @pre un puntero no nulo como parametro
 * @post La salida debe ser 0 entre la comparacion del nombre recibido y el nombre que se le habia puesto
 */
void test1_link_get_name(){
  Link *l;
  l = link_create(1, 1, 2);
  link_set_name(l, "nombre");
  PRINT_TEST_RESULT(strcmp(link_get_name(l), "nombre") == 0);
}

/**
 * @test Prueba la función de recibir el nombre de un link
 * @pre un puntero no nulo como parametro
 * @post La salida debe ser NULL
 */
void test2_link_get_name(){
  Link *l = NULL;
  link_set_name(l, "nombre");
  PRINT_TEST_RESULT(strcmp(link_get_name(l), "nombre") == NULL);
}

/**
 * @test Prueba la función de recibir el id de un espacio que conecta el link
 * @pre un puntero no nulo como parametro
 * @post La salida debe ser el id del espacio1
 */
void test1_link_get_space1_id(){
  Link *l;
  l = link_create(1, 1, 2);
  PRINT_TEST_RESULT(link_get_space1_id(l) == 1);
}

/**
 * @test Prueba la función de recibir el id de un espacio que conecta el link
 * @pre un puntero nulo como parametro
 * @post La salida debe ser NO_ID
 */
void test2_link_get_space1_id(){
  Link *l = NULL;
  PRINT_TEST_RESULT(link_get_space1_id(l) == ERROR);
}

/**
 * @test Prueba la función de recibir el id de un espacio que conecta el link
 * @pre un puntero no nulo como parametro
 * @post La salida debe ser el id del espacio2
 */
void test1_link_get_space2_id(){
  Link *l;
  l = link_create(1, 1, 2);
  PRINT_TEST_RESULT(link_get_space2_id(l) == 2);
}

/**
 * @test Prueba la función de recibir el id de un espacio que conecta el link
 * @pre un puntero nulo como parametro
 * @post La salida debe ser NO_ID
 */
void test2_link_get_space2_id(){
  Link *l = NULL;
  PRINT_TEST_RESULT(link_get_space2_id(l) == ERROR);
}

/**
 * @test Prueba la función de cambiar el estado de un link
 * @pre un puntero no nulo como parametro. Inicialmente es estado es FALSE
 * @post La salida debe ser OK
 */
void test1_link_change_state(){
  Link *l;
  l = link_create( 3, 5, 6);
  PRINT_TEST_RESULT(link_change_state(l) == OK);
}

/**
 * @test Prueba la función de cambiar el estado de un link
 * @pre un puntero no nulo como parametro. El estado es TRUE
 * @post La salida debe ser OK
 */
void test2_link_change_state(){
  Link *l;
  l = link_create(3, 5, 6);
  l->state = TRUE;
  PRINT_TEST_RESULT(link_change_state(l) == OK);
}

/**
 * @test Prueba la función de cambiar el estado de un link
 * @pre un puntero nulo como parametro
 * @post La salida debe ser ERROR
 */
void test3_link_change_state(){
  Link *l = NULL;
  PRINT_TEST_RESULT(link_change_state(l) == ERROR);
}
