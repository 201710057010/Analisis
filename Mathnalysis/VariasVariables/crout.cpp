#include <omp.h>
#include "crout.h"
#include <cfloat>
#include <stdio.h>

//#include "exceptions.h"
#include <iostream>

vector <double> metodoCrout(vector<vector<double> > &A, vector<double> &b) {
	int N = A.size();
	vector<double> results;
	vector<vector<double> > L(N, vector<double>(N, 0.0));
	vector<vector<double> > U(N, vector<double>(N, 0.0));
	inicializar(L, U); 

	try {
		factorizacionLU(A, L, U, N);
		printf("Final L matrix\n");
		toStringMatrixCR(L);
		printf("Final U matrix\n");
		toStringMatrixCR(U);
		vector<double> Z = sustitucionForward(L, b);
		printf("z vector\n");
		for (double e : Z) {
			printf("%f ", e);
		}
		printf("\n\n");
		results = sustitucionBackward(U, Z);
		Z.clear();
		Z.shrink_to_fit();
	}
	catch (exception& ex) {
		throw ex;
	}
	L.clear();
	L.shrink_to_fit();
	U.clear();
	U.shrink_to_fit();
	return results;
}


void inicializar(vector<vector<double> >& L, vector<vector<double> >& U) {
	int N = L.size();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i < j) {
				U[i][j] = DBL_MAX;
				L[i][j] = 0;
			}
			else if (i > j) {
				L[i][j] = DBL_MAX;
				U[i][j] = 0;
			}
			else if (i == j) {
				U[i][j] = 1;
				L[i][j] = DBL_MAX;
			}
		}
	}
}

void factorizacionLU(vector<vector<double> >& A, vector<vector<double> >& L, vector<vector<double> >& U, int N) {
	for (int k = 1; k < N + 1; k++) {
		printf("Phase %d\n\n", k);
		toStringIn(L, 'L');
		toStringIn(U, 'U');
		double sum = 0;
		for (int p = 0; p < k - 1; p++) {
			sum += L[k - 1][p] * U[p][k - 1];
		}
		L[k - 1][k - 1] = A[k - 1][k - 1] - sum;
		for (int i = k + 1; i < N + 1; i++) {
			sum = 0;
			for (int p = 0; p < k - 1; p++) {
				sum += L[i - 1][p] * U[p][k - 1];
			}
			double denominator = U[k - 1][k - 1];
			if (denominator == 0) {
		//		throw div0Exception();
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
		//		throw div0Exception();
			}
			else {
				U[k - 1][j - 1] = (A[k - 1][j - 1] - sum) / L[k - 1][k - 1];
			}
		}
	}
}

vector<double> sustitucionForward(vector<vector<double> > &L, vector<double> &b) {
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
		//	throw div0Exception();
		}
		else
		{
			x[i - 1] = (b[i - 1] - sum) / L[i - 1][i - 1];
		}
	}
	return x;
}

vector<double> sustitucionBackward(vector<vector<double> > &U, vector<double> &z) {
	int N = U.size();
	vector<double> x(N, 0.0);
	for (int i = N - 1; i >= 0; i--) {
		double sum = 0;
		for (int j = i + 1; j < N; j++) {
			sum += U[i][j] * x[j];
		}
		double denominator = U[i][i];
		if (denominator == 0) {
		//	throw div0Exception();
		}
		else {
			x[i] = (z[i] - sum) / U[i][i];
		}
	}
	return x;
}

void toStringMatrixCR(vector<vector<double> > &matrix)
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


void toStringIn(vector<vector<double> > &matriz, char name) {
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
