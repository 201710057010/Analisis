#pragma once
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cfloat>

using namespace std;

void toStringInPiv(vector<vector<double> > &matrix);
vector<vector<double> > swapRows(vector<vector<double> > Ab, int filaMayor, int k);
vector<vector <double> > pivParcial (vector<vector<double> > &Ab, int n, int k);
vector<vector<double> > formaMatrizAumentadapiv(vector<vector<double> > a, vector<double> b, int n);
vector<double> sustitucionBackwardPiv(vector<vector<double> > Ab, int n);
vector<vector<double> > EliminacionGaussPivoteo(vector<vector<double> > &Ab,int n);
vector <double> EliminacionGauss(vector<vector<double>> &A, vector<double> b, int n);
