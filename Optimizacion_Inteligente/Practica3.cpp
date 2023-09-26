/*
Universidad Autonoma de Aguascalientes
Centro de Ciencias Basicas
Departamento de Ciencias de la Computacion
Optimizacion Inteligente
Diego Alberto Aranda Gonzalez (ID 262021)
Diego Emilio Moreno Sánchez (ID 264776)
Profesor: Dr. en C. Luis Fernando Gutiérrez Marfileño

Practica 3: Implementar un programa que utilizando la metaheuristica de algoritmos
geneticos para resolver el problema de las 8 reinas.
*/
#include <iostream>
#include <algorithm>

using namespace std;


// Funcion para generar numeros aleatorias
void generarPoblacionInicial (int generacion[50][8]) {
  // Generar numeros aleatorios entre 0 y 7
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 8; j++) {
      generacion[i][j] = rand() % 8;
    }
  }
}
  
// Funcion para mostrar la poblacion
void mostrarGeneracion(int generacion[50][8]) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 8; j++) {
      cout << generacion[i][j] << " ";
    }
    cout << endl;
  }
}

int calcularFitness(int individuo[8]) {
  
  int fitness = 0;

  // tablero inicializado con -1's
  int tablero[8][8];
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      tablero[i][j] = -1;
    }
  }

  // Recorrer el individuo
  for (int i = 0; i < 8; i++) {
    // Vamos a incrementar en uno las toda la fila
    // y toda la columna de la posicion de la reina
    // en el tablero
    for (int j = 0; j < 8; j++) {
      tablero[i][j]++;
      tablero[j][individuo[i]]++;
    }

    // Vamos a incrementar en uno las diagonales
    // de la posicion de la reina en el tablero

    // Diagonal superior derecha
    int k = i;
    int l = individuo[i];
    while (k >= 0 && l < 8) {
      if (k != i && l != individuo[i]) {
        tablero[k][l]++;
      }
      k--;
      l++;
    }

    // Diagonal superior izquierda
    k = i;
    l = individuo[i];
    while (k >= 0 && l >= 0) {
      if (k != i && l != individuo[i]) {
        tablero[k][l]++;
      }
      k--;
      l--;
    }


    // Diagonal inferior derecha
    k = i;
    l = individuo[i];
    while (k < 8 && l < 8) {
      if (k != i && l != individuo[i]) {
        tablero[k][l]++;
      }
      k++;
      l++;
    }

    // Diagonal inferior izquierda
    k = i;
    l = individuo[i];
    while (k < 8 && l >= 0) {
      if (k != i && l != individuo[i]) {
        tablero[k][l]++;
      }
      k++;
      l--;
    }
  }

  // Recorrer el tablero y sumar  los valores de 
  // las posiciones de las reinas 
  for (int i = 0; i < 8; i++) {
    fitness += tablero[i][individuo[i]]; 
  }

  if (fitness == 8) {
    cout << "Solucion encontrada" << endl;
    // mostrar individuo
    for (int i = 0; i < 8; i++) {
      cout << individuo[i] << " ";
    }          
    cout << endl;
  }
  return fitness;
}


void seleccionarPadres(int generacion[50][8], int fitness[50], int padres[25][8]) {
  // Ordenar los individuos de menor a mayor fitness
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 50; j++) {
      if (fitness[i] < fitness[j]) {
        swap(fitness[i], fitness[j]);
        swap(generacion[i], generacion[j]);
      }
    }
  }
  // Mostrar los 25 individuos con menor fitness con su fitness
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 8; j++) {
      // cout << generacion[i][j] << " ";
      padres[i][j] = generacion[i][j];
    }
    // cout << fitness[i] << " ";
    // cout << i;
    // cout << endl;
  }
}

void cruzarPadres(int padres[50][8], int nuevaGeneracion[50][8]) {

  for (int j = 0; j < 50; j += 2) {
    // Seleccionar dos padres aleatorios
    int padre1 = rand() % 25;
    int padre2 = rand() % 25;

    // Seleccionar un punto de cruce aleatorio
    int puntoCruce = rand() % 8;

    // Crear dos hijos
    int hijo1[8];
    int hijo2[8];

    // Copiar los genes de los padres a los hijos
    for (int i = 0; i < 8; i++) {
      hijo1[i] = padres[padre1][i];
      hijo2[i] = padres[padre2][i];
    }

    // Cruzar los genes de los padres en el punto de cruce
    for (int i = puntoCruce; i < 8; i++) {
      hijo1[i] = padres[padre2][i];
      hijo2[i] = padres[padre1][i];
    }

    // Agregar los hijos a la nueva generacion
    for (int i = 0; i < 8; i++) {
      nuevaGeneracion[j][i] = hijo1[i];
      nuevaGeneracion[j+1][i] = hijo2[i];
    }
  }
}

void mutarGeneracion(int generacion[50][8]) {
  for (int i = 0; i < 50; i++) {
    // Seleccionar un individuo aleatorio
    int individuo = rand() % 50;

    // Seleccionar un gen aleatorio
    int gen = rand() % 8;

    // Cambiar el valor del gen
    generacion[individuo][gen] = rand() % 8;
  }
}

void menu() {
  cout << "Programa que encuentra una solucion para el problema de las 8 reinas por medio de Algortimo Genetico" << endl;
  cout << "1. Iniciar Ejecucion" << endl;
  cout << "2. Salir" << endl;
  cout << "Ingrese una opcion: ";
}


int main() {
  
  int opcion;
  do {
    menu();
    cin >> opcion;

    if (opcion == 1) {

      // Ejecutar algoritmo genetico
      int generacion[50][8]; // -> 50 individuos de 8 genes cada uno
      int fitness[50];

      // 1. Generar poblacion inicial
      generarPoblacionInicial(generacion);
      cout << "Primera generacion" << endl;
      //Mostrar solo los primeros 5 individuos
      mostrarGeneracion(generacion);
      
      // 2. Calcular fitness de cada individuo
      int fitness_acum;
      for (int i = 0; i < 50; i++) {
        fitness[i] = calcularFitness(generacion[i]);
        fitness_acum += fitness[i];
      }
	  cout << "Puntuacion de la 1era generacion: " << fitness_acum << endl;

      for (int i = 0; i < 50; i++) {

        // 3. Seleccionar a los padres
        // Se deben seleccionar los 25 individuos con un menor fitness
        int padres[50][8];
        seleccionarPadres(generacion, fitness, padres);

        // 4. Cruzar los padres y agregar los hijos a una nueva generacion
        cruzarPadres(padres, generacion);

        // 5. Mutar generacion
        mutarGeneracion(generacion);

        // 6. Evaluar la poblacion
        int fitness_acum = 0;
        for (int i = 0; i < 50; i++) {
          fitness[i] = calcularFitness(generacion[i]);
          fitness_acum += fitness[i];
        }
        if (fitness[i] == 8){
          	break;
		}
        cout << "Puntuacion generacion: " << fitness_acum << endl;
	  }
		cout << endl;
    } 
    else if (opcion == 2) {
      cout << "Saliendo del programa..." << endl;
    }
    else {
      cout << "Opcion invalida" << endl;
    }
  } while (opcion != 2);
  return 0;
}
