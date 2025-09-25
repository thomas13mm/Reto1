#ifndef VERIFICACIONES_H
#define VERIFICACIONES_H

bool EsNumero(char &num){
    /*
     * Descripcion:
     *  Verifica si un caracter es un numero basandose en su equivalencia ascci, si es un numero se devuelve verdadero, de lo contrario se
     *  devuelve falso.
     *
     * Args:
     *  -(&char) num: Direccion de memoria del caracter que se quiere comprobar-
     *
     * return:
     *  -bool.
     */

    if(num>='0' && num<='9'){
        return true;
    }
    return false;
}

void ConvertirTextoANumero(unsigned char &n){
    /*Descripcion:
     *  Convierte un caracter de texto a numero
     *
     *Args:
     *  -(unsigned char) n: referencia al caracter que se quiere convertir a numero:
     */
    if(n<='9' && n>='0'){
        n=n-'0';
    }
}

bool in(unsigned char* &BigArr, unsigned char* &SmallArr, unsigned int &lengthBigArr, unsigned int &lengthSmallArr){
    /*Descripcion:
     *  Itera sobre un arreglo y valida si otro arreglo esta dentro del arreglo mas grande, si esta presente se toma como verdadero
     *
     *Args:
     *  -(unsigned char*) BigArr: Referencia al arreglo de caracteres que contiene el texto desencriptado.
     *  -(unsigned char*) SmallArr: Referencia al arreglo de caracteres que tiene el fragmento a buscar.
     *  -(unsigned int) lengthBigArr: referencia al tamaño de arreglo mas grande
     *  -(unsigned int)lengthSmallArr: referancia al tamaño del arreglo mas pequeño
     *
     *returns:
     *  -(bool) true si esta presente, false si no lo esta.
     */

    unsigned int i=0;
    unsigned int j=0;

    while(i != lengthBigArr ){
        if(BigArr[i]==SmallArr[j]){
            j++;
        }
        else if(lengthSmallArr==j){
            return true;
        }
        else{
            j=0;
        }
        i++;
    }
    return false;

}

#endif // VERIFICACIONES_H
