#include <cstdlib>
#include <iostream>
#include <vector>
#include <cfloat>
#include "PivParcial.h"

using namespace std;

void toStringIn(vector<vector<double> > &matrix) {
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

vector<vector<double>> swapRows(vector<vector<double>> Ab, int filaMayor, int k){
  vector<double> aux = Ab[k];  
    Ab[k]=Ab[filaMayor];
    Ab[filaMayor]=aux;
    return Ab;
}

vector<vector <double> > pivParcial (vector<vector<double>> &Ab, int n, int k){
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
  toStringIn(Ab);
  return Ab;
}

vector<vector<double> > formaMatrizAumentada(vector<vector<double> > a, vector<double> b, int n){
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

vector<double> sustitucionBackward(vector<vector<double> > Ab, int n) {
    vector<double> x(n, 0.0);
    x[n]= (Ab[n-1][n]/Ab[n-1][n-1]);
	for (int i = n - 1; i >= 0; i--) {
	  double sum = 0;
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

vector<vector<double>> EliminacionGaussPivoteo(vector<vector<double> > &Ab,int n){
  for(int k =0; k<n-1; k++){
    cout<< "ETAPA " << k+1 << endl;
    Ab = pivParcial(Ab,n,k);
    double multiplicador=0;
    for(int i=k+1; i<n; i++){
      multiplicador = (Ab[i][k]/Ab[k][k]);
      //cout << multiplicador << endl;
      for(int j=k; j<n+1; j++){
	Ab[i][j]=(Ab[i][j]-(multiplicador*Ab[k][j]));
	
      }
    }
   toStringIn(Ab);
  }
  
  return Ab;
}



vector <double> EliminacionGauss(vector<vector<double>> &A, vector<double> b, int n){
  vector<double> x(n, 0.0);
  vector<vector<double> > Ab(n, vector<double>(n+1, 0.0));
  Ab = formaMatrizAumentada(A,b,n);
  Ab = EliminacionGaussPivoteo(Ab,n);
  x= sustitucionBackward(Ab, n);
  return x;
}


  int main() {
  vector<vector<double> > l(4, vector<double>(4, 0.0));
  l[0][0] = -7;
  l[0][1] = 2;
  l[0][2] = -3;
  l[0][3] = 4;
  l[1][0] = 5;
  l[1][1] = -1;
  l[1][2] = 14;
  l[1][3] = -1;
  l[2][0] = 1;
  l[2][1] = 9;
  l[2][2] = -7;
  l[2][3] = 5;
  l[3][0] = -12;
  l[3][1] = 13;
  l[3][2] = -8;
  l[3][3] = -4;
  
  vector<double> m={-12,13,31,-32};
  
  vector<double>  a = EliminacionGauss(l,m,4);

  for(int i =0; i< a.size(); i++){
    cout <<"x"<<i+1<<"= "<< a[i] << endl;

  }
  // toStringIn(a,'a');
  
}

  

