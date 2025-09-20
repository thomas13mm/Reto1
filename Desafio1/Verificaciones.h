#ifndef VERIFICACIONES_H
#define VERIFICACIONES_H

bool EsNumero(char &num){
    /*
     * Descripcion:
     *  Verifica si un caracter es un numero basandose en su equivalencia ascci, si es un numero se devuelve verdader, de lo contrario se
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

#endif // VERIFICACIONES_H
