#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;


void biseccion(double (*func)(double),double a, double b, double tol, int niter) {
	double y0 = func(a);
	double y1 = func(b);
	cout << fixed;
	cout.precision(7);
	if (tol < 0) {
		cout << "tolerancia no valida" << endl;
	}
	else if (niter <= 0) {
		cout << "numero de iteraciones no valida" << endl;
	}
	else if (y0 == 0) {
		cout << "a is root" << endl;
	}
	else if (y1 == 0) {
		cout << "b is a root" << endl;
	}
	else if (y0 * y1 < 0) {
		cout << "|  niter  |   a  |  b  |   xm  |  fxm  | error |" << endl;
		double xm = (a + b) / 2;
		double ym = func(xm);
		int cont = 1;
		double error = tol + 1;
		cout << "|   " << cont << "   |" << a << "|" << b << "|" << xm << "|" << ym << "|" << " " << "|" << endl;
		while ((ym != 0) && (error > tol) && (cont < niter)) {
			if (ym * y1 < 0) {
				a = xm;
				y0 = ym;
			}
			else {
				b = xm;
				y1 = ym;
			}
			double aux = xm;
			xm = (a + b) / 2;
			ym = func(xm);
			cont++;
			error = abs(xm - aux);
			cout << "|   " << cont << "  |" << a << "|" << b << "|" << xm << "|" << ym << "|" << error << "|" << endl;
		}

		if (ym == 0) {
			cout << "xm es una raiz" << endl;
		}
		else if (error < tol) {
			cout << "xm es una aproximacion a una raiz con una tolerancia = " << tol << endl;

		}
		else {
			cout << "fracaso en el numero de iteracciones" << endl;
		}

	}
	else {
		cout << "fracaso" << endl;
	}
}
