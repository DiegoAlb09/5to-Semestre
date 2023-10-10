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
int calcularDistancia(int ciudad1x, int ciudad1y, int ciudad2x, int ciudad2y){
  return sqrt(pow((ciudad1x-ciudad2x),2)+pow((ciudad1y-ciudad2y),2));
}

//funcion de enfriamiento
int enfriamiento(int t0,int a, int k){
  return a*(t0/(1+k));
}

int main(){
  int opcion;
  //arreglo de las coordenadas de las ciudades
  int ciudades[25][2] = {{5,4},{7,4},{5,6},{4,3},{2,4},{1,3},{1,5},{3,2},{6,3},{7,7},{6,1},
                         {4,1},{1,1},{1,7},{4,7},{7,2},{9,2},{8,5},{10,4},{11,1},{10,7},{13,6},{12,8}};
  //Temperatura Inicial
  int t0 = 1000;

  do{
    menu();
    cin >> opcion;
    switch(opcion){
      case 1:
        cout << "Iniciando ejecucion..." << endl;
        //Calculo de la distancia entre las ciudades
        int distancia;
        distancia = calcularDistancia(ciudades[0][0],ciudades[0][1],ciudades[1][0],ciudades[1][1]);
        cout << "Distancia entre las ciudades 1 y 2: " << distancia << endl;
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
