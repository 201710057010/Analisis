#pragma once
#include <vector>

using namespace std;

vector<double> metodoGaussSeidel(vector<double> &variables, vector<vector<double> > &matriz, vector<double> &indepTerms);
vector<double> solveGaussSeidel(vector<vector<double>> &A, vector<double> &b, vector<double> &initValues,double tol, int nIter,double lamda);
double absNorm(vector<double> &x1, vector<double> &x0);