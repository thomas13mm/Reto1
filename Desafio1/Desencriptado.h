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

char* desencriptarTexto(const char* textoEncriptado, unsigned int n, unsigned char* K, unsigned int* N ) {
    /*Descripcion:
     *  Funcion encargada de intentar desencriptar un texto encriptado usando
     *  un par (K, N). Aplica XOR y rotacion a la derecha, y valida que el 
     *  resultado contenga unicamente caracteres permitidos (A-Z, a-z, 0-9).
     *
     *Args:
     *  -(const char*) textoEncriptado: Texto de entrada (arreglo de caracteres encriptados).
     *  -(unsigned int) n: Longitud del texto encriptado.
     *  -(unsigned char) K: Clave para la operacion XOR.
     *  -(unsigned int) N: Numero de posiciones de rotacion a la derecha.
     *  -(char*) textoDesencriptado: Arreglo dinamico donde se almacena el resultado.
     *
     *return: (bool) true si todos los caracteres desencriptados son validos,
     *               false si se encuentra al menos un caracter invalido.
     */
}

#endif // DESENCRIPTADO_H
