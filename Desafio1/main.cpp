#include <iostream>
#include <Desencriptado.h>
#include <ReadWriteLoad.h>
#include <MetodoLRE.h>

using namespace std;

int main()
{
    //Declaraciones
    unsigned char* Encriptado=nullptr;
    unsigned char* Pista=nullptr;
    unsigned char* Result=nullptr;
    unsigned int lengthEncriptado=0;
    unsigned int lengthDesencriptado=0;

    //Cargo la pista
    const unsigned char* NamePista="pista1";
    Pista=ReadArchivo(NamePista,lengthEncriptado);

    //Cargo el texto encriptado
    const unsigned char* NameEncriptado="../../../Encriptado1.txt";
    Encriptado=ReadArchivo(NameEncriptado, lengthEncriptado);

    //ciclos para hallar k y n
    for(unsigned int k = 0; k < 255; k++){  //ciclo para iterar sobre valores de k
        for(unsigned int n = 0; n<8; n++){  //ciclo para iterar sobre valores de n

            //Aqui llamo la funcion desencriptar
            Result=desencriptarTexto(Encriptado,lengthEncriptado,k,n);

            //Aplico 2 casos. El primero para LRE y el segundo para LZ78
            unsigned int Metodo=1;
            switch (Metodo) {

            case 1:             //ApliCo descompresion con LRE primero
                DescompresionLRE(Encriptado, );
                Metodo++;
                break;

            case 2:            //Aplico descompresion lz78
                //DescompresionLZ78
                //LZ78
                break;
            default:
                cout<<"Error: no entra en ningun caso";
                break;
            }

            //Funcion que verifique si la pista esta dentro del arreglo y retorne falso o verdadero
            //si es verdadero entonces break

        }
    }

    //Imprime k y n
    //Imprime el texto por consola

    if(!SaveArchivo(Result, lengthDesencriptado))
        cout<<"Error al guardar el texto desencriptado";
    cout<<"Guardado exitosamente";


    return 0;
}
