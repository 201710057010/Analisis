#include <stdio.h>

#include <cmath>
#include <iostream>
#include<iomanip>
#include <cstring>
#include "raices_multiples.h"
#include "exceptions.h"

using namespace std;

double raicesMultiples(double (*func)(double), double(*dfunc)(double), double(*d2Func)(double), double x0, int nIter, double tol, bool errorType) {
	double error;
	double x1, x2;
	double fx, dfx, d2fx;
	int count;

	fx = func(x0);
	dfx = dfunc(x0);
	d2fx = d2Func(x0);
	x2 = pow(dfx, 2) - fx * d2fx;
	error = tol + 1;
	count = 0;


	cout << " | " << "iter" << "  |  " << "Xn" << "  |  " << "f(Xn)" << "  |  " << "f'(Xn)" << "  |  " << "f''(Xn)" << "  |  " << "Error" << "  |" << endl;

	if (fx == 0) {
		cout << x0 << " is a root" << endl;
		return x0;
	}

	while (error > tol && fx != 0 && x2 != 0 && count < nIter) {
		x1 = x0 - ((fx * dfx) / x2);
		fx = func(x1);
		dfx = dfunc(x1);
		d2fx = d2Func(x1);
		error = (errorType == false) ? fabs(x1 - x0) : fabs((x1 - x0) / x1);
		count++;
		x0 = x1;
		cout << " | " << count << " | " << x1 << " | " << fx << " | " << dfx << " | " << d2fx << " | " << error << " |" << endl;
	}

	if (fx == 0){
		return x0;
	}
	else if (error < tol) {
		return x1;
	}
	else if (x2 == 0) {
		throw div0Exception();
	}
	else {
		throw TooMuchIterException();
	}
}