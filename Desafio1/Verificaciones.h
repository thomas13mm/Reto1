#ifndef VERIFICACIONES_H
#define VERIFICACIONES_H

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
