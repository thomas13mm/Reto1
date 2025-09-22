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

bool SaveArchivo(char* &PtrArr, unsigned int &n, const char* name = "../../datasetDesarrollo/Texto_Desencriptado.txt"){
    /*Descripcion:
     *  Guarda todos los elementos de un arreglo en un archivo de texto plano .txt
     *
     *Args:
     *  -(const char*) name: Apuntador al nombre del archivo, es opcional si no se entrega un nombre se usara
     *  "Texto_Desencriptado".
     *  -(char* &) PtrArr: Direccion de memoria del apuntador que señala al arreglo.
     *
     *Return: Valor booleano true que indica que el archivo fue guardado de forma exitosa, y falso si ocurrio un error
     *
     *Libreria: https://cplusplus.com/reference/fstream/ofstream/
     */

    ofstream Archivo(name, ios::out);
    if(!Archivo.is_open()){
        return false;
    }

    Archivo.write(PtrArr,n);

    if(Archivo.fail()){
        Archivo.close();
        return false;
    }

    Archivo.close();
    return true;
}


#endif // READWRITELOAD_H
