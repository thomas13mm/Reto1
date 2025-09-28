#include <iostream>
#include <Desencriptado.h>
#include <ReadWriteLoad.h>
#include <Verificaciones.h>
#include <MetodoLRE.h>
#include <ModifyStruct.h>
#include <MetodoLZ78.h>

using namespace std;

int main(){

    //Declaraciones Apuntadores
    unsigned char* Encriptado=nullptr;
    unsigned char* Pista=nullptr;
    unsigned char* Comprimido=nullptr;
    unsigned char* Caracteres=nullptr;
    unsigned char* Resultado=nullptr;
    unsigned int* Indices=nullptr;

    //Declaraciones Variables
    unsigned int length_Encriptado;
    unsigned int length_Pista;
    unsigned int length_CharInd;
    unsigned int length_Resultado;
    const char namepista[]="../../datasetDesarrollo/pista3.txt";
    const char nameencriptado[]="../../datasetDesarrollo/Encriptado3.txt";

    //Leer y cargar estructuras
    Encriptado=ReadArchivo(nameencriptado,length_Encriptado);
    Pista=ReadArchivo(namepista,length_Pista);

    bool found = false;

    for(unsigned int k = 0; k<256 && !found; k++){
        for(unsigned int n = 0; n<8 && !found; n++){

            desencriptarTexto(k,n,Encriptado,length_Encriptado,Comprimido);

            unsigned short int caso=1;
            while(caso <= 2 && !found){
                switch(caso){
                case 1: // LRE
                    SepararArrLRE(Comprimido,Caracteres,Indices,length_Encriptado,length_CharInd);
                    DescompresionLRE(Caracteres,Indices,Resultado,length_CharInd,length_Resultado);

                    if(in(Resultado,Pista,length_Resultado,length_Pista)){
                        SaveArchivo(Resultado,length_Resultado);
                        cout<<"El K era: "<<k<<"\nEl n era: "<<n<<"\nEl metodo era: LRE\n";
                        found = true;
                    }

                    delete[] Caracteres; Caracteres=nullptr;
                    delete[] Indices; Indices=nullptr;
                    delete[] Resultado; Resultado=nullptr;
                    break;

                case 2: // LZ78
                    SepararArrLZ78(Comprimido,Caracteres,Indices,length_Encriptado,length_CharInd);
                    //print(Caracteres,Indices,length_CharInd,length_CharInd);
                    descompresionLZ78(Indices,Caracteres,length_CharInd,Resultado,length_Resultado);

                    if(in(Resultado,Pista,length_Resultado,length_Pista)){
                        SaveArchivo(Resultado,length_Resultado);
                        cout<<"El K era: "<<k<<"\nEl n era: "<<n<<"\nEl metodo era: LZ78\n";
                        found = true;
                    }

                    delete[] Caracteres; Caracteres=nullptr;
                    delete[] Indices; Indices=nullptr;
                    delete[] Resultado; Resultado=nullptr;
                    break;
                }
                caso++;
            }

            delete[] Comprimido; Comprimido=nullptr;
        }
    }

    if(!found){
        cout<<"No se encontro ningun caso valido\n";
    }

    delete[] Encriptado;
    delete[] Pista;

    cout<<"All done.";
    return 0;
}

