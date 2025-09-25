#include <iostream>
#include <Desencriptado.h>
#include <ReadWriteLoad.h>
#include <Verificaciones.h>
#include <MetodoLRE.h>
#include <ModifyStruct.h>

using namespace std;

int main()
{
    //Declaraciones
    unsigned char* Encriptado=nullptr;
    unsigned char* Pista=nullptr;
    unsigned char* Result=nullptr;
    unsigned char* caracteres=nullptr;
    unsigned int* enteros=nullptr;
    unsigned int lengthPista=0;
    unsigned int lengthEncriptado=0;
    unsigned int lengthDesencriptado=0;
    unsigned int lengthIntChar;

    //Cargo la pista
    const unsigned char* NamePista="../../../pista3";
    Pista=ReadArchivo(NamePista,lengthPista);

    //Cargo el texto encriptado
    const unsigned char* NameEncriptado="../../../Encriptado3.txt";
    Encriptado=ReadArchivo(NameEncriptado, lengthEncriptado);

    //ciclos para hallar k y n
    for(unsigned int k = 0; k < 256; k++){  //ciclo para iterar sobre valores de k
        for(unsigned int n = 0; n<8; n++){  //ciclo para iterar sobre valores de n

            //Aqui llamo la funcion desencriptar
            Result=desencriptarTexto(Encriptado,lengthEncriptado,k,n);

            //Aqui separo las estructuras de datos desacopladas.
            SepararArr(Result, caracteres, enteros, lengthEncriptado, lengthIntChar);
            delete[] Result;
            Result=nullptr;

            //Aplico 2 casos. El primero para LRE y el segundo para LZ78
            unsigned int Metodo=1;
            switch (Metodo) {

            case 1:             //ApliCo descompresion con LRE primero
                DescompresionLRE(caracteres, enteros, Result, lengthIntChar);
                if(in(Result,Pista,lengthDesencriptado,lengthPista)){
                    delete[] caracteres;
                    delete[] enteros;
                    delete[] Pista;
                    delete[] Encriptado;
                    Pista=nullptr;
                    Encriptado=nullptr;
                    enteros=nullptr;
                    caracteres=nullptr;
                    break;
                }
                Metodo++;

            case 2:            //Aplico descompresion lz78
                //DescompresionLZ78
                if(in(Result,Pista,lengthDesencriptado,lengthPista)){
                    delete[] caracteres;
                    delete[] enteros;
                    delete[] Pista;
                    delete[] Encriptado;
                    Encriptado=nullptr;
                    Pista=nullptr;
                    enteros=nullptr;
                    caracteres=nullptr;
                    break;
                }
                Metodo++;
            default:
                cout<<"Error: no entra en ningun caso";
                break;
            }

            if(in(Result,Pista,lengthDesencriptado,lengthPista))
                break;
            cout<<"El texto fue desplazado "<<n<<" bits."<<'\n';
        }

        if(in(Result,Pista,lengthDesencriptado,lengthPista))
            break;
        cout<<"El texto fue encriptado con una mascara de "<<k<<" bits."<<'\n';
        //Imprime el texto por consola

    }


    if(!SaveArchivo(Result, lengthDesencriptado))
        cout<<"Error al guardar el texto desencriptado";
    cout<<"Guardado exitosamente";


    return 0;
}
