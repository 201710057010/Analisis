#pragma once

#include<iostream>
#include<cmath>
#include<iomanip>
#include<cfloat>
#include<vector>

using namespace std;

void toStringInja(vector<vector<double> > &matriz, char name);
vector<vector <double> > formaMatrizAumentadaja (vector <vector<double> > a, vector<double> b, int n);
vector<double> calcularNuevoJacobi(vector<double> x, vector<vector<double> > ab, double lamda);
void jacobi(double tol, int iter, vector<double> &x, vector<vector<double> > &a, vector<double> &b);