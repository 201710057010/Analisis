#include<iostream>
#include<cmath>
#include<iomanip>
#include<cfloat>
#include <stdio.h>
#include<vector>
#include "jacobi.h"

using namespace std;

void toStringInja(vector<vector<double> > &matriz, char name) {
  printf("%c matriz\n", name);
  for (unsigned int i = 0; i < matriz.size(); i++){
    for (unsigned int j = 0; j < matriz[0].size(); j++) {
      if (matriz[i][j] == DBL_MAX) {
        printf("%6c%d%d ", name, j + 1, i + 1);
      }
      else {
        printf("%.6f ", matriz[i][j]);
      }
    }
    cout << endl;
  }
  printf("\n");
}


vector<vector <double> > formaMatrizAumentadaja (vector <vector<double> > a, vector<double> b, int n){
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

vector<double> calcularNuevoJacobi(vector<double> x, vector<vector<double> > ab, double lamda){
    vector<double> r(x.size(),0.0);
    for(int i=0; i<x.size(); i++){
      double suma = 0;
      for(int j=0; j<x.size(); j++){
        if(j != i){
          suma += ab[i][j]*x[j];
        }
      }
      r[i] = lamda * (ab[i][ab.size()] - suma)/ab[i][i] + (1- lamda) * x[i];
      suma = 0;
    }
    return r;
}

void jacobi(double tol, int iter, vector<double> &x, vector<vector<double> > &a, vector<double> &b){
    int cont = 0;
    double disp = tol + 1;
    vector<vector<double> > ab = formaMatrizAumentadaja(a,b,a.size()); 
    while(disp>tol && cont<iter){
      vector<double> xn = calcularNuevoJacobi(x, ab,1);
      double aux = 0;
      for(int i=0; i<a.size(); i++){
	      aux = max(abs(x[i]-xn[i]), aux);
      }
      disp = aux;
      x = xn;
      cont++;
      cout << "Iteración " << cont << endl;
      for(int i=0; i<x.size(); i++){
        cout << " x" << i << " = " << x[i] << endl;
      }
    }
    if(disp < tol){
      for(int i=0; i<x.size(); i++){
        cout << "x" << i << " = " << x[i] << "  ";
      }
      cout << "Aproximación con tolerancia = " << tol << endl; 
    } 
    else{
      cout << "Fracasó en " << iter << " iteraciones. ";
    }
}
