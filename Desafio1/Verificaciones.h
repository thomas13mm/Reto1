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
     *  Verifica si SmallArr (pista) está contenido dentro de BigArr (texto desencriptado/descomprimido).
     *
     *Args:
     *  -(unsigned char*) BigArr: Apuntador al arreglo grande (texto completo).
     *  -(unsigned char*) SmallArr: Apuntador al arreglo pequeño (pista a buscar).
     *  -(unsigned int) lengthBigArr: Tamaño del arreglo grande.
     *  -(unsigned int) lengthSmallArr: Tamaño del arreglo pequeño.
     *
     *returns:
     *  true si SmallArr está contenido en BigArr, false en caso contrario.
     */

    if (lengthSmallArr == 0 || lengthBigArr < lengthSmallArr) {
        return false; // casos borde
    }

    // Recorremos BigArr hasta donde quepa SmallArr
    for (unsigned int i = 0; i <= lengthBigArr - lengthSmallArr; i++) {
        bool match = true;

        // Comparar carácter por carácter
        for (unsigned int j = 0; j < lengthSmallArr; j++) {
            if (BigArr[i + j] != SmallArr[j]) {
                match = false;
                break;
            }
        }

        if (match) {
            return true; // Se encontró la pista
        }
    }

    return false; // No se encontró
}


void print(unsigned char* &arr1, unsigned int* &arr2, unsigned int &length1, unsigned int &length2){
    std::cout<<"Letras: ";
    for(unsigned int i = 0; i<length1;i++){
        std::cout<<arr1[i]<<", ";
    }
    cout<<'\n'<<"Indices: ";
    for(unsigned int i = 0; i<length2;i++){
        std::cout<<arr2[i]<<", ";
    }
}

#endif // VERIFICACIONES_H
