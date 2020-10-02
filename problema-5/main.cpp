/*

Julián Guillermo Zapata Rugeles

Escriba un programa que muestre el siguiente patrón en la pantalla:
     *
    ***
   *****
  *******
   *****
    ***
     *

El tamaño del patrón estará determinado un número entero impar que ingrese el usuario. En el
ejemplo mostrado, el tamaño de la gura es 7.

*/

#include <iostream>

using namespace std;

int main()
{
     int baseImpar=0 , auxiliarDivision;
    bool sucess=false;
    while (!sucess){
        cout << "Ingrese un número impar mayor que 0 : " ; cin >> baseImpar;
        if( baseImpar%2!=0 && baseImpar>0){
            sucess=true;
        }
    }
    for( int indice=1;indice<baseImpar; indice+=2){
        auxiliarDivision=((baseImpar-indice)/2);
        for( int subIndice=0 ; subIndice < baseImpar ;subIndice++){
            if(subIndice==auxiliarDivision){
                for( int thrIndice=0; thrIndice < indice ; thrIndice ++){
                    cout << "*";
                }
            }
         cout << " ";
        }
        cout << endl;
    }

    for( int indice=baseImpar;indice>=1; indice-=2){
        auxiliarDivision=((baseImpar-indice)/2);
        for( int subIndice=0 ; subIndice < baseImpar ;subIndice++){
            if(subIndice==auxiliarDivision){
                for( int thrIndice=0; thrIndice < indice ; thrIndice ++){
                    cout << "*";
                }
            }
         cout << " ";
        }
        cout << endl;
    }

    return 0;
}
