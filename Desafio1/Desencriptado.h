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
    return caracter ^ K;
}

unsigned char rotarDerecha(unsigned char caracter, int N) {
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
    char resultado = ((caracter >> N) | (caracter << (8 - N)));
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


void desencriptarTexto(unsigned int &K, unsigned int &N, unsigned char* &Encriptado, unsigned int &n, unsigned char* &resultado){

    resultado= new unsigned char [n];
    for(unsigned int i = 0; i<n; i++){
        unsigned char c =Encriptado[i];


        c = aplicarXOR(c, (unsigned char)K);
        c = rotarDerecha(c, N);

        resultado[i]=c;
    }
}

#endif // DESENCRIPTADO_H
