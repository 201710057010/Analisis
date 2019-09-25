// Mathnalysis.cpp: define el punto de entrada de la aplicación.
//


#include "Mathnalysis.h"
#include "exceptions.h"
#include "PuntoFijo.h"
#include "raices_multiples.h"
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
		double x = raicesMultiples(f,g,g2,-3.2,11,0.0005,0);
		cout << x << endl;
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