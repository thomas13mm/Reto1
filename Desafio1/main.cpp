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
    const char namepista[]="../../datasetDesarrollo/pista2.txt";
    const char nameencriptado[]="../../datasetDesarrollo/Encriptado2.txt";

    //Leer y cargar estrucuturas
    Encriptado=ReadArchivo(nameencriptado,length_Encriptado);
    Pista=ReadArchivo(namepista,length_Pista);

    //Buscar k y n
    for(unsigned int k = 0; k<256; k++){
        for(unsigned int n = 0; n<8; n++){

            //Desencriptamos con el k y n actual
            desencriptarTexto(k,n,Encriptado,length_Encriptado,Comprimido);

            //Intentamos descomprimir Comprimido con LRE y LZ78
            unsigned short int caso=1;
            switch(caso){
                case 1://LRE
                    SepararArrLRE(Comprimido,Caracteres,Indices,length_Encriptado,length_CharInd);
                    DescompresionLRE(Caracteres,Indices,Resultado,length_CharInd,length_Resultado);

                    //verificamos si la pista esta dentro del resultado
                    if(in(Resultado,Pista,length_Resultado,length_Pista)){
                        SaveArchivo(Resultado,length_Resultado);
                        cout<<"El K era: "<<k<<'\n'<<"El n era: "<<n<<'\n'<<"El metodo era: LRE"<<'\n';
                        delete[] Caracteres;
                        delete[] Encriptado;
                        delete[] Comprimido;
                        delete[] Indices;
                        delete[] Resultado;
                        Caracteres=nullptr;
                        Indices=nullptr;
                        Encriptado=nullptr;
                        Comprimido=nullptr;
                        Resultado=nullptr;

                        k=99;
                        n=99;
                        break;
                    }
                    else{

                        //Si no era el caso entonces liberamos memoria de caracteres,indices, y resultado;
                        delete[] Caracteres;
                        delete[] Indices;
                        delete[] Resultado;
                        Caracteres=nullptr;
                        Indices=nullptr;
                        Resultado=nullptr;
                        caso++;
                    }

                case 2://LZ78
                    SepararArrLZ78(Comprimido,Caracteres,Indices,length_Encriptado,length_CharInd);
                    descompresionLZ78(Indices,Caracteres,length_CharInd,Resultado,length_Resultado);

                    //verificamos si la pista esta dentro del resultado
                    if(in(Resultado,Pista,length_Resultado,length_Pista)){
                        SaveArchivo(Resultado,length_Resultado);
                        cout<<"El K era: "<<k<<'\n'<<"El n era: "<<n<<'\n'<<"El metodo era: LRE"<<'\n';
                        delete[] Caracteres;
                        delete[] Encriptado;
                        delete[] Comprimido;
                        delete[] Indices;
                        delete[] Resultado;
                        Caracteres=nullptr;
                        Indices=nullptr;
                        Encriptado=nullptr;
                        Comprimido=nullptr;
                        Resultado=nullptr;

                        k=99;
                        n=99;
                        break;
                    }
                    else{
                        //Si no era el caso entonces liberamos memoria de caracteres,indices, y resultado;
                        delete[] Caracteres;
                        delete[] Indices;
                        delete[] Resultado;
                        Caracteres=nullptr;
                        Indices=nullptr;
                        Resultado=nullptr;
                        caso++;
                    }
                default:
                    break;

            }
        }
    }

    cout<<"All done";

    return 0;
}
