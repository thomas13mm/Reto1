#ifndef DESENCRIPTADO_H
#define DESENCRIPTADO_H

#include <iostream>
using namespace std;

unsigned char aplicarXOR(unsigned char caracter, unsigned char K) {
    /*Descripcion:
    *  Funcion encargada de aplicar la operacion XOR entre un caracter y la clave K.
    *
    *Args:
    *  -(unsigned char) caracter: Carácter de entrada a procesar.
    *  -(unsigned char) K: Clave de un byte para la operación XOR.
    *
    *return: (unsigned char) Resultado de aplicar XOR entre caracter y K.
    *
    */
    unsigned char resultado = caracter ^ K;
    return resultado;
}

unsigned char rotarDerecha(unsigned char caracter, unsigned int N) {
    /*Descripcion:
    *  Funcion encargada de rotar a la derecha los bits de un caracter.
    *
    *Args:
    * -(unsigned char) caracter: Caracter (byte) a rotar.
    *  -(unsigned int) N: Numero de posiciones a rotar a la derecha.
    *
    *return: un caracter resultante de la rotacion.
    *
    */
    unsigned char resultado = ((caracter >> N) | (caracter << (8 - N)));
    return resultado;
}

bool esCaracterInvalido(unsigned char caracter) {
    /*Descripcion:
    *  Funcion encargada de verificar si un caracter esta fuera del rango permitido
    *  (A-Z, a-z, 0-9).
    *
    *Args:
    *  -(unsigned char) caracter: Caracter a evaluar despues de las operaciones
    *                             de desencriptado.
    *
    *return: (bool) true si el caracter esta fuera del rango permitido,
    *               false si pertenece al rango valido.
    *
    */
    if (caracter >= '0' && caracter <= '9')
        return false;
    if (caracter >= 'a' && caracter <= 'z')
        return false;
    if (caracter >= 'A' && caracter <= 'Z')
        return false;

    return true;
}

void desencriptarTexto(char* textoEncriptado, unsigned int n, unsigned char& K, unsigned int& N, char*& arrCaracteres, char*& arrNumeros) {
    /*Descripcion:
    *  Funcion encargada de desencriptar un texto encriptado, probando diferentes combinaciones
    *  de K y N hasta obtener un resultado valido (caracteres alfanumericos).
    *
    *Args:
    *  -(char*) textoEncriptado: Apuntador al arreglo con el texto encriptado.
    *  -(unsigned int) n: Longitud del texto encriptado.
    *  -(unsigned char&) K: Referencia a la clave XOR correcta (resultado).
    *  -(unsigned int&) N: Referencia al numero de rotaciones correcto (resultado).
    *  -(char*&) arrCaracteres: Apuntador a un arreglo dinamico que contendra
    *                           los caracteres desencriptados validos.
    *  -(char*&) arrNumeros: Apuntador a un arreglo dinamico que contendra 
    *                        unicamente los numeros desencriptados.
    *
    *return: (void) Los resultados se devuelven a traves de las referencias
    *                y apuntadores dinamicos.
    */

    char* temp = new char[n];

    for (unsigned int kPrueba = 0; kPrueba < 256; kPrueba++) {
        for (unsigned int nPrueba = 0; nPrueba < 8; nPrueba++) {

            bool valido = true;
            for (unsigned int i = 0; i < n; i++) {
                unsigned char c = textoEncriptado[i];

                c = aplicarXOR(c, (unsigned char)kPrueba);
                c = rotarDerecha(c, nPruebas);

                if (esCaracterInvalido(c)) {
                    valido = false;
                    break;
                }



            }


        }
    }
}

#endif // DESENCRIPTADO_H
