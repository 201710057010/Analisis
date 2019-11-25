#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include<stdlib.h>
 
using namespace std;
 
//void leerDatos(vector < vector<double> > A, int fil, int col, vector<double> b);
void gaussEliminacion(vector < vector<double> > A, int fil, int col, vector<double> b);
void intercambiarFilas(vector < vector<double> > A, int col, int k, int max );
void imprimirMatriz(vector < vector<double> > A, int fil, int col, vector<double> b);
void imprimirSolucion(vector<double>v, int fil);
