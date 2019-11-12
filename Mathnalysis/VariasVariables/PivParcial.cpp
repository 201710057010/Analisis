#include <cstdlib>
#include <iostream>
#include <vector>
#include <cfloat>
#include <stdio.h>
#include "PivParcial.h"
#include <omp.h>

using namespace std;

void toStringInPiv(vector<vector<double> > &matrix) {
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

vector<vector<double> > swapRows(vector<vector<double> > Ab, int filaMayor, int k){
  vector<double> aux = Ab[k];  
    Ab[k]=Ab[filaMayor];
    Ab[filaMayor]=aux;
    return Ab;
}

vector<vector <double> > pivParcial (vector<vector<double> > &Ab, int n, int k){
  double mayor = abs(Ab[k][k]);
  double filaMayor=0;
  for(int s=k+1;s<n; s++){
    filaMayor=k;
    if (abs(Ab[s][k]) > mayor){
      mayor=abs(Ab[s][k]);
      filaMayor=s;
    }
    if(mayor==0){
      cout << "El sistema no tiene solución unica" << endl;
    } else {
      if(filaMayor != k){
        cout << "Filas " << k << " y " << filaMayor << " cambiadas" << endl;
        Ab=swapRows(Ab,filaMayor,k);
      }
    }    
  } 
  toStringInPiv(Ab);
  return Ab;
}

vector<vector<double> > formaMatrizAumentadapiv(vector<vector<double> > a, vector<double> b, int n){
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

vector<double> sustitucionBackwardPiv(vector<vector<double> > Ab, int n) {
    vector<double> x(n, 0.0);
    x[n]= (Ab[n-1][n]/Ab[n-1][n-1]);
    for (int i = n - 1; i >= 0; i--) {
	  double sum = 0;
    #pragma omp parallel for
	  for (int j = i + 1; j < n; j++) {
	    sum = sum+(Ab[i][j]*x[j]);
	  }
	  double denominator = Ab[i][i];
	  if (denominator == 0) {
	    printf("Error por division por 0");
	  }
	  else {
	    x[i] = (Ab[i][n] - sum) / Ab[i][i];
	  }
	}
	return x;
}

vector<vector<double> > EliminacionGaussPivoteo(vector<vector<double> > &Ab,int n){
  for(int k =0; k<n-1; k++){
    cout<< "ETAPA " << k+1 << endl;
    Ab = pivParcial(Ab,n,k);
    double multiplicador=0;
    #pragma omp parallel for
    for(int i=k+1; i<n; i++){
      multiplicador = (Ab[i][k]/Ab[k][k]);
      //cout << multiplicador << endl;
      for(int j=k; j<n+1; j++){
        Ab[i][j]=(Ab[i][j]-(multiplicador*Ab[k][j]));
      }
    }
   toStringInPiv(Ab);
  }
  return Ab;
}

vector <double> EliminacionGauss(vector<vector<double> > &A, vector<double> b, int n){
  vector<double> x(n, 0.0);
  vector<vector<double> > Ab(n, vector<double>(n+1, 0.0));
  Ab = formaMatrizAumentadapiv(A,b,n);
  Ab = EliminacionGaussPivoteo(Ab,n);
  x= sustitucionBackwardPiv(Ab, n);
  return x;
}

  

