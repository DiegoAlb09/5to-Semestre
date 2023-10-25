/*
Universidad Autonoma de Aguascalientes
Centro de Ciencias Basicas
Departamento de Ciencias Computacionales
Optimizacion Inteligente 
Alumno: Diego Alberto Aranda Gonzalez ID 262021
Profesor: Dr. en C. Luis Fernando Gutierrez Marfileno
Problema 1: Implementar un algoritmo genetico para colocar 8 torres de ajedrez de manera que no se ataquen entre si.
*/

#include <iostream>
#include <algorithm>

using namespace std;

//Funcion para generar la poblacion de 50 individuos
void generarPbIncial(int generacion[50][8]){
    //Generar numeros aleatorios entre 0 y 7
    for(int i=0; i<50; i++){
        for(int j=0; j<8; j++){
            generacion[i][j] = rand() % 8;
        }
    }
}

//Mostramos solo el primer individuo de la poblacion
void mostrarPbInicial(int generacion[50][8]){
    for(int i=0; i<1; i++){
        for(int j=0; j<8; j++){
            cout << generacion[i][j] << " ";
        }
        cout << i;
        cout << endl;
    }
}

//Calculamos el fitness de la poblacion
int calcularFitness(int individuo[8]){
  int fitness = 0;
  //tablero inicializado con -1's
  int tablero[8][8];
  for (int i = 0; i < 8; i++){
    for (int j = 0; i < 8; i++){
      tablero[i][j] = -1;
    }
  }

  //Recorremos el individuo
  for (int i = 0; i < 8; i++){
    //Incremetamos en 1 las filas y columnas donde se encuentran las torres
    for (int j = 0; j < 8; j++){
      tablero[i][j]++;
      tablero[j][individuo[i]]++;
    }
  }
  //Recorremos todo el tablero y sumamos los unos que se encuentren 
  //en las filas y columnas donde se encuentran las torres
  for (int i = 0; i < 8; i++){
    fitness += tablero[i][individuo[i]];
  }

  if(fitness >= 8){
    cout << "Solucion encontrada" << endl;
    //Mostramos la solucion
    for (int i = 0; i < 8; i++){
      cout << individuo[i] << " ";
    }
    cout << endl;
  }

  return fitness;
}

//Funcion para seleccionar padres
void seleccionarPadres(int generacion[50][8], int fitness[50], int padres[10][8]){
  //Ordenamos la poblacion de menor a mayor
  for (int i = 0; i < 50; i++){
    for (int j = 0; j < 50; j++){
      if(fitness[i] < fitness[j]){
        swap(fitness[i], fitness[j]);
        swap(generacion[i], generacion[j]);
      }
    }
  }
  //Seleccionamos los 10 mejores padres
  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 8; j++){
      padres[i][j] = generacion[i][j];
    }
  }
}

//Cruzamiento
void cruzarPadre(int padres[10][8], int newGen[50][8]){
  for (int j = 0; j < 50; j+=2){
    int padre1 = rand() % 10;
    int padre2 = rand() % 10;

    //Punto de cruce
    int puntCruce = rand() % 8;

    //Generamos los hijos
    int hijo1[8];
    int hijo2[8];

    //Copiamos los genes de los padres a los hijos
    for (int i = 0; i < 8; i++){
      hijo1[i] = padres[padre1][i];
      hijo2[i] = padres[padre2][i];
    }

    //Cruzar los genes de los padres en el punto de cruce
    for (int i = puntCruce; i < 8; i++){
      hijo1[i] = padres[padre2][i];
      hijo2[i] = padres[padre1][i];
    }

    for (int i = 0; i < 8; i++){
      newGen[j][i] = hijo1[i];
      newGen[j+1][i] = hijo2[i];
    }
  }
}

//Mutacion
void mutarGen(int generacion[50][8]){
  for (int i = 0; i < 50; i++){
    int individuo = rand() % 50;
    int gen = rand() % 8;
    generacion[individuo][gen] = rand() % 8;
  }
}


void menu(){
  cout << "Problema de las 8 torres en el tablero" << endl;
  cout << "Ejecutar codigo" << endl;
  cout << "Salir" << endl;
  cout << "Ingrese una opcion: ";
}

int main(){
  int opcion;
  do{
    menu();
    cin >> opcion;
    switch(opcion){
      case 1:{
        int generacion[50][8];
        int fitness[50];

        //Generamos la poblacion inicial
        generarPbIncial(generacion);
        
        //Mostramos
        mostrarPbInicial(generacion);
        
        //Calculamos el fitness de la poblacion
        int fitnessAcumulado;
        for (int i = 0; i < 50; i++){
          fitness[i] = calcularFitness(generacion[i]);
          fitnessAcumulado += fitness[i];
        }
        cout << "Puntuacion de generacion: "<< fitnessAcumulado << endl;

        for (int i = 0; i < 50; i++){
          int padres[10][8];

          seleccionarPadres(generacion, fitness, padres);
          
          cruzarPadre(padres, generacion);
          
          mutarGen(generacion);

          int fitnessAcumulado = 0;
          for (int i = 0; i < 50; i++){
            fitness[i] = calcularFitness(generacion[i]);
            fitnessAcumulado += fitness[i];
            if(fitness[i] >= 8){
              break;
            }
          }
          mostrarPbInicial(generacion);
          cout << "Puntuacion de generacion: "<< fitnessAcumulado << endl;
        }
        break;
      }
      case 2:{
        cout << "Saliendo..." << endl;
        break;
      }
      default:{
        cout << "Opcion no valida" << endl;
        break;
      }
    }
  }while(opcion != 2);
  return 0;
}
