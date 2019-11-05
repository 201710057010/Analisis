#include<iostream>
#include<cmath>
#include<iomanip>
#include<cfloat>
#include<vector>
#include "EGS.h"

using namespace std;

vector<vector <double> > formaMatrizAumentada (vector <vector<double> > a, vector<double> b, int n){
    vector<vector<double> > aumentada(n, vector<double>(n+1, 0.0));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            aumentada[i][j] = a[i][j];
        }
    }
    for(int i=0; i<n; i++){
        aumentada[i][n] = b[i];
    }

    return aumentada;
}

void toStringInEg(vector<vector<double> > &matrix) {
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

vector<vector<double> > gausianaSimple (vector<vector<double> > &a, vector<double> &b, int n  ){
    vector<vector<double> > ab = formaMatrizAumentada(a,b,n);
    for(int k=0; k<n-1; k++){
      cout << "ETAPA "<< k+1 << endl;
      double multiplicador=0;
        for(int i=k+1; i<n; i++){
	  multiplicador = (ab[i][k]/ab[k][k]);
	  //cout << multiplicador << endl;
            for(int j=k; j<n+1; j++){
	      ab[i][j] = (ab[i][j] - (multiplicador * ab[k][j]));
            }
        }
        toStringInEg(ab);
    }

    return ab;
}

vector<double> sustitucionBackwardEg(vector<vector<double> > &Ab, int n) {
    
    vector<double> x(n, 0.0);
    x[n-1]= (Ab[n-1][n]/Ab[n-1][n-1]);
    
        for (int i = n - 2; i>=0; i--) {
          double sum = 0;
          for (int j = i + 1; j < n; j++) {
            sum = sum + (Ab[i][j]*x[j]);
          }
          double denominator = Ab[i][i];

          if (denominator == 0) {
            printf("Error div por 0");
          }
          else {
            x[i] = (Ab[i][n] - sum) / Ab[i][i];
            
          }
        }
        
        return x;
}


