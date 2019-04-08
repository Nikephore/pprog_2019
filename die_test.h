/**
 * @brief Se encarga de probar el funcionamiento del dado
 *
 * @file die_test.h
 * @authors Álvaro Platón
 * @version 2.0
 * @date 04/04/2019
 * @copyright GNU Public License
 */

#ifndef DIE_TEST_H
#define DIE_TEST_H

/**
 * @test Prueba la función de creación de un dado
 * @pre Un identificador como parámetro
 * @post Un puntero no nulo al dado creado
 */
void test1_die_create();
/**
 * @test Prueba la función para lanzar un dado
 * @pre El dado que va a lanzar cuya id es un puntero a NULL
 * @post La salida debe ser ERROR
 */
void test1_die_roll();
/**
 * @test Prueba la función lanzar un dado
 * @pre Un identificador como parámetro
 * @post El identificador del dado es el introducido
 */
void test2_die_roll();
/**
 * @test Prueba la función para obtener el ultimo numero obtenido del dado
 * @pre El dado que va a lanzar cuya id es un puntero a NULL
 * @post La salida debe ser ERROR
 */
void test1_die_get_last_roll();
/**
 * @test Prueba la función  para obtener el ultimo numero obtenido del dado
 * @pre Un identificador como parámetro
 * @post El identificador del dado es el introducido
 */
void test2_die_get_last_roll();

#endif
