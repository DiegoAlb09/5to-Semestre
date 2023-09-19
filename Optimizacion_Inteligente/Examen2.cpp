/*
Universidad Autonoma de Aguascalientes
Centro de Ciencias Básicas
Departamento de Ciencias de la Computacion
Optimización Inteligente
Alumno: Diego Alberto Aranda Gonzalez ID 262021

Practica 2: Minimizar la siguiente funcion utilizando el Metodo de Busqueda Aleatoria
f(x) = -(1+cos(12sqtr(x1^2 + x2^2)))/(0.5(x1^2+x2^2)+2)
*/
#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;

double random(double min, double max){
  return (double)rand() / RAND_MAX * (max - min) + min;
}

double f(double x1, double x2) {
  return -1*(1 + cos(12*sqrt(pow(x1,2) + pow(x2,2))))/(0.5*(pow(x1,2)+pow(x2,2))+2);
}

void menu() {
  cout << "Programa que calcula el minimo de la funcion f(x) = -(1+cos(12sqtr(x1^2 + x2^2)))/(0.5(x1^2+x2^2)+2) por el metodo de busqueda aleatoria" << endl;
  cout << "1. Calular el minimo" << endl;
  cout << "2. Salir" << endl;
  cout << "Ingrese una opcion: ";
}

void tabla(int i, double x_1, double x_2, double fx, double min_actual){
  cout << "No.Iteracion  " << " x1 " << " x2 " << " f(x) " << " Min Actual "<< endl;
  cout << "-----------------------------------------" << endl;
  cout << i << "  " << x_1 << "  " << x_2 << "  " << fx << "  " << min_actual << endl;
  cout << endl;
}
int main() {
  int opcion;
  do {
    menu();
    cin >> opcion;
    if (opcion == 1) {
      double x_1 = random(-5.12, 5.12);
      double x_2 = random(-5.12, 5.12);
      double fx = f(x_1, x_2);
      double min_actual = fx;
      tabla(0, x_1, x_2, fx, min_actual);
      double xi = 0;
      double yi = 0;
      double fx1 = 0;
      for (int i = 0; i < 10000; i++) {
        xi = random(-5.12, 5.12);
        yi = random(-5.12, 5.12);
        fx1 = f(xi, yi);
        tabla(i, xi, yi, fx1, min_actual);
        if (fx1 < fx) {
          x_1 = xi;
          x_2 = yi;
          fx = fx1;
        }
        if (fx < min_actual) {
          min_actual = fx;
        }
      }
      cout << "El minimo de la funcion es: " << fx << endl;
      cout << "Con x_1 = " << x_1 << " y x_2 = " << x_2 << endl;
      cout << endl;
    } else if (opcion == 2) {
      cout << "Saliendo del programa..." << endl;
    } else {
      cout << "Opcion no valida" << endl;
    }
  } while (opcion != 2);
  return 0;
}
