// Mathnalysis.cpp: define el punto de entrada de la aplicación.
//


#include "Mathnalysis.h"
//#include "exceptions.h"
#include "EcuacionesUnaVariable/PuntoFijo.h"
#include "EcuacionesUnaVariable/raices_multiples.h"
#include "EcuacionesUnaVariable/biseccion.h"
#include "EcuacionesUnaVariable/busqueda_incrementa.h"
#include "EcuacionesUnaVariable/newton.h"
#include "EcuacionesUnaVariable/reglaFalsa.h"
#include "EcuacionesUnaVariable/secante.h"
#include "VariasVariables/gaussSeidel.h"
#include "VariasVariables/crout.h"
#include "VariasVariables/doolittle.h"
#include "VariasVariables/EGS.h"
#include "VariasVariables/jacobi.h"
#include "VariasVariables/PivTotal.h"
#include "VariasVariables/PivParcial.h"
#include "VariasVariables/Cholesky.h"
#include "analizador/analizer.h"
#include "interpolacion/diferenciasdivididas.h"
#include "interpolacion/InterpolacionCubica.h"
#include "interpolacion/InterpolacionLineal.h"
#include "interpolacion/lagrange.h"
#include "interpolacion/splineCuadratico.h"
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

double f2(double x);
double f(double x);
double g2(double x);
int a,nIter,n,k, var,puntoInicial;
double xa, tol, xb, delta, respuesta;
bool errorType;
vector<double> x;
vector<vector<double> > A;
vector<double> b;
vector<double> c;
vector<vector<double> > ab;
string funcionf,funciong,funcionf2;
vector <double> puntosx;
vector <double> puntosy;


using namespace std;


		//double x = puntoFijo(f, g, -0.5, 11, 0.0005, 0);
		//double x = raicesMultiples(f,g,g2,-3.2,11,0.0005,0);
		//
		//
		//
		//metodoGaussSeidel(c,A,b);

void leerxa(){
	cin >> xa;
}

void leertol(){
	cin >> tol;
}

void leerxb(){
	cin >> xb;
}

void leerdelta(){
	cin >> delta;
}

void leererrorType(){
	cin >> errorType;
}

void leernIter(){
	cin >> nIter;
}

void leerPuntosx(int temporal){
	cout << "inserte los puntos" << endl;
	double aux;
	vector<double> x(temporal,0);
	puntosx = x;
	for(int i = 0; i < temporal; i++){
		cin >> aux;
		puntosx[i] = aux;
	}
}

void leerPuntosy(int temporal){
	cout << "inserte los puntos" << endl;
	double aux;
	vector<double> x(temporal,0);
	puntosy = x;
	for(int i = 0; i < temporal; i++){
		cin >> aux;
		puntosy[i] = aux;
	}
}

void leerpuntoInicial(){
	cin >> puntoInicial;
}

void randomize(int n,int m){
	double aux = 0;
	vector<vector<double> > x(n,vector<double>(m, 0));
    A = x;
	for(int i = 0; i < n; i++){
		for(int j =0; j < m; j++){
			aux = rand() % 100 + 1; 
			A[i][j] = aux;
		}
	}
}

void randomizeb(int n){
	int aux;
	vector<double> x(n,0);
	b = x;
	for(int i = 0; i < n; i++){
		aux = rand() % 100 + 1;
		b[i] = aux;
	}
}

void randomizec(int n){
	int aux;
	vector<double> x(n,0);
	c = x;
	for(int i = 0; i < n; i++){
		aux = rand() % 100 + 1;
		c[i] = aux;
	}
}

void leerA(int n, int m){
	double aux = 0;
	cout << "inserte la matriz:" << endl;
	vector<vector<double> > x(n,vector<double>(m, 0));
	A = x;
	for(int i = 0; i < n; i++){
		for(int j =0; j < m; j++){
			cin >> aux;
			A[i][j] = aux;
		}
	}
}

void leerb(int n){
	int aux;
	vector<double> x(n,0);
	cout << "inserte el vector" << endl;
	b = x;
	for(int i = 0; i < n; i++){
		cin >> aux;
		b[i] = aux;
	}
}

void leerc(int n){
	int aux;
	vector<double> x(n,0);
	c = x;
	cout << "inserte los terminos independientes" << endl;
	for(int i = 0; i < n; i++){
		cin >> aux;
		c[i] = aux;
	}
}

void leerfuncionf(){
	cin >> funcionf;
}

void leerfuncionf2(){
	cin >> funcionf2;
}

void leerfunciong(){
	cin >> funciong;
}

void leervar(){
	cin >> var;
}

int main()
{
	vector<double> x;
	vector<vector<double>> ab;
	cout << "***Mathnalysis***" << endl;
	cout << "instrucciones:" << endl;
	cout << "1 para insertar xa" << endl;
	cout << "2 para insertar tolerancia" << endl;
	cout << "3 para insertar xb" << endl;
	cout << "4 para insertar delta" << endl;
	cout << "5 para insertar el tipo de error" << endl;
	cout << "6 para insertar el numero de iteraciones" << endl;
	cout << "7 para insertar una matriz A" << endl;
	cout << "8 para insertar una matriz b " << endl;
	cout << "9 para insertar una matriz c" << endl;
	cout << "10 para insertar una funcion f " << endl;
	cout << "11 para insertar una funcion f'" << endl;
	cout << "12 para insertar una funcion g" << endl;
	cout << "13 para ejecutar el metodo de biseccion" << endl;
	cout << "14 para ejecutar el metodo de busqueda incremental" << endl;
	cout << "15 para ejecutar el metodo de newton" << endl;
	cout << "16 para ejecutar el metodo de punto fijo" << endl;
	cout << "17 para ejecutar el metodo de raices multiples" << endl;
	cout << "18 para ejecutar el metodo de regla falsa" << endl;
	cout << "19 para ejecutar el metodo de secante " << endl;
	cout << "20 para ejecutar el metodo de cholesky" << endl;
	cout << "21 para ejecutar el metodo de crout" << endl;
	cout << "22 para ejecutar el metodo de doolitle" << endl;
	cout << "23 para ejecutar el metodo de eliminacion gaussiana simple" << endl;
	cout << "24 para ejecutar el metodo de gauss seidel" << endl;
	cout << "25 para ejecutar el metodo de jacobi" << endl;
	cout << "26 para ejecutar el metodo de elminacion gaussiana con pivoteo parcial" << endl;
	cout << "27 para ejecutar el metodo de elminacion gaussiana con pivoteo total" << endl;
	cout << "28 para insertar los puntos x" << endl;
	cout << "29 para insertar los puntos y" << endl;
	cout << "30 para ejecutar el metodo de diferencias divididas" << endl;
	cout << "31 para ejecutar el spline cubico " << endl;
	cout << "32 para ejecutar el spline lineas " << endl;
	cout << "33 para ejecutar el metodo de lagrange" << endl;
	cout << "0 para salir del programa" << endl;
	
	try{
		a = -1;
		int temporal;
		double v;
		double respuesta;
		double z;
		while(a != 0){
			cin >> a;
			switch (a)
			{
				case 1:
					cout << "digite el xa: " << endl;
					leerxa();
					break;
				case 2:
				    cout << "digite la tolerancia: " << endl;
					leertol();
					break;
				case 3:
					cout << "digite el xb: " << endl;
					leerxb();
					break;
				case 4:
					cout << "digite el delta: " << endl;
					leerdelta();
					break;
				case 5:
					cout << "digite 0 para el absoluto, 1 para el relativo: " << endl;
					leererrorType();
					break;
				case 6:
					cout << "digite el numero de iteraciones: : " << endl;
					leernIter();
					break;
				case 7:
					int m;
					cout << "cantidad de filas: ";
					cout << endl;
					cin >> n;
					cout << "cantidad de columnas: ";
					cout << endl; 
					cin >> m;
					leerA(n,m);
					break;
				case 8:
					leerb(n);
					break;
				case 9:
					leerc(n);
					break;
				case 10:
					cout << "digite la funcion f: " << endl;
		    		leerfuncionf();
					break;
				case 11:
					cout << "digite la funcion f': " << endl;
					leerfuncionf2();
					break;
				case 12:
					cout << "digite la funcion g: " << endl;
					leerfunciong();
					break;
				case 13:
					biseccion(f,xa,xb,tol,nIter);
					break;
				case 14:
					busqueda_incremental(f,xa, delta, nIter);
					break;
				case 15:
					newton(f,f2,xa,tol,nIter);
					break;
				case 16:
					puntoFijo(f,g,xa,nIter,tol,errorType);
					break;
				case 17:
		 			raicesMultiples(f,g,f2,xa,nIter,tol,errorType);
					break;
				case 18:
					reglaFalsa(f,xa,xb,tol,nIter);
					break;
				case 19:
					secante(f,tol,xa,xb,nIter);
					break;
				case 20:
					//randomize(100,100);
					//randomizeb(100);
					x = metodoCholesky(A,b);
					for(int i = 0; i <x.size(); i++){
			    		cout << "x" << i+1 << "= " << x[i] << endl;
			  		}
					break;
				case 21:
					x = metodoCrout(A,b);
					for(int i = 0; i <x.size(); i++){
			    		cout << "x" << i+1 << "= " << x[i] << endl;
			  		}
					break;
				case 22:
					x = doolittle(A,b);
					for(int i = 0; i <x.size(); i++){
			    		cout << "x" << i+1 << "= " << x[i] << endl;
			  		}
					break;
				case 23:
					ab = gausianaSimple(A,b,A.size());
					x = sustitucionBackwardEg(ab,ab.size());
					for(int i = 0; i < x.size(); i++){
			    		cout << "x" << i+1 << "= " << x[i] << endl;
			  		}
					break;
				case 24:
					x = metodoGaussSeidel(c, A, b);
					for(int i = 0; i < x.size(); i++){
			    		cout << "x" << i+1 << "= " << x[i] << endl;
			  		}
					break;
				case 25:
					jacobi(tol, nIter, c, A, b);
				    break;
				case 26:
					x = EliminacionGauss(A,b,A.size());
					for(int i = 0; i < x.size(); i++){
			    		cout << "x" << i+1 << "= " << x[i] << endl;
			  		}
					break;
				case 27:
					x = EliminacionGaussPivT(A, b, A.size());
					for(int i = 0; i < x.size(); i++){
			    		cout << "x" << i+1 << "= " << x[i] << endl;
			  		}
					break;
				case 28:
					cout << "inserte la cantidad de puntos" << endl;
					cin >> temporal;
					leerPuntosx(temporal);
					break;
				case 29:
					cout << "inserte la cantidad de puntos" << endl;
					cin >> temporal;
					leerPuntosy(temporal);
					break;
				case 30:
				    cout << "desde donde va empezar:" << endl;
					cin >> v; 
					cout << diferenciasDivididas(puntosx, puntosy, puntosx.size(), v) << endl;
					break;
				case 31:
					interpCubica(puntosx, puntosy);
					break;
				case 32:
					respuesta = interpolate( puntosx, puntosy, true ); 
					cout << respuesta << endl;
					break;
				case 33:
				    cout << "desde donde va empezar:" << endl;
					cin >> v; 
					cout << lagrange(puntosx, puntosy, puntosx.size(), v) << endl;
					break;
			}
		}
	}catch(exception e){
		cout << e.what() << endl;
	}
	return 0;
}

void toStringMatrixCRMa(vector<vector<double> > &matrix)
{
	for (unsigned int i = 0; i < matrix.size(); i++)
	{
		for (unsigned int j = 0; j < matrix[0].size(); j++)
		{
			printf("%f ", matrix[i][j]);
		}
		cout << endl;
	}
	printf("\n");
}

double f(double x) {
	//return exp(3*x-12)+x*cos(3*x) - pow(x,2) + 4;
	//return x*exp(x) - pow(x,2)- 5*x - 3;
	return analizar(funcionf,x);
}

double g(double x) {
    //return (x*exp(x) - pow(x,2) - 3) / 5;
	return analizar(funciong,x);
}

double f2(double x) {
	return analizar(funcionf2,x);
}
