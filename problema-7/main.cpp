/*
Julian Guillermo Zapata Rugeles

Problema 7. En la serie de Fibonacci, cada número es la suma de los 2 anteriores e inicia con 1 y
1. Ej: 1, 1, 2, 3, 5, 8, ....
Escriba un programa que reciba un número n y halle la suma de todos los números pares en la serie
de Fibonacci menores a n.
Ej: si se ingresa 10, sería la suma de 2+8 =10
Nota: el formato de salida debe ser: El resultado de la suma es: 10
*/
#include <iostream>

using namespace std;

int main()
{

    int a=1 , b = 1 , resultado = 0 , backup = 1 , cota = 0 , suma = 0;
    cout << "Ingrese un numero para probar en la seria de fibonacci : " ;
    cin >> cota;
    while (true){
        resultado = a +b ;
        a = resultado ;
        b = backup ;
        backup = resultado ;
        if (resultado%2==0){
//            cout << resultado << endl ;
            if(resultado<=cota){
                suma=suma+resultado;
            }
        }
        if(resultado>=cota){
            break;
        }
    }

    cout << "la suma es "<<suma <<endl;
    return 0;
}
