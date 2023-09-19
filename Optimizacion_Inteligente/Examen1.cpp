/*
Universidad Autonoma de Aguascalientes
Centro de Ciencias Básicas
Departamento de Ciencias de la Computacion
Optimización Inteligente
Alumno: Diego Alberto Aranda Gonzalez ID 262021

Problema 1_Examen: Implementar un programa para obtener el valor minimo de 
la siguiente función por medio del metodo de Newton:
f(x) = 5x^2+3x-2 = 0
*/

#include <iostream>
#include <math.h>
#include <string>

using namespace std;

float fx(float x) {
  return 5*pow(x,2) + 3*x - 2;
}

float f1(float x) {
  return 10*x + 3;
}
float f2(float x){
	return 10;
}
void menu(){
  cout << "Programa que calcula el minimo de una funcion utilizando el metodo de Newton" << endl;
  cout << "f(x) = 5x^2+3x-2" << endl;
  cout << "1. Ejecutar el programa" << endl;
  cout << "2. Salir" << endl;
  cout << "Ingrese una opcion: ";
}

void tabla(int k, float xk, float fx, float f1, float f2){
  cout << "k|" << "xk|" << "f(x)|" << "f1(x)|" << "f2(x)|" << "xk+1" << endl;
  cout << "------------------------------------------------" << endl;
  cout << k << "|" << xk << "|" << fx << "|" << f1 << "|" << f2 << "|" << xk - (f1/f2) << endl;
  cout << endl;
}

int main (){

  int opcion;

  do {

    menu();
    cin >> opcion;

    if (opcion == 1) {
      cout << "Ejecutando el programa..." << endl;

      float x_0;
      cout << "Ingrese el valor de x_0 (De preferencia -0.9): ";
      cin >> x_0;

      float xk = x_0;
      float error = 0.0001;

      int k = 1; // numero de iteraciones
		
      while (abs(f1(xk)) > error) {
        float xk1 = xk - (f1(xk)/f2(xk));
        tabla(k, xk, fx(xk), f1(xk), f2(xk));
        xk = xk1;
        k++;
      }

      cout << endl;
      cout << "Función Original: " << "5x^2 + 3x - 2" << endl;
	  cout << "La Primera Derivada: " << "10x + 3" << endl;
	  cout << "La Segunda Derivada: " << "10" << endl;
	    
      cout << "------------------------------------------------" << endl;
      cout << "El valor de xk es: " << xk << endl;
      cout << "El minimo de la funcion es: " << fx(xk) << endl;
      cout << "------------------------------------------------" << endl;

      cout << endl;

    } else if (opcion == 2) {
      cout << "Saliendo del programa..." << endl;
      break;
    } else {
      cout << "Opcion no valida" << endl;
    }

  } while (opcion != 2);
  
  return 0;
}
