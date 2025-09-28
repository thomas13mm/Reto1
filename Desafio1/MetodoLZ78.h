#ifndef METODOLZ78_H
#define METODOLZ78_H

void descompresionLZ78(unsigned int*& prefijos, unsigned char*& caracteres,unsigned int n,unsigned char*& salida,unsigned int& tamSalida) {
    /*Descripcion:
     *  Descomprime un texto codificado con el algoritmo LZ78 a partir de dos arreglos:
     *  uno de prefijos (índices de diccionario) y otro de caracteres.
     *
     *Args:
     *  -(unsigned int*&) prefijos: Arreglo que contiene los índices de prefijos de cada palabra en el diccionario.
     *  -(unsigned char*&) caracteres: Arreglo que contiene los caracteres finales de cada palabra.
     *  -(unsigned int) n: Número de tuplas, es decir, el tamaño de los arreglos prefijos y caracteres.
     *  -(unsigned char* &) salida: Apuntador por referencia donde se almacenará el texto descomprimido.
     *  -(unsigned int &) tamSalida: Referencia a un entero donde se devolverá el tamaño del texto descomprimido.
     */

    // --- 1. Inicializar estructuras auxiliares ---
    unsigned char** diccionario = new unsigned char*[n + 1];
    unsigned int* longitudes = new unsigned int[n + 1];

    diccionario[0] = nullptr;
    longitudes[0] = 0;

    // --- 2. Construcción del diccionario y conteo del tamaño total ---
    tamSalida = 0;
    for (unsigned int k = 0; k < n; k++) {
        unsigned int idx = prefijos[k];

        // Validación: si el índice es mayor al actual, se normaliza a 0
        if (idx > k) idx = 0;

        unsigned int nuevaLong = longitudes[idx] + 1;
        diccionario[k + 1] = new unsigned char[nuevaLong];

        // Copiar el prefijo correspondiente
        for (unsigned int j = 0; j < longitudes[idx]; j++) {
            diccionario[k + 1][j] = diccionario[idx][j];
        }

        // Añadir el caracter final
        diccionario[k + 1][longitudes[idx]] = caracteres[k];
        longitudes[k + 1] = nuevaLong;

        // Aumentar el tamaño total de salida
        tamSalida += nuevaLong;
    }

    // --- 3. Reservar memoria para la salida ---
    salida = new unsigned char[tamSalida];

    // --- 4. Copiar el contenido del diccionario a la salida ---
    unsigned int pos = 0;
    for (unsigned int i = 1; i <= n; i++) {
        for (unsigned int j = 0; j < longitudes[i]; j++) {
            salida[pos++] = diccionario[i][j];
        }
    }

    // --- 5. Liberar memoria auxiliar ---
    for (unsigned int i = 1; i <= n; i++) {
        delete[] diccionario[i];
    }
    delete[] diccionario;
    delete[] longitudes;
}



#endif // METODOLZ78_H

