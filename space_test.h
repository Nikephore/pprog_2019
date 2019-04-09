/**
 * @brief Prueba del modulo space
 *
 * @file space_test.h
 * @author Victor Perea
 * @version 1.0
 * @date 01/04/2019
 * @copyright GNU Public License
 */

#ifndef SPACE_TEST_H
#define SPACE_TEST_H

/**
 * @test Prueba la función de creación de un espacio
 * @pre Un identificador como parámetro
 * @post Un puntero no nulo al espacio creado
 */
void test1_space_create();

/**
 * @test Prueba la función de creación de un espacio
 * @pre Un identificador como parámetro
 * @post El identificador del espacio es el introducido
 */
void test2_space_create();

/**
 * @test Prueba la función para establecer el nombre de un espacio
 * @pre Nombre que establecer al espacio
 * @post La salida debe ser OK
 */
void test1_space_set_name();

/**
 * @test Prueba la función para establecer el nombre de un espacio
 * @pre El espacio al que establecer el nombre es un puntero a NULL
 * @post La salida debe ser ERROR
 */
void test2_space_set_name();

/**
 * @test Prueba la función para establecer el nombre de un espacio
 * @pre El espacio es un puntero no NULL, pero el nombre a establecer es NULL
 * @post La salida debe ser ERROR
 */
void test3_space_set_name();

/**
 * @test Prueba la función para establecer el enlace al norte de un espacio
 * @pre El espacio es un puntero no NULL
 * @post La salida debe ser OK
 */
void test1_space_set_north();

/**
 * @test Prueba la función para establecer el enlace al norte de un espacio
 * @pre El espacio es un puntero NULL
 * @post La salida debe ser ERROR
 */
void test2_space_set_north();

/**
 * @test Prueba la función para establecer el enlace al norte de un espacio
 * @pre El espacio es un puntero no NULL, pero el ID del enlace es NO_ID
 * @post La salida debe ser ERROR
 */
void test3_space_set_north();

/**
 * @test Prueba la función para establecer el enlace al sur de un espacio
 * @pre El espacio es un puntero no NULL
 * @post La salida debe ser OK
 */
void test1_space_set_south();

/**
 * @test Prueba la función para establecer el enlace al sur de un espacio
 * @pre El espacio es un puntero NULL
 * @post La salida debe ser ERROR
 */
void test2_space_set_south();

/**
 * @test Prueba la función para establecer el enlace al sur de un espacio
 * @pre El espacio es un puntero no NULL, pero el ID del enlace es NO_ID
 * @post La salida debe ser ERROR
 */
void test3_space_set_south();

/**
 * @test Prueba la función para establecer el enlace al este de un espacio
 * @pre El espacio es un puntero no NULL
 * @post La salida debe ser OK
 */
void test1_space_set_east();

/**
 * @test Prueba la función para establecer el enlace al este de un espacio
 * @pre El espacio es un puntero NULL
 * @post La salida debe ser ERROR
 */
void test2_space_set_east();

/**
 * @test Prueba la función para establecer el enlace al este de un espacio
 * @pre El espacio es un puntero no NULL, pero el ID del enlace es NO_ID
 * @post La salida debe ser ERROR
 */
void test3_space_set_east();

/**
 * @test Prueba la función para establecer el enlace al oeste de un espacio
 * @pre El espacio es un puntero no NULL
 * @post La salida debe ser OK
 */
void test1_space_set_west();

/**
 * @test Prueba la función para establecer el enlace al oeste de un espacio
 * @pre El espacio es un puntero NULL
 * @post La salida debe ser ERROR
 */
void test2_space_set_west();

/**
 * @test Prueba la función para establecer el enlace al oeste de un espacio
 * @pre El espacio es un puntero no NULL, pero el ID del enlace es NO_ID
 * @post La salida debe ser ERROR
 */
void test3_space_set_west();

/**
 * @test Prueba la función para recibir el id del espacio
 * @pre El espacio es un puntero no NULL con ID = 25
 * @post La salida debe ser 25
 */
void test1_space_get_id();

/**
 * @test Prueba la función para recibir el id del espacio
 * @pre El espacio es un puntero NULL
 * @post La salida debe ser ERROR
 */
void test2_space_get_id();

/**
 * @test Prueba la función para recibir el nombre del espacio
 * @pre El espacio es un puntero no NULL
 * @post La salida debe ser 0
 */
void test1_space_get_name();

/**
 * @test Prueba la función para recibir el nombre del espacio
 * @pre El espacio es un puntero NULL
 * @post La salida debe ser NULL
 */
void test2_space_get_name();

/**
 * @test Prueba la función para recibir el link del espacio del norte
 * @pre El espacio es un puntero no NULL
 * @post La salida debe ser 4
 */
void test1_space_get_north();

/**
 * @test Prueba la función para recibir el link del espacio del norte
 * @pre El espacio es un puntero NULL
 * @post La salida debe ser NO_ID
 */
void test2_space_get_north();

/**
 * @test Prueba la función para recibir el link del espacio del sur
 * @pre El espacio es un puntero no NULL
 * @post La salida debe ser 2
 */
void test1_space_get_south();

/**
 * @test Prueba la función para recibir el link del espacio del sur
 * @pre El espacio es un puntero NULL
 * @post La salida debe ser NO_ID
 */
void test2_space_get_south();

/**
 * @test Prueba la función para recibir el link del espacio del este
 * @pre El espacio es un puntero no NULL
 * @post La salida debe ser 1
 */
void test1_space_get_east();

/**
 * @test Prueba la función para recibir el link del espacio del este
 * @pre El espacio es un puntero NULL
 * @post La salida debe ser NO_ID
 */
void test2_space_get_east();

/**
 * @test Prueba la función para recibir el link del espacio del oeste
 * @pre El espacio es un puntero no NULL
 * @post La salida debe ser 6
 */
void test1_space_get_west();

/**
 * @test Prueba la función para recibir el link del espacio del oeste
 * @pre El espacio es un puntero NULL
 * @post La salida debe ser NO_ID
 */
void test2_space_get_west();

/**
 * @test Prueba la función obtener el objeto
 * @pre El espacio es un puntero a la creacion del espacio
 * @post La salida debe ser un puntero a set
 */
void test1_space_get_object();

/**
 * @test Prueba la función para recibir objetos del espacio
 * @pre El espacio es un puntero NULL
 * @post La salida debe ser FALSE
 */
void test2_space_get_object();

/**
 * @test Prueba la función para escribir la descripcion del espacio
 * @pre El espacio es un puntero no NULL
 * @post La salida debe ser OK
 */
void test1_space_set_description();

/**
 * @test Prueba la función para escribir la descripcion del espacio
 * @pre El espacio es un puntero no NULL, pero la descripcion a introducir es NULL
 * @post La salida debe ser ERROR
 */
void test2_space_set_description();

/**
 * @test Prueba la función para escribir la descripcion del espacio
 * @pre El espacio es un puntero NULL
 * @post La salida debe ser ERROR
 */
void test3_space_set_description();

/**
 * @test Prueba la función para recibir la descripcion del espacio
 * @pre El espacio es un puntero no NULL
 * @post La salida debe ser 0, ya que hay que comparar la cadena de caracteres que se le había puesto y ese resultado tiene que ser 0
 */
void test1_space_get_description();

/**
 * @test Prueba la función para recibir la descripcion del espacio
 * @pre El espacio es un puntero NULL
 * @post La salida debe ser ERROR
 */
void test2_space_get_description();

/**
 * @test Prueba la función para añadir un objeto
 * @pre El espacio es un puntero no NULL y la id introducida es 2
 * @post La salida debe ser OK
 */
void test1_space_add_object();

/**
 * @test Prueba la función para añadir un objeto
 * @pre El espacio es un puntero no NULL y la id introducida es NO_ID
 * @post La salida debe ser ERROR
 */
void test2_space_add_object();

/**
 * @test Prueba la función para añadir un objeto
 * @pre El espacio es un puntero NULL y la id introducida es 6
 * @post La salida debe ser ERROR
 */
void test3_space_add_object();

/**
 * @test Prueba la función para eliminar un objeto
 * @pre El espacio es un puntero no NULL y la id introducida es 6
 * @post La salida debe ser OK
 */
void test1_space_delete_object();

/**
 * @test Prueba la función para eliminar un objeto
 * @pre El espacio es un puntero NULL y la id introducida es 6
 * @post La salida debe ser ERROR
 */
void test2_space_delete_object();

/**
 * @test Prueba la función para eliminar un objeto
 * @pre El espacio es un puntero NULL y la id introducida es NO_ID
 * @post La salida debe ser ERROR
 */
void test3_space_delete_object();

/**
 * @test Prueba la función para añadir un link al espacio
 * @pre El espacio es un puntero no NULL y la id introducida es 3
 * @post La salida debe ser OK
 */
void test1_space_add_link();

/**
 * @test Prueba la función para añadir un link al espacio
 * @pre El espacio es un puntero no NULL y la id introducida es NO_ID
 * @post La salida debe ser ERROR
 */
void test2_space_add_link();

/**
 * @test Prueba la función para añadir un link al espacio
 * @pre El espacio es un puntero NULL y la id introducida es 3
 * @post La salida debe ser ERROR
 */
void test3_space_add_link();

/**
 * @test Prueba la función para generrar la descripcion grafica del espacio
 * @pre El espacio es un puntero no NULL, la cadena de caracteres es "illu" y la id introducida es 2
 * @post La salida debe ser OK
 */
void test1_space_set_gdesc();

/**
 * @test Prueba la función para generrar la descripcion grafica del espacio
 * @pre El espacio es un puntero no NULL, la cadena de caracteres es "illu" y la id introducida es -1
 * @post La salida debe ser ERROR
 */
void test2_space_set_gdesc();

/**
 * @test Prueba la función para generrar la descripcion grafica del espacio
 * @pre El espacio es un puntero no NULL, la cadena de caracteres es NULL y la id introducida es 1
 * @post La salida debe ser ERROR
 */
void test3_space_set_gdesc();

/**
 * @test Prueba la función para generrar la descripcion grafica del espacio
 * @pre El espacio es un puntero NULL, la cadena de caracteres es "illu" y la id introducida es 1
 * @post La salida debe ser ERROR
 */
void test4_space_set_gdesc();

/**
 * @test Prueba la función para ilustrar los objetos
 * @pre El espacio es un puntero no NULL y la id introducida es 1
 * tiene que devolver "gdesc" que es lo que se le habia introducido y al compararla tiene que dar 0
 * @post La salida debe ser 0
 */
void test1_space_get_gdesc_illustration();

/**
 * @test Prueba la función para ilustrar los objetos
 * @pre El espacio es un puntero NULL y la id introducida es 1
 * @post La salida debe ser NULL
 */
void test2_space_get_gdesc_illustration();

/**
 * @test Prueba la función para ilustrar los objetos
 * @pre El espacio es un puntero no NULL y la id introducida es menor que 0
 * @post La salida debe ser NULL
 */
void test3_space_get_gdesc_illustration();

/**
 * @test Prueba la función para comprobar los objetos del espacio
 * @pre El espacio es un puntero no NULL y la id introducida es 3
 * @post La salida debe ser OK
 */
void test1_space_check_object();

/**
 * @test Prueba la función para comprobar los objetos del espacio
 * @pre El espacio es un puntero NULL y la id introducida es 2
 * @post La salida debe ser ERROR
 */
void test2_space_check_object();

/**
 * @test Prueba la función para comprobar los objetos del espacio
 * @pre El espacio es un puntero no NULL y la id introducida es NO_ID
 * @post La salida debe ser ERROR
 */
void test3_space_check_object();

/**
 * @test Prueba la función para comprobar los objetos del espacio
 * @pre El espacio es un puntero no NULL y la id introducida es 2 pero no coincide con la de ningun objeto en el espacio
 * @post La salida debe ser ERROR
 */
void test4_space_check_object();

/**
 * @test Prueba la función para comprobar que se destruye espacio
 * @pre El espacio es un puntero no NULL
 * @post La salida debe ser OK
 */
void test1_space_destroy();

/**
 * @test Prueba la función para comprobar que se destruye espacio
 * @pre El espacio es un puntero NULL
 * @post La salida debe ser ERROR
 */
void test2_space_destroy();
#endif
