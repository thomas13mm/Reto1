#ifndef METODOLZ78_H
#define METODOLZ78_H

#endif // METODOLZ78_H

void descompresionLZ78(int*& prefijos, unsigned char*& caracteres, int n, char*& result, int& tamResult) {


    char** diccionario = new char*[n+1]; // arreglo de apuntadores a palabras
    int* longitudes = new int[n+1]; // arreglo de longitudes

    diccionario[0] = nullptr;
    longitudes[0] = 0;

    // itera sobre cada par (prefijo, letra)
    for (unsigned int k = 0; k < n; k++) {
        int idx = prefijos[k];              // prefijo
        unsigned char c = caracteres[k];    // letra nueva
        int nuevaLong = longitudes[idx] + 1;

        diccionario[k + 1] = new char[nuevaLong];  // reserva para la nueva palabra

        // copiar la palabra del prefijo 
        for (unsigned int j = 0; j < longitudes[idx]; j++) {
            diccionario[k + 1][j] = diccionario[idx][j];
        }

        diccionario[k + 1][longitudes[idx]] = c   // se pone la letra nueva al final
        longitudes[k + 1] = nuevaLong             // guarda la longitud
    }

    // ciclo para calcular la longitud total del texto descomprimido sumando todas las longitudes anteriores
    int total = 0;
    for (unsigned int i = 1; i <= n; i++) {
        total += longitudes[i];
    }

    

}