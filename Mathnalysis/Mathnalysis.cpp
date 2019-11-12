// Mathnalysis.cpp: define el punto de entrada de la aplicación.
//


#include "Mathnalysis.h"
#include "exceptions.h"
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
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

double f2(double x);
double f(double x);
double g2(double x);
int a,nIter,n,k, var;
double xa, tol, xb, delta, respuesta;
bool errorType;
vector<double> x;
vector<vector<double> > A;
vector<double> b;
vector<double> c;
vector<vector<double>> ab;
string funcionf,funciong,funcionf2;

using namespace std;


		//double x = puntoFijo(f, g, -0.5, 11, 0.0005, 0);
		//double x = raicesMultiples(f,g,g2,-3.2,11,0.0005,0);
		//
		//
		//
		//metodoGaussSeidel(c,A,b);

void leerxa(){
	cin >> a;
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
	int n = 0;
	randomize(3000,3000);
	randomizeb(3000);
	metodoCholesky(A,b);
	/**try{
		a = -1;
		while(a != 0){
			cin >> a;
			switch (a)
			{
				case 1:
					leerxa();
					break;
				case 2:
					leertol();
					break;
				case 3:
					leerxb();
					break;
				case 4:
					leerdelta();
					break;
				case 5:
					leererrorType();
					break;
				case 6:
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
		    		leerfuncionf();
					break;
				case 11:
					leerfuncionf2();
					break;
				case 12:
					leerfunciong();
					break;
				case 13:
					biseccion(f,xa,xb,tol,nIter);
					break;
				case 14:
					busqueda_incremental(f,xa, delta, nIter);
					break;
				case 15:
					newton(f,g,xa,tol,nIter);
					break;
				case 16:
					puntoFijo(f,g,xa,tol,nIter,errorType);
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
					cout << f(var) << endl;
					break;
				case 21:
					leervar();
					break;
				case 22:
					randomize(100,100);
					randomizeb(100);
					metodoCholesky(A,b);
					break;
			}
		}
	}catch(exception e){
		cout << e.what() << endl;
	}*/
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
	return analizar(funcionf,x);
}

double g(double x) {
	return analizar(funciong,x);
}

double f2(double x) {
	return analizar(funcionf2,x);
}
