//Julian Guillermo Zapata Rugeles
//Problema 9. Escriba un programa que pida un número entero N e imprima el resultado de la suma
//de todos sus dígitos elevados a sí mismos.
//Ej: si se ingresa 1223 el resultado sería
//1 1 + 2 2 + 2 2 + 3 3 = 36
//Nota: la salida del programa debe ser: El resultado de la suma es: 36.

#include <iostream>

using namespace std;

int main()
{
    int numeroPruba = 0 ;
    int potencia = 1;
    int modulo=0;
    int sumatoria = 0 ;
    cout << "Ingrese un numero para descomponer : ";
    cin >> numeroPruba ;
    while (numeroPruba>=1) {
        modulo=numeroPruba%10;
        cout << modulo << " x " << modulo << " = ";
        potencia=1;
        for(int i = 0 ;i < modulo ; i ++){
            potencia=potencia*modulo;
        }
        sumatoria=sumatoria+potencia;
        cout << potencia << endl;
        numeroPruba=numeroPruba/10;

    }
    cout << "La suma es : "<<sumatoria<< endl;
    return 0;
}
