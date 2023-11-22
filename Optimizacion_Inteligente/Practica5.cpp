/*
Universidad Autonoma de Aguascalientes
Centro de Ciencias de Basicas
Departamento de Ciencias de la Computacion
Materia: Optimización Inteligente
Alumno: Diego Alberto Aranda Gonzalez
Diego Emilio Moreno Sánchez
Profesor: Dr. en C. Luis Fernando Gutierrez Marfileño
Practica 5: Implementar un programa utilizando la metaheuristica de Sistema de Colonias de Hormigas
resuelva el problema de Job Shop.
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <ctime>

using namespace std;
//Estructura para almacenar los trabajos

struct Trabajo{
  int id;
  vector<int> tiempo; //Peso
};

//Funcion de evaluacion
double evaluar(vector<int> solucion, vector<Trabajo> Trabajo, vector<vector<double>> feromonas, vector<vector<double>> visibilidad, double alfa, double beta){
  double evaluacion = 0;
  for(int i = 0; i < solucion.size(); i++){
    evaluacion += (alfa * feromonas[i][solucion[i]]) + (beta * visibilidad[i][solucion[i]]);
  }
  return evaluacion;
}

//Funcion para crear soluciones
vector<int> crearSolucion(vector<Trabajo> Trabajo, vector<vector<double>> feromonas, vector<vector<double>> visibilidad, double alfa, double beta){
  vector<int> solucion;
  for(int i = 0; i < Trabajo.size(); i++){
    double max = 0;
    int pos = 0;
    for(int j = 0; j < Trabajo[i].tiempo.size(); j++){
      double evaluacion = (alfa * feromonas[i][j]) + (beta * visibilidad[i][j]);
      if(evaluacion > max){
        max = evaluacion;
        pos = j;
      }
    }
    solucion.push_back(pos);
  }
  return solucion;
}

//Funcion para actualizar feromonas
vector<vector<double>> actualizarFeromonas(vector<vector<double>> feromonas, vector<int> solucion, double rho, double Q){
  for(int i = 0; i < feromonas.size(); i++){
    for(int j = 0; j < feromonas[i].size(); j++){
      feromonas[i][j] = (1 - rho) * feromonas[i][j];
    }
  }
  for(int i = 0; i < solucion.size(); i++){
    feromonas[i][solucion[i]] += (Q / solucion.size());
  }
  return feromonas;
}

//Funcion Menu
void menu(){
  cout << "----Menu----" << endl;
  cout << "1.- Ejecutar programa" << endl;
  cout << "2.- Salir" << endl;
  cout << "Opcion: ";
}

int main(){
  int opcion;
  do{
    menu();
    cin >> opcion;
    if(opcion == 1){
        
        //Inicializamos los parametros
        int numTrabajos = 3;
        int numMaquinas = 3;

        vector<Trabajo> Trabajo{
          {1, {3, 3, 3}},
          {2, {2, 3, 4}},
          {3, {3, 3, 2}}
        };

        double alfa = 1; //Influencia en el rastro de feromonas
        double beta = 2; //Influencia en la heuristica
        int rho = 10; //Tasa de evaporacion
        int q = 1; //Feromona inicial
        int numAnts = 50; //Numero de hormigas
        bool bestSol = false; //Mejor solucion

        //Inicializamos las feromonas
        vector<vector<double>> feromonas(numTrabajos, vector<double>(numMaquinas, q));

        //Inicializamos la visibilidad
        vector<vector<double>> visibilidad(numTrabajos, vector<double>(numMaquinas, 1));

        //Empezamos el ciclo de hormigas
        for(int i = 0; i < numAnts; i++){
          vector<pair<vector<int>, double>> bestSoluciones;

          //Construimos soluciones y las evaluamos
          for(int j = 0; j < numAnts; j++){
            vector<int> solucion = crearSolucion(Trabajo, feromonas, visibilidad, alfa, beta);
            double tiempoF = evaluar(solucion, Trabajo, feromonas, visibilidad, alfa, beta);
            bestSoluciones.push_back(make_pair(solucion, tiempoF));
          }
          //Seleccionamos la mejor solucion
          sort(bestSoluciones.begin(), bestSoluciones.end(), [](const pair<vector<int>, double> &a, const pair<vector<int>, double> &b){
            return a.second < b.second;
          });
          bestSoluciones.resize(numAnts);

          //Actualizamos las feromonas
          actualizarFeromonas(feromonas, bestSoluciones[0].first, rho, q);

          //Evaporamos feromonas
          for(int i = 0; i < feromonas.size(); i++){
            for(int j = 0; j < feromonas[i].size(); j++){
              feromonas[i][j] = (1 - rho) * feromonas[i][j];
            }
          }

          //Seleccionamos la mejor solucion final
          if(!bestSol){
            bestSol = true;
            cout << "Mejor solucion: " << endl;
            for(int i = 0; i < bestSoluciones[0].first.size(); i++){
              cout << "Trabajo " << i + 1 << " en la maquina " << bestSoluciones[0].first[i] + 1 << endl;
            }
            cout << "Tiempo total: " << bestSoluciones[0].second << endl;
          }
          else{
            if(bestSoluciones[0].second < bestSoluciones[0].second){
              cout << "Mejor solucion: " << endl;
              for(int i = 0; i < bestSoluciones[0].first.size(); i++){
                cout << "Trabajo " << i + 1 << " en la maquina " << bestSoluciones[0].first[i] + 1 << endl;
              }
              cout << "Tiempo total: " << bestSoluciones[0].second << endl;
            }
          }      
        }
      }
      else if(opcion == 2){
        cout << "Saliendo..." << endl;
      }
      else{
        cout << "Opcion no valida" << endl;
      }
  }while(opcion != 2);
  return 0;
}