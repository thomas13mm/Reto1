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
    /*
    * Descripcion:
    *  Funcion encargada de desencriptar un texto encriptado aplicando, para cada caracter,
    *  una operacion XOR con una clave K y una rotacion de N bits a la derecha.
    *  Se prueban todas las combinaciones posibles de (K, N) hasta encontrar una
    *  que produzca un texto valido (solo caracteres alfanumericos: A-Z, a-z, 0-9).
    *
    * Args:
    *  -(char*) textoEncriptado: Apuntador al arreglo con el texto encriptado.
    *  -(unsigned int) n: Longitud del texto encriptado (numero de caracteres).
    *  -(unsigned char&) K: Referencia donde se almacenara la clave XOR correcta.
    *  -(unsigned int&) N: Referencia donde se almacenara el numero de rotaciones correcto.
    *  -(char*&) arrCaracteres: Apuntador de salida. Contendra un arreglo dinamico
    *                           con todos los caracteres alfabeticos desencriptados.
    *  -(char*&) arrNumeros: Apuntador de salida. Contendra un arreglo dinamico
    *                        con todos los digitos numericos desencriptados.
    *
    * return: (void) 
    *  - Si se encuentra una combinacion valida de (K, N), se devuelven:
    *       K y N correctos (por referencia).
    *       arrCaracteres y arrNumeros con memoria dinamica reservada y llenada.
    *  - Si no se encuentra una combinacion valida:
    *       arrCaracteres y arrNumeros quedan en nullptr.
    * 
    * Nota: 
    *  El llamador es responsable de liberar la memoria dinamica reservada
    *  para arrCaracteres y arrNumeros cuando ya no se utilicen.
    */

    char* temp = new char[n];

    for (unsigned int kPrueba = 0; kPrueba < 256; kPrueba++) {
        for (unsigned int nPrueba = 0; nPrueba < 8; nPrueba++) {

            bool valido = true;
            unsigned int contadorNum = 0;
            unsigned int contadorChar = 0;
            
            for (unsigned int i = 0; i < n; i++) {
                unsigned char c = textoEncriptado[i];

                c = aplicarXOR(c, (unsigned char)kPrueba);
                c = rotarDerecha(c, nPruebas);

                if (esCaracterInvalido(c)) {
                    valido = false;
                    break;
                }

                temp[i] = c;

                if (c >= '0' && c <= '9') {
                    contadorNum++;
                }
                else {
                    contadorChar++;
                }

            }

            // si la combinacion (K, N) fue correcta
            if (valido) {

                K = (unsigned char)kPrueba; //se guardan los valores encontrados
                N = nPrueba;

                arrCaracteres = new char[contadorChar + 1];
                arrNumeros = new char[contadorNum + 1];

                unsigned int idxN = 0, idxC = 0;

                for (unsigned int i = 0; i < n; i++) {
                    char c = temp[i];
                    if (c >= '0' && c <= '9') {
                        arrNumeros[idxN] = c;
                    } 
                    else {
                        arrCaracteres[idxC] = c;
                    }
                }

                delete[] temp;
                return;

            }
        }
    }

    /*Si se recorrieron todas las combinaciones y ninguna fue valida
    * se libera temp y se dejan los punteros de salida en nullptr
    * para indicar "no encontrado"
    */

    delete[] temp;
    arrCaracteres = nullptr;
    arrNumeros = nullptr;
}

#endif // DESENCRIPTADO_H
