#include <stdio.h>
#include "PuntoFijo.h"
#include <cmath>
#include <iostream>
#include <cstring>
#include "exceptions.h"

using namespace std;

double puntoFijo(double (*func)(double), double(*gFunc)(double), double xa, int nIter, double tol, bool errorType) {

	double fx = func(xa);
	int count = 0;
	double error = tol + 1;
	double xn = 0;

	cout << " | " << "iter" << "  |  " << "Xn" << "  |  " << "f(Xn)" << "  |  " << "Error" << "  |" << endl;

	if (fx == 0) {
		return fx;
	}
	else {
		while (fx != 0 && error > tol && count < nIter) {
			xn = gFunc(xa);
			fx = func(xn);
			error = ((errorType == false) ? fabs(xn - xa) : fabs((xn - xa) / xn));
			xa = xn;
			count++;
			cout << " | " << count << "  |  " << xn << "  |  " << fx << "  |  " << error << "  |" << endl;
		}
		if (fx == 0) {
			return xa;
		}
		else if (error < tol) {
			return xa;
		}
		else {
			throw TooMuchIterException();
		}
	}
}