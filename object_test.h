/**
 * @brief Se encarga de probar el funcionamiento de los objetos
 *
 * @file object_test.h
 * @authors Álvaro Platón
 * @version 2.0
 * @date 04/04/2019
 * @copyright GNU Public License
 */

#ifndef OBJECT_TEST_H
#define OBJECT_TEST_H
/**
 * @test Prueba la función de creación de un objeto
 * @pre Un identificador como parámetro
 * @post Un puntero no nulo al objeto creado
 */
void test1_object_create();
/**
 * @test Prueba la función de creación de un objeto
 * @pre Un identificador como parámetro
 * @post El identificador del objeto es el introducido
 */
void test2_object_create();
/**
 * @test Prueba la función para establecer el nombre del objeto
 * @pre El objeto al que establecer el nombre es un puntero a NULL
 * @post La salida debe ser ERROR
 */
void test1_object_set_name();
/**
 * @test Prueba la función para establecer el nombre del objeto
 * @pre El objeto es un puntero no NULL, pero el nomnre a establecer es NULL
 * @post La salida debe ser ERROR
 */
void test2_object_set_name();
/**
 * @test Prueba la función para establecer la id del objeto
 * @pre El objeto al que establecer la id es un puntero a NULL
 * @post La salida debe ser ERROR
 */
void test1_object_set_id();
/**
 * @test Prueba la función para establecer la id del objeto
 * @pre El objeto es un puntero no NULL, pero la id a establecer es NULL
 * @post La salida debe ser ERROR
 */
void test2_object_set_id();
/**
 * @test Prueba la función para establecer la descripcion del objeto
 * @pre El objeto al que establecer la descripcion es un puntero a NULL
 * @post La salida debe ser ERROR
 */
void test1_object_set_description();
/**
 * @test Prueba la función para establecer la descripcion del objeto
 * @pre El objeto es un puntero no NULL, pero la descripcion a establecer es NULL
 * @post La salida debe ser ERROR
 */
void test2_object_set_description();
/**
 * @test Prueba la función para obtener el nombre del objeto
 * @pre El objeto es un puntero a la creacion del objeto, pero la id a obtener no es NULL
 * @post La salida debe ser ERROR
 */
void test1_object_get_name();
/**
 * @test Prueba la función para obtener la descripcion del objeto
 * @pre La descripcion es un puntero a la creacion del objeto, pero la nombre a obtener no es NULL
 * @post La salida debe ser ERROR
 */
void test1_object_get_description();
/**
 * @test Prueba la función para obtener la id de un objeto
 * @pre El objeto es un puntero no NULL, pero la id a obtener es NULL
 * @post La salida debe ser ERROR
 */
void test1_object_get_id();

#endif
