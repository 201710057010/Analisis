#include <cstdlib>
#include <iostream>
#include <vector>
#include <cfloat>
#include <math.h>
#include "doolittle.h"

using namespace std;


void inicializardo(vector<vector<double> >& L, vector<vector<double> >& U, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i < j) {
	U[i][j] = DBL_MAX;
	L[i][j] = 0;
      }
      else if (i > j) {
	L[i][j] = DBL_MAX;
	U[i][j] = 0;
      }
      else if (i == j) {
      	U[i][j] = DBL_MAX;
	L[i][j] = 1;
      }
    }
  }
}

void toStringIndo(vector<vector<double> > &matriz, char name) {
  printf("%c matriz\n", name);
  for (unsigned int i = 0; i < matriz.size(); i++) {
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


void factorizacionLUdo(vector<vector<double> >& A, vector<vector<double> >& L, vector<vector<double> >& U, int N) {
 for (int k = 1; k < N + 1; k++) {
   printf("Phase %d\n\n", k);
   toStringIndo(L, 'L');
   toStringIndo(U, 'U');
   double sum = 0;
   for (int p = 0; p < k - 1; p++) {
     sum += L[k - 1][p] * U[p][k - 1];
   }
   U[k - 1][k - 1] =A[k - 1][k - 1] - sum;
   for (int i = k + 1; i < N + 1; i++) {
     sum = 0;
     for (int p = 0; p < k - 1; p++) {
       sum += L[i - 1][p] * U[p][k - 1];
     }
     double denominator = U[k - 1][k - 1];
     if (denominator == 0) {
       //throw div0Exception();
     }
     else {
       L[i - 1][k - 1] = (A[i - 1][k - 1] - sum) / U[k - 1][k - 1];
     }
   }
   for (int j = k + 1; j < N + 1; j++) {
     sum = 0;
     for (int p = 0; p < k - 1; p++) {
       sum += L[k - 1][p] * U[p][j - 1];
     }
     double denominator = L[k - 1][k - 1];
     if (denominator == 0) {
       //  throw div0Exception();
     }
     else {
       U[k - 1][j - 1] = (A[k - 1][j - 1] - sum) / L[k - 1][k - 1];
     }
   }
 }
}

vector<double> sustitucionForwarddo(vector<vector<double> > &L, vector<double> &b) {
  int N = L.size();
  std::vector<double> x(N, 0.0);
  for (int i = 1; i < N + 1; i++)
    {
      double sum = 0;
      for (int p = i - 1; p > 0; p--)
	{
	  sum += (L[i - 1][p - 1] * x[p - 1]);
	}
      double denominator = L[i - 1][i - 1];
      if (denominator == 0)
	{
	  //throw div0Exception();
	}
      else
	{
	  x[i - 1] = (b[i - 1] - sum) / L[i - 1][i - 1];
	}
    }
  return x;
}

vector<double> sustitucionBackwarddo(vector<vector<double> > &U, vector<double> &z) {
  int N = U.size();
  vector<double> x(N, 0.0);
  for (int i = N - 1; i >= 0; i--) {
    double sum = 0;
    for (int j = i + 1; j < N; j++) {
      sum += U[i][j] * x[j];
    }
    double denominator = U[i][i];
    if (denominator == 0) {
      //throw div0Exception();
    }
    else {
      x[i] = (z[i] - sum) / U[i][i];
    }
  }
  return x;
}

void toStringMatrixCRdo(vector<vector<double> > &matrix)
{
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

vector <double> doolittle(vector<vector <double>> A, vector<double> b){
  int n = A.size();
  vector <double> x;
  vector<vector<double> > L(n, vector<double>(n, 0.0));
  vector<vector<double> > U(n, vector<double>(n, 0.0));
  inicializardo(L,U,n);

  factorizacionLUdo(A, L, U, n);
  printf("Final L matrix\n");
  toStringMatrixCRdo(L);
  printf("Final U matrix\n");
  toStringMatrixCRdo(U);
  vector<double> Z = sustitucionForwarddo(L, b);
  printf("z vector\n");
  for (double e : Z) {
    printf("%f ", e);
  }
  printf("\n\n");
  x = sustitucionBackwarddo(U, Z);
  return x;

}

