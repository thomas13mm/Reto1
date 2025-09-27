#ifndef METODOLRE_H
#define METODOLRE_H

#include <iostream>

using namespace std;

void DescompresionLRE(unsigned char* &ptrChar, unsigned int* &ptrInt, unsigned char* &ptrDescomprimido, unsigned int &n, unsigned int &k){
    /*Descripcion:
     *  Recibe 2 arreglos descoplados y descomprime los indices del arreglo de caracteres multiplicando cada posicion por
     *  su equivalencia en cada posicion de arreglo de enteros.
     *
     * Args:
     *  -(unsigned int) k: Referencia donde se va guardar el tamaño del texto descomprimido
     *  -(char*) ptrChar: Referencia a un apuntador de un arreglo de caracteres.
     *  -(unsigned int*) ptrInt: Referencia a un apuntador de un arreglo de enteros.
     *  -(char*) ptrDescomprimido: Referencia a un apuntador de un arreglo de caracteres donde se va a guardar
     *  el texto desencriptado.
     *  -(unsigned int) n: Referencia a la cantidad de pares presentes en int y char.
    */

    k=0;
    unsigned int cont = 0;

    for(unsigned int i = 0; i < n; i++){
        k += ptrInt[i];
    }

    ptrDescomprimido = new unsigned char[k];

    for(unsigned int i = 0; i < n; i++){
        for(unsigned int j = 0; j < ptrInt[i]; j++){
            ptrDescomprimido[cont] = ptrChar[i];
            cont++;
        }
    }
}

#endif // METODOLRE_H
