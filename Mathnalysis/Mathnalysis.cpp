// Mathnalysis.cpp: define el punto de entrada de la aplicación.
//


#include "Mathnalysis.h"
#include "exceptions.h"
#include "PuntoFijo.h"
#include "raices_multiples.h"
#include "biseccion.h"
#include "busqueda_incrementa.h"
#include "newton.h"
#include "reglaFalsa.h"
#include "secante.h"
#include "gaussSeidel.h"
#include "crout.h"
#include <math.h>
#include <stdio.h>
#include <iostream>

double f(double x);
double g(double x);

using namespace std;

int main()
{
	try {
		//double x = puntoFijo(f, g, -0.5, 11, 0.0005, 0);
		//double x = raicesMultiples(f,g,g2,-3.2,11,0.0005,0);
		vector<vector<double> > A = { {20,-1,3,4} , {6,23,4,3} , {7,21,46,9} , {-3,-9,12,38}};
		vector<double> b = { 30,-10,20,-14 };
		vector<double> c = { 0,0,0,0 };
		metodoGaussSeidel(c,A,b);
	}
	catch (exception e) {
		cout << "gg" << endl;
	}
}

double f(double x) {
	return pow(x, 4) - 18 * pow(x, 2) + 80;
}

double g(double x) {
	return 4 * pow(x, 3) - 36 * x;
}

double g2(double x) {
	return 12 * pow(x, 2) - 36;
}