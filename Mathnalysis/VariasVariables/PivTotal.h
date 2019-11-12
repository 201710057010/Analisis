#include <cstdlib>
#include <iostream>
#include <vector>
#include <cfloat>

using namespace std;

vector<vector<double> > swapRowsPivT(vector<vector<double> > Ab, int filaMayor, int k);
void toStringInPivT(vector<vector<double> > &matrix);
vector<vector<double> > swapColPivT(vector<vector<double> > Ab, int colMayor, int k);
vector<vector <double> > pivTotal (vector<vector<double> > &Ab, int n, int k);
vector<vector<double> > formaMatrizAumentadaPivT(vector<vector<double> > a, vector<double> b, int n);
vector<vector<double> > EliminacionGaussPivT(vector<vector<double> > &Ab,int n);
vector<double> sustitucionBackwardPivt(vector<vector<double> > Ab, int n);
vector <double> EliminacionGaussPivT(vector<vector<double> > &A, vector<double> b, int n);