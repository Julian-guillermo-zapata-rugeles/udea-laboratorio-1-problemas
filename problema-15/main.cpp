#include <iostream>

using namespace std;
void mostrar(int );

int main()
{
    int dimesiones = 0;
    int auxiliar = 0;
    int n1=0;
    cout << "Ingrese un numro para la dimesiones de la matriz : " ;
    cin >> dimesiones;
    for(int i=dimesiones ;i >= 1 ; i-=2){
        mostrar(i);
    }
    return 0;
}

void mostrar(int a ){
    //
    //cout <<(a*a)-(a-1)<< " <-> " << a*a  << endl;
    for(int b=(a*a)-(a-1);b<a*a;b++){
        cout << b <<" ";
    }
    cout << endl;
}
