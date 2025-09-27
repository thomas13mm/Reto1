#ifndef MODIFYSTRUCT_H
#define MODIFYSTRUCT_H

void SepararArrLRE(unsigned char* &Arr,  unsigned char* &caracteres, unsigned int* &enteros, unsigned int &lengthArr, unsigned int &lengthIntYChar){
    /*Descripcion:
     *  Toma un arreglo de caracteres y lo separa en 2 arreglos de tal forma que los caracteres que corresponden a numeros quedan en
     *  un solo arreglo y los caracteres alfabeticos quedan en otro arreglo por separados manteniendo una relacion de tuplas por indice
     *
     *Args:
     *  -(unsigned char*) Arr: Arreglo que contiene tanto letras como numeros.
     *  -(unsigned char*) caracteres: apuntador vacio que se le asignara un arreglo de caracteres.
     *  -(unsigned int*) enteros: apuntador vacio que se le asignara un arreglo de enteros.
     *  -(unsigned int) lengthArr: referencia al tamaño de Arr.
     *  -(unsigned int) lengthIntYchar: referencia a una variable para guardar el tamaño de caracteres y enteros.
     */

    lengthIntYChar=lengthArr/3;

    enteros=new unsigned int[lengthIntYChar];
    caracteres=new unsigned char[lengthIntYChar];

    for (unsigned int i = 0, j = 0; i < lengthArr; i += 3, j++) {
        enteros[j]    = Arr[i+1];
        caracteres[j] = Arr[i+2];
    }


}

void SepararArrLZ78(unsigned char* &Arr, unsigned char* &caracteres, unsigned int* &prefijos,unsigned int &lengthArr, unsigned int &n){
    /*Descripcion:
     *  Separa en 2 arreglos desacoplados la los prefijos y los indices de estos dentro del arreglo mas grande teniendo en cuenta que
     *  los 2 primeros bytes representan el prefijo de la letra
     *
     *Args:
     *  -(unsigned char*) Arr: Referencia al arreglo que se va separar
     *  -(unsigned char*) caracteres: Referencia a un apuntador que va guardar el arreglo con los caracteres
     *  -(unsigned int*) prefijos: Referencia al apuntador que guarda el arreglo con los prefijos
     *  -(unsigned int) lenghtArr: Referencia a la longitud de Arr
     *  -(unsigned int) n: referencia donde se va a almacenar el tamaño de los arreglos desacoplados
     */


    n = lengthArr / 3;

    prefijos   = new unsigned int[n];
    caracteres = new unsigned char[n];

    for (unsigned int i = 0, j = 0; i < lengthArr; i += 3, j++) {
        prefijos[j] = (Arr[i] << 8) | Arr[i+1];
        caracteres[j] = Arr[i+2];
    }
}


#endif // MODIFYSTRUCT_H
