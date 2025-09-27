#ifndef VERIFICACIONES_H
#define VERIFICACIONES_H

bool EsNumero(unsigned char &num){
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

bool in(unsigned char* &BigArr, unsigned char* &SmallArr, unsigned int &lengthBigArr, unsigned int &lengthSmallArr) {
    /*Descripcion:
     *  Verifica si SmallArr está contenido dentro de BigArr.
     *
     *Args:
     *  -(unsigned char*) BigArr: Apuntador al arreglo grande.
     *  -(unsigned char*) SmallArr: Apuntador al arreglo pequeño (patrón a buscar).
     *  -(unsigned int) lengthBigArr: Tamaño del arreglo grande.
     *  -(unsigned int) lengthSmallArr: Tamaño del arreglo pequeño.
     *
     *returns:
     *  true si SmallArr está contenido en BigArr, false en caso contrario.
     */

    if (lengthSmallArr == 0 || lengthBigArr < lengthSmallArr) {
        return false; // casos borde: patrón vacío o más grande que el texto
    }

    unsigned int i = 0; // recorre BigArr
    unsigned int j = 0; // recorre SmallArr

    while (i < lengthBigArr) {
        if (BigArr[i] == SmallArr[j]) {
            j++;
            if (j == lengthSmallArr) {
                return true; // se encontró el patrón completo
            }
        } else {
            j = 0; // reinicia el patrón
        }
        i++;
    }

    return false;
}


#endif // VERIFICACIONES_H
