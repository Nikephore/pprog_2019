/**
 * @brief Se encarga de probar el funcionamiento del dado
 *
 * @file die_test.c
 * @authors Álvaro Platón
 * @version 2.0
 * @date 04/04/2019
 * @copyright GNU Public License
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include "die.h"
 #include "die_test.h"

 #define MAX_TESTS 6

 /**
  * @brief Funcion principal de pruebas para el modulo Space.
  *
  * Dos modos de ejecucion:
  *   1.-Si se ejecuta sin parametros se ejecutan todas las pruebas
  *   2.-Si se ejecuta con un numero entre 1 y el numero de pruebas solo ejecuta
  *      la prueba indicada
  *
  */
 int main(int argc, char **argv){

 	int test = 0;
 	int all = 1;

 	if (argc < 2){
 		printf("Running all test for module Die:\n");
 	}
 	else{
 		test = atoi(argv[1]);
 		all = 0;
 		printf("Running test %d:\t", test);
 		if (test < 1 || test > MAX_TESTS){
 			printf("Error: unknown test %d\n", test);
 			exit(EXIT_SUCCESS);
 		}
 	}

 	if (all || test == 1)
 		test1_die_create();
 	if (all || test == 2)
 		test1_die_roll();
 	if (all || test == 3)
 		test2_die_roll();
 	if (all || test == 4)
 		test1_die_get_roll();
 	if (all || test == 5)
 		test2_die_get_roll();

 	PRINT_PASSED_PERCENTAGE;

 	return 0;
 }

 void test1_die_create(){
 	int result = die_create(5) != NULL;
 	PRINT_TEST_RESULT(result);
 }

 void test1_die_roll() {
 	Die *d = NULL;
 	PRINT_TEST_RESULT(die_roll(d) == ERROR);
 }

 void test2_die_roll() {
 	Die *d;
 	d = die_create(66);
 	PRINT_TEST_RESULT(die_roll(d) == OK);
 }

 void test1_die_get_last_roll(){
 	Die *d = NULL;
 	PRINT_TEST_RESULT(die_get_roll(d) == -1);
 }

 void test2_die_get_roll(){
 	Die *d;
 	d = die_create(66);
 	die_roll(d);
 	PRINT_TEST_RESULT(die_get_roll(d) >= 0 && die_get_roll(d) <= 9);
 }
