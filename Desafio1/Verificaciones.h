#ifndef VERIFICACIONES_H
#define VERIFICACIONES_H

bool in(unsigned char* &BigArr, unsigned char* &SmallArr, unsigned int &lengthBigArr, unsigned int &lengthSmallArr) {
    /*Descripcion:
     *  Verifica si SmallArr (pista) esta contenido dentro de BigArr (texto desencriptado/descomprimido).
     *
     *Args:
     *  -(unsigned char*) BigArr: Apuntador al arreglo grande (texto completo).
     *  -(unsigned char*) SmallArr: Apuntador al arreglo pequeño (pista a buscar).
     *  -(unsigned int) lengthBigArr: Tamaño del arreglo grande.
     *  -(unsigned int) lengthSmallArr: Tamaño del arreglo pequeño.
     *
     *returns:
     *  true si SmallArr esta contenido en BigArr, false en caso contrario.
     */

    if (lengthSmallArr == 0 || lengthBigArr < lengthSmallArr) {
        return false; // casos borde
    }

    // Recorremos BigArr hasta donde quepa SmallArr
    for (unsigned int i = 0; i <= lengthBigArr - lengthSmallArr; i++) {
        bool match = true;

        // Comparar caracter por caracter
        for (unsigned int j = 0; j < lengthSmallArr; j++) {
            if (BigArr[i + j] != SmallArr[j]) {
                match = false;
                break;
            }
        }

        if (match) {
            return true; // Se encontro la pista
        }
    }

    return false; // No se encontro
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

bool esPrimerCharCero(unsigned char c) {
    /*Descripcion:
     *  Verifica si el caracter recibido es exactamente '0'.
     *  Si es '0' retorna true.
     *  Si esta en el rango '1'-'9' o no es un digito, retorna false.
     *
     *Args:
     *  -(unsigned char) c: Caracter a verificar.
     *
     *Return:
     *  true si c es '0'.
     *  false en cualquier otro caso.
     */

    if (c == '0') {
        return true;
    }
    return false;
}

#endif // VERIFICACIONES_H
