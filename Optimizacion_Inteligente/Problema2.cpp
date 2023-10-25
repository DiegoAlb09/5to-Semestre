/*
Universidad Autonoma de Aguascalientes
Centro de Ciencias Basicas
Departamento de Ciencias Computacionales
Optimizacion Inteligente
Alumno: Diego Alberto Aranda Gonzalez ID 262021
Profesor: Dr. en C. Luis Fernando Gutierrez Marfileno
Problema 2: Implementar el recocido simulado para generar una matriz que minimice el tiempo de operacion de todos los trabajos
*/

#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

void menu(){
  cout << "Problema 2"<<endl;
  cout << "Iniciar programa"<< endl;
  cout << "Salir"<< endl;
  cout << "Ingrese una opcion: ";
}

//Generar una poblacion inicial
void poblacionIncial(int pbIncial1[12]){
  for(int i=0; i<12; i++){
    pbIncial1[i] = rand() % 4;
  }
}

void poblacionVecina(int pbIncial1[12], int pbVecina[12]){
  //Se genera apartir del intercambio aleatorio de dos elementos de la poblacion inicial
  int pos1 = rand() % 12;
  int pos2 = rand() % 12;
  int aux = pbIncial1[pos1];
  pbIncial1[pos1] = pbIncial1[pos2];
  pbIncial1[pos2] = aux;
  for(int i=0; i<12; i++){
    pbVecina[i] = pbIncial1[i];
  }
}

int main(){
  int opcion;
  do{
    menu();
    cin >> opcion;
    switch(opcion){
      case 1:
        //Iniciar programa
        int pbIncial1[12];
        int pbVecina[12];
        poblacionIncial(pbIncial1);
        for(int i=0; i < 12; i++){
          cout << pbIncial1[i] << " ";
        }
        cout << endl;
        poblacionVecina(pbIncial1, pbVecina);
        for (int i = 0; i < 12; i++){
          cout << pbVecina[i] << " ";
        }
        cout << endl;
        
        break;
      case 2:
        //Salir
        break;
      default:
        cout << "Opcion invalida" << endl;
        break;
    }
  }while(opcion != 2);
  return 0;
}
