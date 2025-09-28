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

unsigned char rotarDerecha(unsigned char c, unsigned int N) {
    /*Descripcion:
     *  Rota a la derecha los bits de un byte.
     *
     *Args:
     *  -(unsigned char) c: Byte a rotar.
     *  -(unsigned int) N: Número de posiciones a rotar.
     *
     *Return: (unsigned char) resultado después de la rotación.
     */
    return (unsigned char)((c >> N) | (c << (8 - N)));
}

void desencriptarTexto(unsigned int &K, unsigned int &N,unsigned char* &Encriptado,unsigned int &n,unsigned char* &resultado) {
    /*Descripcion:
     *  Desencripta un arreglo de bytes aplicando primero XOR con K
     *  y luego rotación a la derecha (inverso de encriptar).
     *
     *Args:
     *  -(unsigned int &) K: Clave XOR de un byte.
     *  -(unsigned int &) N: Número de posiciones para rotar a la derecha.
     *  -(unsigned char* &) Encriptado: Bytes encriptados.
     *  -(unsigned int &) n: Longitud del arreglo.
     *  -(unsigned char* &) resultado: Apuntador donde se guarda el desencriptado.
     */

    resultado = new unsigned char[n];
    for (unsigned int i = 0; i < n; i++) {
        unsigned char c = Encriptado[i];

        // primero XOR
        c=aplicarXOR(c,K);

        // luego rotar derecha
        c = rotarDerecha(c, N);

        resultado[i] = c;
    }
}


#endif // DESENCRIPTADO_H
