//Julian Guillermo Zapata Rugeles
//Problema 11. Escriba un programa que reciba un número y calcule el mínimo común múltiplo de
//todos los números enteros entre 1 y el número ingresado.
//Ej: Si se recibe 4 el programa debe imprimir 12.
//Nota: la salida del programa debe ser: El minimo comun multiplo es: 12.

//ALGORITMO DE FUERZA BRUTA

#define ULLI unsigned long long int
#include <iostream>
#include <limits>

bool verificarMCM(ULLI *,ULLI *); // analizar si es el número es minimo comun multiplo


using namespace std;

int main()
{
    bool salir = false;
    ULLI numeroUsuario=0 ;
    ULLI limiteMaximo = std::numeric_limits<unsigned long long int>::max(); // maximo numero representable de unsinged long long int
    cout << "Ingrese un numero para hallar su MCM desde 1 hasta N : " ;
    cin >> numeroUsuario ;
    for(ULLI i = numeroUsuario ; i < limiteMaximo ; i ++ ){
        // desde el numero de usuario hasta el límite máximo unsigne long long int
        salir=verificarMCM(&i,&numeroUsuario);
        if(salir==true){
            cout << i << " es el minimo comun multiplo de todos los numeros desde 1 hasta "<< numeroUsuario << endl;;
            break;
        }
    }
    if(salir==false){
        cout << "Se alcanzó el limite maximo permitido para encontrar el minimo comun multiplo " << endl;
    }
    return 0;
}

bool verificarMCM(ULLI *numeroPrueba , ULLI *numeroUsuario){
    // se iterará en un ciclo for desde 1 hasta *numeroUsuario
    // cada número será probado en *numeroPrueba % i != 0
    // si al menos alguno cumple con no ser divisor exacto de *numeroPrueba
    // sucess <-- false ; y  al salir del ciclo se retornará false pues no todos cumplieron
    // si se retorna true ; todos fueron divisores por lo que *numeroPrueba es un multiplo común
    //cout <<"probando con  = "<< *numeroPrueba << "  -->  desde 1 hasta " << *numeroUsuario << endl;
    bool sucess=true;
    for(ULLI i= 1 ; i <= *numeroUsuario ; i++){ // desde 1 hasta -> n
        if(*numeroPrueba % i != 0 ){
            sucess=false; // si almenos alguno cumple con no ser divisor al final del ciclo succes=false.
        }
    }

    return sucess;
}
