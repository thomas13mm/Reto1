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

#endif // VERIFICACIONES_H
