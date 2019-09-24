#pragma once

/**
* Funcion que intenta encontrar la raiz de una funcion usando el metodo de punto fijo
* Argumentos: func : apuntador a una función
			  gFunc: apuntador a la funcion g
			  xa : valor inicial del metodo
			  nIter: numero maximo de iteraciones
			  tol: tolerancia
			  errorType: tipo de error, 0 si es absoluto, 1 si es relativo
* Retorna: una raiz o una aproximacion a una raiz
*/

double puntoFijo(double (*func)(double), double(*gFunc)(double), double xa, int nIter, double tol, bool errorType);