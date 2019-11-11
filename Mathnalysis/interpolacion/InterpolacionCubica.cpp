#include <cstdlib>
#include <iostream> 
#include <vector>
#include <cmath>
#include "InterpolacionCubica.h"
#include "..\VariasVariables\PivParcial.h"
#include <string>

using namespace std;

void toStringdd(vector<vector<double> > &matrix) {
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

void interpCubica(vector<double> &xn, vector<double> &fxn){
  string output = "";
  int n = (xn.size() - 1) * 4;
  vector<vector<double> > Ab(n, vector<double>(n+1,0.0));
  int i = 0;
  for (int j = 0; j < xn.size() - 1; j++) {
    Ab[i][j * 4] = pow(xn[j], 3);
    Ab[i][(j * 4) + 1] = pow(xn[j], 2);
    Ab[i][(j * 4) + 2] = xn[j];
    Ab[i][(j * 4) + 3] = 1;
    Ab[i][n] = fxn[j];
    i++;
  }
  for (int j = 1; j < xn.size(); j++) {
    j--;
    Ab[i][j * 4] = pow(xn[(j+1)], 3);
    Ab[i][(j * 4) + 1] = pow(xn[(j+1)], 2);
    Ab[i][(j * 4) + 2] = xn[j+1];
    Ab[i][(j * 4) + 3] = 1;
    j++;
    Ab[i][n] = fxn[j];
    i++;
  }
  for (int j = 1; j < xn.size() - 1; j ++) {
    j--;
    Ab[i][j * 4] = 3 * pow(xn[(j+1)], 2);
    Ab[i][(j * 4) + 1] = 2 * xn[(j+1)];
    Ab[i][(j * 4) + 2] = 1;
    Ab[i][(j * 4) + 4] = -3 * pow(xn[(j+1)], 2);
    Ab[i][(j * 4) + 5] = -2 * xn[(j+1)];
    Ab[i][(j * 4) + 6] = -1;
    j++;
    i++;
  }
  for (int j = 1; j < xn.size() - 1; j ++) {
    j--;
    Ab[i][j * 4] = 6 * xn[(j+1)];
    Ab[i][(j * 4) + 1] = 2;
    Ab[i][(j * 4) + 4] = -6 * xn[(j+1)];
    Ab[i][(j * 4) + 5] = -2;
    j++;
    i++;
  }
  Ab[i][0] = 6 * xn[0];
  Ab[i][1] = 2;
  int n2 = (xn.size() - 2) * 4;
  Ab[i + 1][n2] = 6 * xn[xn.size() - 1];
  Ab[i + 1][n2 + 1] = 2;

  toStringdd(Ab);

  string ecuaciones = "Sistema de ecuaciones Ab\n";
  vector<vector<double> > A(n,vector<double>(n,0.0));
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      A[i][j] = Ab[i][j];
    }
  }
  vector<double> b(n, 0.0);
  for(int i=0; i<n; i++){
    b[i] = Ab[i][n];
  }
  vector<double> rVector = EliminacionGauss(Ab, b, n);
  n = xn.size();

  for (int j = 0; j < n -1; j++) {
    ecuaciones += std::to_string((float) rVector[j*4]) + " x^3 ";
    ecuaciones += std::to_string((float)rVector[j*4+1]) + " x^2 ";
    ecuaciones += std::to_string((float)rVector[j*4+2])+ " x ";
    ecuaciones += std::to_string((float)rVector[j*4+3]);
    ecuaciones += ", " + std::to_string(xn[(j)]) + "<= x <= " + std::to_string(xn[j+1]) + " \n";
  }
  cout << ecuaciones << endl;
}

int main(){
  vector<double> b = { 1,3,4,5 };
  vector<double> c = { 3,1,3.5,2 };
  interpCubica(b,c);
}
