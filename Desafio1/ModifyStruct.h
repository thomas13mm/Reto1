#ifndef MODIFYSTRUCT_H
#define MODIFYSTRUCT_H

void SepararArrToLZ78(unsigned char* &Arr, unsigned char* &caracteres, unsigned int* &enteros, unsigned int &lengthArr, unsigned int &lengthIntYChar){
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

    lengthIntYChar=lengthArr/2;
    enteros=new unsigned int[lengthIntYChar];
    caracteres=new unsigned char[lengthIntYChar];

    for(unsigned int i = 0; i<lengthArr; i+2){
        if(Arr[i]<='9' || Arr[i]>='0'){
            enteros[i%lengthIntYChar]=(Arr[i]-'0');
        }
        caracteres[i%lenth]=Arr[i+1];
    }

}

#endif // MODIFYSTRUCT_H
