#include <cstdlib>
#include <iostream> 
#include <vector>
#include <cmath>
#include "InterpolacionCubica.h"
#include "..\VariasVariables\PivParcial.h"
#include <string>

using namespace std;


void toStringd2(vector<vector<double> > &matrix) {
  for (unsigned int i = 0; i < matrix.size(); i++)
	{
		for (unsigned int j = 0; j < matrix[0].size(); j++)
		{
			printf("%f ", matrix[i][j]);
		}
		cout << endl;
	}
	printf("\n");
}

void interpCuadratica(vector<double> &xn, vector<double> &fxn){
    string output = "";
    int n = (xn.size() - 1) * 3;
    vector<vector<double> > Ab(n, vector<double>(n+1,0.0));
    int i = 0;
    for(int j = 0; j< xn.size() -1; j++){
        Ab[i][j * 3] = pow(xn[j], 2);
        Ab[i][(j * 3) + 1] = xn[j];
        Ab[i][(j * 3) + 2] = 1;
    }
}