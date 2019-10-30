# pragma once

#include<iostream>
#include<cmath>
#include<iomanip>
#include<cfloat>
#include<vector>

using namespace std;

vector<vector <double> > formaMatrizAumentada (vector <vector<double> > a, vector<double> b, int n);
void toStringInEg(vector<vector<double> > &matriz, char name);
vector<vector<double> > gausianaSimple (vector<vector<double> > &a, vector<double> &b, int n );
vector<double> sustitucionBackwardEg(vector<vector<double> > &Ab, int n);