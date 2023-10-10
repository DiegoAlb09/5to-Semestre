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
#include <stdlib.h>

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
int enfriamiento(int t0, int a, int k) {
  return a * (t0 / (1 + k));
} 

// ejemplo poblacion inicial
// [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,...,25,1]

// funcion para generar la poblacion inicial
int* generarPoblacionInicial(){
  int poblacionInicial[26];
  // agregar el 0 al inicio
  poblacionInicial[0] = 1;
  // generar numeros aleatorios
  for (int i = 1; i < 25; i++) {
    poblacionInicial[i] = rand() % 25; 
  }
  // verificar que no se repitan los numeros

  // agregar el 0 al final
  poblacionInicial[26] = 1;
  return poblacionInicial;
}

// funcion para calcular el fitness de una solucion
int calcularFitness(int solucion[26], int ciudades[25][2]) {
  double fitness = 0;
  for (int i = 0; i < 26; i++) {
    // calcular la distancia entre las ciudades
    int distancia = calcularDistancia(ciudades[solucion[i]][0],ciudades[solucion[i]][1],ciudades[solucion[i+1]][0],ciudades[solucion[i+1]][1]);
    // sumar la distancia al fitness
    fitness += distancia;
  } 

  // promedio de fitness
  int realFitness = (int)(fitness / 26);

  return realFitness;
}

// funcion para generar una solucion vecina (mecanismo de caminada)
// esta funcion intercamia dos ciudades de la solucion anterior
int* mecanismoDeCaminada(int solucion[26]) {
  // generar dos numeros aleatorios
  int num1 = rand() % 25;
  int num2 = rand() % 25;
  // verificar que los numeros sean diferentes
  while (num1 == num2) {
    num2 = rand() % 25;
  }
  // intercambiar los numeros
  int aux = solucion[num1];
  solucion[num1] = solucion[num2];
  solucion[num2] = aux;
  return solucion;
}

//Funcion para mostrar solucion principal
void mostrarSolucion(int solucion[26]){
  for (int i = 0; i < 26; i++) {
    cout << solucion[i] << " ";
  }
  cout << endl;
}

int main(){
  int opcion;
  //arreglo de las coordenadas de las ciudades
  int ciudades[25][2] = {{5,4},{7,4},{5,6},{4,3},{2,4},{1,3},{1,5},{3,2},{6,3},{7,7},{6,1},
                         {4,1},{1,1},{1,7},{4,7},{7,2},{9,2},{8,5},{10,4},{11,1},{10,7},{13,6},{12,8}};
  //Temperatura Inicial
  int t0 = 1000;

  cout << "Iniciando ejecucion..." << endl;
  //Primera parte del algoritmo
  //Calculo de la distancia entre las ciudades
  int distancia;
  cout << "Primera Poblacion: " << endl;
  ////////////////////////////////////////////////////////////////////////////////
  int poblacionInicial[26];
  int num[24] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,
                 16,17,18,19,20,21,22,23,24,25};
  // agregar el 0 al inicio
  poblacionInicial[0] = 1;

  for (int i = 1; i < 25; i++) {
    // Seleccionar un numero aleatorio del arreglo num
    int numAleatorio = rand() % 24;
    // Asignar el numero aleatorio a la poblacion inicial, 
    // y eliminarlo del arreglo num, siempre y cuando no sea el 0
    while (num[numAleatorio] == 0) {
      numAleatorio = rand() % 24;
    }
    poblacionInicial[i] = num[numAleatorio];
    num[numAleatorio] = 0;
  }
  // agregar el 0 al final
  poblacionInicial[25] = 1;
  mostrarSolucion(poblacionInicial);
  
  int MAX_ITERACIONES = 2000;
  for (int i = 0; i < 2000; i++) {

    // Calculamos el fitness de la solucion actual
    int fitnessActual = calcularFitness(poblacionInicial, ciudades);
    cout << "Poblacion actual: " << endl;
    mostrarSolucion(poblacionInicial);
    cout << "Fitness actual: " << fitnessActual << endl;

    // Generamos una solucion vecina
    //////////////////////////////////////////////////////////////////////////////
    // crear una copia de la solucion actual
    int solucionVecina[26];
    for (int j = 0; j < 26; j++) {
      solucionVecina[j] = poblacionInicial[j];
    }
    // generar dos numeros aleatorios
    int num1 = rand() % 25;
    int num2 = rand() % 25;
    // verificar que los numeros sean diferentes
    while (num1 == num2) {
      num2 = rand() % 25;
    }
    // intercambiar los numeros
    int aux = solucionVecina[num1];
    solucionVecina[num1] = solucionVecina[num2];
    solucionVecina[num2] = aux;
    ////////////////////////////////////////////////////////////////////////////////

    // Calculamos el fitness de la solucion vecina
    int fitnessVecino = calcularFitness(solucionVecina, ciudades);
    cout << "Poblacion vecina: " << endl;
    mostrarSolucion(solucionVecina);
    cout << "Fitness vecino: " << fitnessVecino << endl;

    // Calculamos la diferencia de fitness
    int diferenciaFitness = fitnessVecino - fitnessActual;
    
    // Si la solucion vecina es mejor que la solucion actual
    if (diferenciaFitness > 0) {
      // La solucion vecina pasa a ser la solucion actual
      for (int j = 0; j < 26; j++) {
        poblacionInicial[j] = solucionVecina[j];
      }
    } else {
      // Si la solucion vecina es peor que la solucion actual
      // Generamos un numero aleatorio entre 0 y 1
      float numAleatorio = (float)rand() / RAND_MAX;
      // Calculamos la probabilidad de aceptacion
      float probabilidadAceptacion = exp(diferenciaFitness / t0);
      // Si el numero aleatorio es menor a la probabilidad de aceptacion
      if (numAleatorio <= probabilidadAceptacion) {
        // La solucion vecina pasa a ser la solucion actual
        for (int j = 0; j < 26; j++) {
          poblacionInicial[j] = solucionVecina[j];
        }
      }
    }

    // Reducimos la temperatura
    t0 = enfriamiento(t0, 0.8, i);

  }

  cout << "hola 2";

  return 0;
}
