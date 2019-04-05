/**
 * @brief Pruebas para el modulo de link
 *
 * @file link_test.h
 * @author Victor Perea
 * @version 1.0
 * @date 29/03/2019
 * @copyright GNU Public License
 */

#ifndef LINK_TEST_H
#define LINK_TEST_H


/**
 * @test Prueba la función de creación de un link
 * @pre Un id de un link, y dos id de espacios como parámetros
 * @post Un puntero no nulo al link creado
 */
void test1_link_create();

/**
 * @test Prueba la función de creación de un link
 * @pre Un id de un link igua a NO_ID, y dos id de espacios como parámetros
 * @post Un puntero nulo al link creado
 */
void test2_link_create();

/**
 * @test Prueba la función de destruccion de un link
 * @pre un puntero no nulo como parametro
 * @post La salida debe ser OK
 */
void test1_link_destroy();


/**
 * @test Prueba la función de destruccion de un link
 * @pre un puntero nulo como parametro
 * @post La salida debe ser ERROR
 */
void test2_link_destroy();

/**
 * @test Prueba la función de cambiar el id de un link
 * @pre un puntero no nulo y un id como parametros
 * @post La salida debe ser OK
 */
void test1_link_set_id();


/**
 * @test Prueba la función de cambiar el id de un link
 * @pre un puntero no nulo y un id igual a NO_ID como parametros
 * @post La salida debe ser ERROR
 */
void test2_link_set_id();

/**
 * @test Prueba la función de cambiar el id de un link
 * @pre un puntero nulo y un id como parametros
 * @post La salida debe ser ERROR
 */
void test3_link_set_id();

/**
 * @test Prueba la función de obtener el id de un link
 * @pre un puntero no nulo como parametro
 * @post La salida debe ser 1
 */
void test1_link_get_id();


/**
 * @test Prueba la función de obtener el id de un link
 * @pre un puntero nulo como parametro
 * @post La salida debe ser NO_ID
 */
void test2_link_get_id();

/**
 * @test Prueba la función de nombrar a un link
 * @pre un puntero no nulo y el nombre como parametros
 * @post La salida debe ser OK
 */
void test1_link_set_name();

/**
 * @test Prueba la función de nombrar a un link
 * @pre un puntero no nulo y el nombre nulo como parametros
 * @post La salida debe ser ERROR
 */
void test2_link_set_name();

/**
 * @test Prueba la función de nombrar a un link
 * @pre un puntero nulo y el nombre como parametros
 * @post La salida debe ser ERROR
 */
void test3_link_set_name();

/**
 * @test Prueba la función de recibir el nombre de un link
 * @pre un puntero no nulo como parametro
 * @post La salida debe ser 0 entre la comparacion del nombre recibido y el nombre que se le habia puesto
 */
void test1_link_get_name();

/**
 * @test Prueba la función de recibir el nombre de un link
 * @pre un puntero no nulo como parametro
 * @post La salida debe ser NULL
 */
void test2_link_get_name();

/**
 * @test Prueba la función de recibir el id de un espacio que conecta el link
 * @pre un puntero no nulo como parametro
 * @post La salida debe ser el id del espacio1
 */
void test1_link_get_space1_id();

/**
 * @test Prueba la función de recibir el id de un espacio que conecta el link
 * @pre un puntero nulo como parametro
 * @post La salida debe ser NO_ID
 */
void test2_link_get_space1_id();

/**
 * @test Prueba la función de recibir el id de un espacio que conecta el link
 * @pre un puntero no nulo como parametro
 * @post La salida debe ser el id del espacio2
 */
void test1_link_get_space2_id();

/**
 * @test Prueba la función de recibir el id de un espacio que conecta el link
 * @pre un puntero nulo como parametro
 * @post La salida debe ser NO_ID
 */
void test2_link_get_space2_id();

/**
 * @test Prueba la función de cambiar el estado de un link
 * @pre un puntero no nulo como parametro. Inicialmente es estado es FALSE
 * @post La salida debe ser OK
 */
void test1_link_change_state();

/**
 * @test Prueba la función de cambiar el estado de un link
 * @pre un puntero no nulo como parametro. El estado es TRUE
 * @post La salida debe ser OK
 */
void test2_link_change_state();

/**
 * @test Prueba la función de cambiar el estado de un link
 * @pre un puntero nulo como parametro
 * @post La salida debe ser ERROR
 */
void test3_link_change_state();
#endif
