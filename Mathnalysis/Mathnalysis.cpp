// Mathnalysis.cpp: define el punto de entrada de la aplicación.
//


#include "Mathnalysis.h"
#include "exceptions.h"
#include "EcuacionesUnaVariable\PuntoFijo.h"
#include "EcuacionesUnaVariable\raices_multiples.h"
#include "EcuacionesUnaVariable\biseccion.h"
#include "EcuacionesUnaVariable\busqueda_incrementa.h"
#include "EcuacionesUnaVariable\newton.h"
#include "EcuacionesUnaVariable\reglaFalsa.h"
#include "EcuacionesUnaVariable\secante.h"
#include "VariasVariables\gaussSeidel.h"
#include "VariasVariables\crout.h"
#include <math.h>
#include <stdio.h>
#include <iostream>

double f(double x);
double g(double x);

using namespace std;


		//double x = puntoFijo(f, g, -0.5, 11, 0.0005, 0);
		//double x = raicesMultiples(f,g,g2,-3.2,11,0.0005,0);
		//vector<vector<double> > A = { {20,-1,3,4} , {6,23,4,3} , {7,21,46,9} , {-3,-9,12,38}};
		//vector<double> b = { 30,-10,20,-14 };
		//vector<double> c = { 0,0,0,0 };
		//metodoGaussSeidel(c,A,b);

int main()
{
	
	int a,nIter;
	double xa, tol, xb, delta, respuesta;
	bool errorType;
	a = -1;
	while(a != 0){
		try{	
			cin >> a;
			switch (a)
			{
			case 1:
				cin >> nIter;
				cout << nIter << endl;
				break;
			case 2:
				cin >> xa;
				cout << xa << endl;
				break;
			case 3:
				cin >> xb;
				cout << xb << endl;
				break;
			case 4:
				cin >> tol;
				cout << tol << endl;
				break;
			case 5:
			    cin >> delta;
				cout << delta << endl;
				break;
			case 6:
			    cin >> errorType;
				cout << errorType << endl;
				break;
			case 7: 
				respuesta = puntoFijo(f,g,xa,nIter,tol,errorType);
				cout << respuesta << endl;
				break;
			case 8:
				respuesta = raicesMultiples(f, g, g2, xa,nIter, tol, errorType);
				cout << respuesta << endl;
			case 9:
				biseccion(f,xa, xb, tol, nIter);
			case 10: 
				busqueda_incremental(f,xa, delta, nIter);
			case 11:
				newton(f, g, xa, tol, nIter);
			case 12:
				reglaFalsa(f, xa,  xb, tol, nIter);
			case 13:
				secante(f, tol, xa, xb, nIter);
			}
		}catch(exception e){
		cout << e.what() << endl;
		}
	}
	return 0;
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