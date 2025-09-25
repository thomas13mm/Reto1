#ifndef METODOLRE_H
#define METODOLRE_H

#include <iostream>
#include <Verificaciones.h>

using namespace std;

void DescompresionLRE(unsigned char* &PtrComprimido,unsigned char* &ptrChar, int* &ptrInt, char* &ptrDescomprimido, unsigned int &n){
    /*Descripcion:
     *  Recibe 2 arreglos descoplados y descomprime los indices del arreglo de caracteres multiplicando cada posicion por
     *  su equivalencia en cada posicion de arreglo de enteros.
     *
     * Args:
     *  -(unsigned char* )PtrComprimido: Referencia al apuntador que señala al texto comprimido
     *  -(unsigned char*) ptrChar: Referencia a un apuntador de un arreglo de caracteres.
     *  -(int*) ptrInt: Referencia a un apuntador de un arreglo de enteros.
     *  -(unsigned char*) ptrDescomprimido: Referencia a un apuntador de un arreglo de caracteres donde se va a guardar
     *  el texto desencriptado.
     *  -(unsigned int) n: Referencia a la cantidad de elementos presentes en el arreglo.
    */

    for(unsigned int i = 0; i<n ; i+2){
        ptrInt=;
    }

    unsigned int k = 0;
    unsigned int cont = 0;

    for(unsigned int i = 0; i < n; i++){
        k += ptrInt[i];
    }

    ptrDescomprimido = new char[k];

    for(unsigned int i = 0; i < n; i++){
        for(unsigned int j = 0; j < ptrInt[i]; j++){
            ptrDescomprimido[cont] = ptrChar[i];
            cout << ptrDescomprimido[cont];
            cont++;
        }
    }



}

#endif // METODOLRE_H
