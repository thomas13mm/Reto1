#ifndef DESENCRIPTADO_H
#define DESENCRIPTADO_H

unsigned char aplicarXOR(unsigned char caracter, unsigned char K) {
    /*Descripcion:
    *  Funcion encargada de aplicar la operacion XOR entre un caracter y la clave K.
    *
    *Args:
    *  -(unsigned char) caracter: Carácter de entrada a procesar.
    *  -(unsigned char) K: Clave de un byte para la operación XOR.
    *
    *return: (unsigned char) Resultado de aplicar XOR entre caracter y K.
    *
    */
    unsigned char resultado = caracter ^ K;
    return resultado;
}

unsigned char rotarDerecha(unsigned char caracter, unsigned int N) {
    /*Descripcion:
    *  Funcion encargada de rotar a la derecha los bits de un caracter.
    *
    *Args:
    * -(unsigned char) caracter: Caracter (byte) a rotar.
    *  -(unsigned int) N: Numero de posiciones a rotar a la derecha.
    *
    *return: un caracter resultante de la rotacion.
    *
    */
    unsigned char resultado = ((caracter >> N) | (caracter << (8 - N)));
    return resultado;
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
#endif // DESENCRIPTADO_H
