/*
Universidad Autonoma de Aguascalientes
Centro de Ciencias Basicas
Departamento de Ciencias Computacionales
Optimizacion Inteligente
Diego Alberto Aranda Gonzalez (ID 262021)
Diego Emilio Moreno Sánchez (ID 264776)
Profesor: Dr. en C. Luis Fernando Gutiérrez Marfileño
Practica 4: Implementar un programa que utilizando la metaheuristica de Recocido Simulado
resuelva el problema del Agente Viajero.
*/

#include <iostream>
#include <math.h>

using namespace std;

void menu(){
  cout << "Programa que resuelve el problema del Agente Viajero utilizando la metaheuristica de Recocido Simulado" << endl;
  cout << "1. Iniciar Ejecucion" << endl;
  cout << "2. Salir" << endl;
  cout << "Ingrese una opcion: ";
}

//Funcion para calcular la distancia entre las ciudades
int distancia(int distancias[8][14],int ciudad1,int ciudad2){
  for(int i = 0 ; i < 8 ; i++){
    for(int j = 0 ; j < 14 ; j++){
      if(i == ciudad1 && j == ciudad2){
        return distancias[i][j];
      }
    }
  }
}

//funcion de enfriamiento
int enfriamiento(int t0,int a, int k){
  return a*(t0/(1+k));
}

int main(){
  int opcion;
  //Matriz de distancias
  int distancias[8][14] ={
                      {0,0,0,0,0,0,0,0,0,0,0,25,0,0},
                      {16,0,0,17,0,0,12,0,0,23,0,0,0},
                      {0,0,5,0,3,0,0,0,0,0,0,0,24,0},
                      {9,0,0,6,0,0,0,20,0,0,0,0,0,0},
                      {0,7,0,0,1,0,2,0,0,21,0,0,0,0},
                      {8,0,0,4,0,11,0,0,0,0,0,0,0,0},
                      {0,0,10,0,0,0,18,0,19,0,0,0,0,0},
                      {15,0,0,14,0,13,0,0,0,0,22,0,0,0}
                      };
  //Temperatura Inicial
  int t0 = 1000;

  do{
    menu();
    cin >> opcion;
    switch(opcion){
      case 1:
        cout << "Iniciando ejecucion..." << endl;
        distancia(distancias,0,12);
        //Temperatura actual
        for (int i = 0; i < 2000;i++){
          int tK = enfriamiento(t0,0.8,i);
        }
        break;
      case 2:
        cout << "Saliendo..." << endl;
        break;
      default:
        cout << "Opcion no valida" << endl;
        break;
    }
  }while(opcion != 2);
  return 0;
}
