// Mathnalysis.cpp: define el punto de entrada de la aplicación.
//


#include "Mathnalysis.h"
#include "exceptions.h"
#include "PuntoFijo.h"
#include <math.h>
#include <stdio.h>
#include <iostream>

double f(double x);
double g(double x);

using namespace std;

int main()
{
	try {
		double x = puntoFijo(f, g, -0.5, 11, 0.0005, 0);
		cout << x << endl;
	}
	catch (exception e) {
		cout << "gg" << endl;
	}
}

double f(double x) {
	return x * exp(x) - pow(x, 2) - 5 * x - 3;
}

double g(double x) {
	return (x * exp(x) - pow(x, 2) - 3) / 5;
}
