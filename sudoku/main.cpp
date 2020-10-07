/*

Julian Guillermo Zapata Rugeles
2020
sudoku
rellenar el sudoku o jugar
*/

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;


bool jugarSudoku();
bool computadora();
struct sudoku{

  int **tablero;
  int jugadas=9*9;

  sudoku();  // constructor
  ~sudoku(); // destructor

  void mostrarSudoku();
  bool hacerJugada(int fila , int columna, int numero );
  int jugadasRestantes();

};


int main()
{
    int eleccion=0;
    cout << "*****  Bienvenido al juego del sudoku  *****\n"<<endl;
    cout <<"1) Jugar al sudoku"<<endl;
    cout <<"2) Intentar resolverlo (computadora)"<<endl;
    cin>> eleccion;
    if(eleccion==1){
        jugarSudoku();
    }
    else{
        while (computadora()!=true) {
            cout << "Solucion no factible --> Reiniciando la busqueda "<<endl;
        }

    }
    return 0;
}

sudoku::~sudoku(){

}
bool computadora(){
    sudoku *sdk = new sudoku();
    int numero=0;
    int maximoIntentos=0;
    srand(time(NULL));
    while (sdk->jugadasRestantes()!=0) {
        for(short int a = 0 ; a < 9 ; a ++){
            // 9 FILAS --->
            for(short int b=0 ;b<9 ; b++){
                // ---> 9 COLUMNAS
                numero= 1 + rand()% 9 ;
                while (sdk->hacerJugada(a,b,numero) != true) {
                    numero= 1 + rand()% 9 ;
                     cout << "fila["<<a<<"] columna["<<b<<"] numero ["<<numero<<"]"<<endl;
                     //system("sleep 1");
                     maximoIntentos++;
                     if(maximoIntentos== 150){
                         delete sdk;
                         return false; // salida de la función!
                     }
                }
                cout<< "OK"<<endl;
            }
        }
    }
    sdk->mostrarSudoku();
    return true;
}

bool jugarSudoku(){
    int fila=0, columna=0 , numero=0;
    sudoku *sdk = new sudoku();
    while (sdk->jugadasRestantes()!=0) {
        sdk->mostrarSudoku();
        cout << "Numeros restantes ("<<sdk->jugadasRestantes()<<")"<<endl;
        cout << "fila    :"; cin >> fila;
        cout << "columna :"; cin >> columna;
        cout << "jugada  :"; cin >> numero;
        if(fila<=9 && fila>=1 && columna>=1 &&columna<=9  && numero>=1 && numero<=9){
            sdk->hacerJugada(fila-1,columna-1,numero);
        }
        else{
            system("clear");
            cout << "Alerta -> verifica que tu entrada sea valida "<<endl;
        }
    }
    cout << "JUEGO TERMINADO"<<endl;
    return true;
}

sudoku::sudoku(){
    // creacion de la matriz
    tablero = new int*[9];
    for(short int filas=0 ; filas < 9 ; filas ++){
        tablero[filas] = new int [9];
        for(short int columnas = 0 ; columnas <9 ; columnas ++){
            *(*(tablero+filas)+columnas)=0;
        }
    }
}

bool sudoku::hacerJugada(int fila, int columna, int numero){
    system("clear");

    for(int a=0;a<9;a++){
        // ciclo para buscar si existe el numero en algún lugar del tablero
        // y que coincida con la fila y la matríz
        //

        if(*(*(tablero+a)+columna)==numero){

            // comprobar si está en la columna )
            //out << " Alerta -> Ya Existe este numero en la columna "<<endl;
            return false;
        }

        if(*(*(tablero+fila)+a)==numero){
            // si está en la fila
            //cout << " Alerta -> Ya Existe este numero en la fila "<<endl;
            return false;
        }
        // definir el cuadrante en el que se está operando
        // esto nos permite verificar si existe además algún numero allí
        // que no esté permitido

        int cuadranteFila=(fila/3)*3;
        int cuadranteColumna=(columna/3)*3;
        for(int x=0 ; x<3 ; x++){
            for(int y=0;y<3;y++){
                // preguntaremos si por lo menos algún valor coincide con el numero que se intenta ingresar
                // de estar repetido en el cuadrante se prohibirá la operación
                if(*(*(tablero+(cuadranteFila+x))+(cuadranteColumna+y))==numero){
                    //cout << "Alerta -> Ya existe este numero en el cuadrante"<<endl;
                    return false;
                }
            }
        }

    }
    if(*(*(tablero+fila)+columna)==0){
        // si existia algún numero en esa casilla  se debe descontar puesto se trata de un cambio
        // de ese elemento particular
        //cout << "Msg -> Jugada realizada "<<endl;
        jugadas--;
    }
    else{
        // no se resta nada puesto no cambio los restantes en el tablero
        //cout << "Msg -> valor anterior reemplazado "<< endl;
    }
    *(*(tablero+fila)+columna) = numero;
    return true;
}

int  sudoku::jugadasRestantes(){
    return jugadas;
}
void sudoku::mostrarSudoku(){
    cout <<"  +--------------sudoku---------------+" <<endl;
    cout <<"  Instrucciones  "<<endl;
    cout <<"  Ingrese valores entre 1 a 9 para las :"<<endl;
    cout <<"  -Filas\n  -Columnas\n  -Jugada"<<endl;
    cout << endl;
    cout << "    ";
    for(short int a=1;a<=9;a++){
        cout <<" "<<a<<" ";
        if(a%3==0){
            cout <<"   ";
        }

    }
    cout << endl;
    cout <<"  +-----------------------------------+" <<endl;
    for(short int filas=0 ; filas < 9 ; filas ++){
        cout <<filas+1<<" | ";
        for(short int columnas=0; columnas< 9 ;columnas++){
            if(*(*(tablero+filas)+columnas) == 0){
             cout << " . ";
            }
            else{
                cout <<" "<< *(*(tablero+filas)+columnas)<<" " ;
            }
            if((columnas+1)%3==0){
                cout <<" | ";
            }
        }
        cout << endl;
        if((filas+1)%3==0){
            cout <<"  +-----------------------------------+" <<endl;
        }
    }
}
