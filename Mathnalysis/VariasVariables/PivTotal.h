#include <cstdlib>
#include <iostream>
#include <vector>
#include <cfloat>

using namespace std;

vector<vector<double>> swapRows(vector<vector<double>> Ab, int filaMayor, int k);
void toStringInPivT(vector<vector<double> > &matrix);
vector<vector<double>> swapCol(vector<vector<double>> Ab, int colMayor, int k);
vector<vector <double> > pivTotal (vector<vector<double>> &Ab, int n, int k);
vector<vector<double> > formaMatrizAumentada(vector<vector<double> > a, vector<double> b, int n);
vector<vector<double>> EliminacionGaussPivoteo(vector<vector<double> > &Ab,int n);
vector<double> sustitucionBackwardPivt(vector<vector<double> > Ab, int n);
vector <double> EliminacionGauss(vector<vector<double>> &A, vector<double> b, int n);