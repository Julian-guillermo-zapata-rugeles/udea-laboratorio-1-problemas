#include <iostream>

using namespace std;

void buscar(int *);
int arrayPotencias[100];
int main()
{
    int numero=0;
    cout << "Ingrese un numero : " << endl;
    cin >> numero;
    for(int i =0 ; i < 100 ; i ++){
        arrayPotencias[i]=0;
    }
    //buscar(&numero);
    int l=0;
    for(int i=1; i <= numero; i++){
        //cout << i << " valor "<<endl;
        //cout << &i << " memory "<<endl;
        l=i;
        int primo=0;
        for(int k=1;k<=l;k++){
        if(l%k==0){
            primo++;
        }
    }
        if(primo==2){

        }
        else{
            buscar(&l);
        }

    }

    for(int i =0 ; i < numero ; i ++){
        if(arrayPotencias[i]!=0){
            cout << "["<<arrayPotencias[i]<<"]"<<" posicion -->"<<i<<endl;
        }

    }
    return 0;
}

void buscar(int *numero){
    int contador=0;
    int indice=0;
    int potencias=2;
    bool salir=false;
    while(salir==false){
        if(*numero==1){
            contador=0;
            salir=true;
        }
        if(*numero%potencias==0){
            contador++;
            *numero=*numero/potencias;
            //cout << numero << endl;
        }
        else{

            contador=0;
            potencias++;
        }
        if(contador!=0){
            cout << potencias << "^" << contador << endl;
            arrayPotencias[potencias]=arrayPotencias[potencias]+1;
        }

    }
}
