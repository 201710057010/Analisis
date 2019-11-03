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
#include "VariasVariables\doolittle.h"
#include "VariasVariables\EGS.h"
#include "VariasVariables\jacobi.h"
#include "VariasVariables\PivTotal.h"
#include "VariasVariables\PivParcial.h"
#include "VariasVariables\Cholesky.h"
#include <math.h>
#include <stdio.h>
#include <iostream>

double f(double x);
double g(double x);

using namespace std;


		//double x = puntoFijo(f, g, -0.5, 11, 0.0005, 0);
		//double x = raicesMultiples(f,g,g2,-3.2,11,0.0005,0);
		//
		//
		//
		//metodoGaussSeidel(c,A,b);

int main()
{
	vector<vector<double> > A = { {34,-5,6,12} , {-9,43,21,-8} , {-12,4,75,22} , {7,5,-13,65}};
	vector<double> b = { 37,123,16,9 };
	vector<double> c = { 0,0,0,0 };
	int a,nIter, n, k;
	double xa, tol, xb, delta, respuesta;
	bool errorType;
	a = -1;
	vector<double> x;
	vector<vector<double>> ab;
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
				break;
			case 9:
				biseccion(f,xa, xb, tol, nIter);
				break;
			case 10: 
				busqueda_incremental(f,xa, delta, nIter);
				break;
			case 11:
				newton(f, g, xa, tol, nIter);
				break;
			case 12:
				reglaFalsa(f, xa,  xb, tol, nIter);
				break;
			case 13:
				secante(f, tol, xa, xb, nIter);
				break;
			case 14:
				metodoGaussSeidel(c, A, b);
				break;
			case 15:
				metodoCrout( A, b);				
				break;
			case 16:
			  	x = doolittle(A, b);
			  	for(int i = 0; i <4; i++){
			    	cout << "x" << i << "= " << x[i] << endl;
			  	}
				break;
			case 17:
			    ab = gausianaSimple(A, b, 4);
				x = sustitucionBackwardEg(ab,4);
				for(int i = 0; i< 4; i++){
				  cout << "x"<< i << "= " << x[i] << endl; 
				}
				break;
			case 18:
			    jacobi(tol, nIter, c, A, b);
				break;
			case 19:
			  	x = EliminacionGauss(A, b, 4);
			  	for(int i = 0; i <4; i++){
			    	cout << "x" << i << "= " << x[i] << endl;
			  	}
				break;
		    case 20:
				x = EliminacionGaussPivT(A, b, 4);
			  	for(int i = 0; i < 4; i++){
			  	  cout << "x" << i << "= " << x[i] << endl;
			  	}
				break;
			case 21:
				x = metodoCholesky(A, b);
			  	for(int i = 0; i <4; i++){
			    	cout << "x" << i << "= " << x[i] << endl;
			  	}
				break;
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
