#include <iostream>
#include <cstdio>
#include <Desencriptado.h>
#include <ReadWriteLoad.h>
#include <Verificaciones.h>
#include <MetodoLRE.h>
#include <ModifyStruct.h>
#include <MetodoLZ78.h>

using namespace std;

int main() {

    // Declaraciones de punteros
    unsigned char* Encriptado = nullptr;
    unsigned char* Pista = nullptr;
    unsigned char* Comprimido = nullptr;
    unsigned char* Caracteres = nullptr;
    unsigned char* Resultado = nullptr;
    unsigned int* Indices = nullptr;

    unsigned int length_Encriptado;
    unsigned int length_Pista;
    unsigned int length_CharInd;
    unsigned int length_Resultado;

    int totalArchivos;
    cout << "Ingrese la cantidad de archivos a procesar: ";
    cin >> totalArchivos;

    for (int archivo = 1; archivo <= totalArchivos; archivo++) {
        cout << "\n=== Procesando archivo #" << archivo << " ===\n";

        // Generar rutas dinámicamente SIN STL
        char namepista[256];
        char nameencriptado[256];
        sprintf(namepista, "../../datasetDesarrollo/pista%d.txt", archivo);
        sprintf(nameencriptado, "../../datasetDesarrollo/Encriptado%d.txt", archivo);

        // Leer archivos
        Encriptado = ReadArchivo(nameencriptado, length_Encriptado);
        Pista = ReadArchivo(namepista, length_Pista);

        bool found = false;

        for (unsigned int k = 0; k < 256 && !found; k++) {
            for (unsigned int n = 0; n < 8 && !found; n++) {

                desencriptarTexto(k, n, Encriptado, length_Encriptado, Comprimido);

                if (esCaracterInvalido(Comprimido[1]))
                    continue;

                unsigned short int caso = esPrimerCharCero(Comprimido[1]);

                while (caso <= 2 && !found) {
                    switch (caso) {
                    case 1: // LRE
                        SepararArrLRE(Comprimido, Caracteres, Indices, length_Encriptado, length_CharInd);
                        DescompresionLRE(Caracteres, Indices, Resultado, length_CharInd, length_Resultado);

                        if (in(Resultado, Pista, length_Resultado, length_Pista)) {
                            SaveArchivo(Resultado, length_Resultado);
                            cout << "El K era: " << k << "\nEl n era: " << n << "\nEl metodo era: LRE\n";
                            found = true;
                        }

                        delete[] Caracteres; Caracteres = nullptr;
                        delete[] Indices; Indices = nullptr;
                        delete[] Resultado; Resultado = nullptr;
                        break;

                    case 2: // LZ78
                        SepararArrLZ78(Comprimido, Caracteres, Indices, length_Encriptado, length_CharInd);
                        descompresionLZ78(Indices, Caracteres, length_CharInd, Resultado, length_Resultado);

                        if (in(Resultado, Pista, length_Resultado, length_Pista)) {
                            SaveArchivo(Resultado, length_Resultado);
                            cout << "El K era: " << k << "\nEl n era: " << n << "\nEl metodo era: LZ78\n";
                            found = true;
                        }

                        delete[] Caracteres; Caracteres = nullptr;
                        delete[] Indices; Indices = nullptr;
                        delete[] Resultado; Resultado = nullptr;
                        break;
                    }
                    caso++;
                }

                delete[] Comprimido; Comprimido = nullptr;
            }
        }

        // Liberar memoria
        delete[] Encriptado; Encriptado = nullptr;
        delete[] Pista; Pista = nullptr;

        if (!found) {
            cout << "No se encontro ningun caso valido para el archivo " << archivo << "\n";
        }
    }

    cout << "\n=== Todos los archivos procesados ===\n";
    return 0;
}
