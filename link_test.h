/**
 * @brief Se encarga de probar el funcionamiento de los enlaces
 *
 * @file link_test.h
 * @authors Álvaro Platón
 * @version 2.0
 * @date 04/04/2019
 * @copyright GNU Public License
 */

#ifndef LINK_TEST_H
#define LINK_TEST_H
/**
 * @test Prueba la función de creación de un enlace
 * @pre Un identificador como parámetro
 * @post Un puntero no nulo al espacio creado
 */
void test1_link_create();
/**
 * @test Prueba la función de creación de un enlace
 * @pre Un identificador como parámetro
 * @post El identificador del espacio es el introducido
 */
void test2_link_create();
/**
 * @test Prueba la función para establecer la id de un enlace
 * @pre El enlace al que establecer la id es un puntero a NULL
 * @post La salida debe ser ERROR
 */
void test1_link_set_id();
/**
 * @test Prueba la función para establecer la id de un enlace
 * @pre El enlace es un puntero no NULL, pero la id a establecer es NULL
 * @post La salida debe ser ERROR
 */
void test2_link_set_id();
/**
 * @test Prueba la función para establecer los espacios de un enlace
 * @pre El enlace al que establecer los espacios es un puntero a NULL
 * @post La salida debe ser ERROR
 */
void test1_link_set_spaces();
/**
 * @test Prueba la función para establecer los espacios de un enlace
 * @pre El enlace es un puntero no NULL, pero los espacios a establecer es NULL
 * @post La salida debe ser ERROR
 */
void test2_link_set_spaces();
/**
 * @test Prueba la función para obtener la id de un enlace
 * @pre El enlace es un puntero no NULL, pero la id a obtener es NULL
 * @post La salida debe ser ERROR
 */
void test1_link_get_id();
/**
 * @test Prueba la función para obtener la id del primer espacio de un enlace
 * @pre El enlace es un puntero a la creacion del link, pero la id a obtener no es NULL
 * @post La salida debe ser ERROR
 */
void test1_link_get_space1_id();
/**
 * @test Prueba la función para obtener la id del primer espacio de un enlace
 * @pre El enlace es un puntero a la creacion del link, pero la id a obtener no es NULL
 * @post La salida debe ser ERROR
 */
void test1_link_get_space2_id();

#endif
