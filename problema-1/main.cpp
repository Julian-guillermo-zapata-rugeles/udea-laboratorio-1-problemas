//Julian Guillermo Zapata Rugeles
//Problema 1. Escriba un programa que identique si un carácter ingresado es una vocal, una con-
//sonante o ninguna de las 2 e imprima un mensaje según el caso.
//Nota: el formato de salida debe ser:
//no es una letra.
//a es una vocal.


#include <iostream>

using namespace std;

int main()
{
    char char_vocales[5] = {'a','e','i','o','u'};
    char char_userInput = '\0';
    unsigned int diferencia = 'A'-'a';
    cout << "Ingrese una letra para verificar si es vocal/consonante o ninguna "
            ": " ;
    cin >> char_userInput ;

    // si está en mayusculas se pasa a minusculas
    if(char_userInput >= 'A' && char_userInput <='Z'){
        char_userInput=char(char_userInput-diferencia);

    }

    // se comprueba si está en minusculas y se valida si está en las vocales
    if(char_userInput >= 'a' && char_userInput <= 'z'){
        for(unsigned short int i=0 ; i < sizeof(char_vocales) ; i ++){
            if(char_userInput==char_vocales[i]){
                cout<<"Es una vocal "<< endl ;
                break;
            }
            else{
                cout <<"Es una consonante" <<endl;
                break;
            }
        }

    }
    else{
        cout << char_userInput << " No es vocal ni consonante "<<endl;
    }
    return 0;
}
