//Julian Guillermo Zapata rugees
//Problema 13. Escriba un programa que reciba un número y calcule la suma de todos los primos
//menores que el número ingresado.
//Ej: Si se recibe 10 el programa debe imprimir 17.
//Nota: la salida del programa debe ser: El resultado de la suma es: 17.



#include <iostream>

using namespace std;

int main()
{
    unsigned int numeroUsuario = 0 ;
    unsigned int sumatoria = 0 ;
    unsigned short int contador= 0 ;
    cout << "Ingrese un numero N > 0 cualquiera : ";
    cin >> numeroUsuario;

    for(unsigned int cicloSuperior = 1 ; cicloSuperior < numeroUsuario ; cicloSuperior ++ ){
        contador=0;
        for(unsigned int cicloInferior=1;cicloInferior<=cicloSuperior;cicloInferior++){
            if(cicloSuperior%cicloInferior==0){
                contador++; // aumenta pues se encontró otro divisor más
            }
        }
        if(contador<=2 && cicloSuperior!=1){
            //cout << cicloSuperior << " es un numero primo (sumado al acumulador)"<<endl;
            sumatoria+=cicloSuperior;
        }
    }
    cout <<"El resultado de la suma es "
           ": "<< sumatoria <<endl;
    return 0;
}
