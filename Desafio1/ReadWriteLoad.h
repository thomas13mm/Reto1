#ifndef READWRITELOAD_H
#define READWRITELOAD_H

#include <iostream>
#include <fstream>
#include <Verificaciones.h>

using namespace std;

char* ReadArchivo(const char* name, unsigned int& n){
    /*Descripcion:
     *  Funcion encargada de la lectura de un archivo de texto plano
     *
     *Args:
     *  -(Const char* ) FileName: Apuntador al nombre del archivo.
     *  -(unsigned int) n: Cantidad de caracteres del archivo
     *
     *return: un apuntador a un arreglo de caracteres.
     *
     *Libreria: https://cplusplus.com/reference/fstream/fstream/
     */

    ifstream Archivo(name, ios::in);
    if (!Archivo.is_open()) {
        cerr << "Error: no se pudo abrir el archivo " << name << endl;
        n = 0;
        return nullptr;
    }
    Archivo.seekg(0, ios::end);
    n = Archivo.tellg();
    Archivo.seekg(0, ios::beg);
    char* PtrArr = new char[n];
    Archivo.read(PtrArr, n);
    Archivo.close();
    return PtrArr;
}




#endif // READWRITELOAD_H
