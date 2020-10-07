//Julian Guillermo Zapata Rugeles

//Problema 17. La secuencia de números triangulares se forma al sumar su posición en el arreglo
//con el valor del número anterior: 1, 1+2=3, 3+3=6, 6+4=10, 10+5=15, 15+6=21, 21+7=28...
//Si listamos los números triangulares y sus divisores tenemos:
//1: 1
//3: 1,3
//6: 1,2,3,6
//10: 1,2,5,10
//15: 1,3,5,15
//21: 1,3,7,21
//28: 1,2,4,7,14,28
//Se observa que 28 es el primer número triangular que tiene más de 5 divisores. Escriba un programa
//que reciba un número k y calcule cual es el primer número triangular que tiene más de k divisores.
//Tip: el enésimo número triangular se puede representar como n*(n+1)/2.

#include <limits>
#include <iostream>

using namespace std;

int main()
{
    unsigned long int ul_resultado = 0 ;
    unsigned long int ul_numero_k =  0 ;
    unsigned short int us_contador = 0 ;

    cout << "Este programa busca el primer numero triangular en tener mas de k divisores " <<endl;
    cout << "Ingrese por favor un numero k > 0 : ";
    cin >> ul_numero_k ;

    for(unsigned long int  ul_iterator = 1 ; ul_iterator <std::numeric_limits<unsigned long int >::max() ; ul_iterator ++){
        ul_resultado = ((ul_iterator*(ul_iterator+1))/2) ;
        us_contador=0;
        for(unsigned long int ul_divisor = 1 ; ul_divisor <= ul_resultado ; ul_divisor ++){
           if(ul_resultado % ul_divisor==0){
               us_contador++;
           }

        }
        if(us_contador >= ul_numero_k){
            if(us_contador>ul_numero_k){
                cout << "No se encontro ningun numero con explicitamente  "<< ul_numero_k << " divisores " << endl;
                cout << "sin embargo sí el proximo con "<< us_contador << endl;
                cout << "numero = "<< ul_resultado << endl;
            }
            else{
                cout << "numero triangular encontrado con "<< us_contador<< " divisores " << endl;
                cout << "numero = "<< ul_resultado << endl;
            }
            exit(1);
        }
    }

    return 0;
}
