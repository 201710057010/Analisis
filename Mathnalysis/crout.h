#pragma once
#include <vector>
#include <cfloat>
#include <iostream>

using namespace std;


vector <double> metodoCrout(vector<vector<double> > A, vector<double> b);
void inicializar(vector<vector<double> >& L, vector<vector<double> >& U);
void factorizacionLU(vector<vector<double> >& A, vector<vector<double> >& L, vector<vector<double> >& U, int N);
vector<double> sustitucionForward(vector<vector<double> >& L, vector<double>& b);
vector<double> sustitucionBackward(vector<vector<double> >& U, vector<double>& z);
void toStringMatrixCR(vector<vector<double> >& matrizAumentada);
//Prints incomplete matrix with equal spacing
void toStringIn(vector<vector<double> >& matriz, char name);