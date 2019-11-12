#pragma once

#include <cstdlib>
#include <iostream>
#include <vector>
#include <cfloat>
#include <math.h>

using namespace std;

void toStringMatrixCR(vector<vector<double> > &matrix);
void toStringIn(vector<vector<double> > &matriz, char name);
void inicializar(vector<vector<double> >& L, vector<vector<double> >& U);
void factorizacionLU(vector<vector<double> >& A, vector<vector<double> >& L, vector<vector<double> >& U, int N);
vector<double> sustitucionForward(vector<vector<double> > &L, vector<double> &b);
vector<double> sustitucionBackward(vector<vector<double> > &U, vector<double> &z);
vector <double> metodoCholesky(vector<vector<double> > &A, vector<double> &b);
