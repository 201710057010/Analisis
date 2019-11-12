#pragma once
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cfloat>
#include <math.h>

using namespace std;

void inicializar(vector<vector<double> >& L, vector<vector<double> >& U, int n);
void toStringIndo(vector<vector<double> > &matriz, char name);
void factorizacionLUdo(vector<vector<double> >& A, vector<vector<double> >& L, vector<vector<double> >& U, int N);
vector<double> sustitucionForwarddo(vector<vector<double> > &L, vector<double> &b);
vector<double> sustitucionBackwarddo(vector<vector<double> > &U, vector<double> &z);
void toStringMatrixCRdo(vector<vector<double> > &matrix);
vector <double> doolittle(vector<vector <double>> &A, vector<double> &b);
