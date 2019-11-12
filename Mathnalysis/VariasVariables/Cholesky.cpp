#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>
#include <cfloat>
#include <stdio.h>
#include <omp.h>

using namespace std;

void toStringMatrixCRch(vector<vector<double> > &matrix)
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


void toStringInch(vector<vector<double> > &matriz, char name) {
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


void inicializarch(vector<vector<double> >& L, vector<vector<double> >& U) {
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
				U[i][j] = DBL_MAX;
				L[i][j] = U[i][j];
			}
		}
	}
}

void factorizacionLUch(vector<vector<double> >& A, vector<vector<double> >& L, vector<vector<double> >& U, int N) {
	//omp_set_dynamic(0);
	//omp_set_num_threads(5);
	#pragma omp for
	for (int k = 1; k < N + 1; k++) {
	//	printf("Phase %d\n\n", k);
	//	toStringInch(L, 'L');
	//	toStringInch(U, 'U');
		double sum = 0;
		for (int p = 0; p < k - 1; p++) {
			sum += L[k - 1][p] * U[p][k - 1];
		}
		L[k - 1][k - 1] = sqrt(A[k - 1][k - 1] - sum);
		U[k-1][k-1]= L[k-1][k-1];
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
				L[i - 1][k - 1] = (A[i - 1][k - 1] - sum) / L[k - 1][k - 1];
			}
		}
		for (int j = k + 1; j < N + 1; j++) {
			sum = 0;
			for (int p = 0; p < k - 1; p++) {
				sum += L[k - 1][p] * U[p][j - 1];
			}
			double denominator = L[k - 1][k - 1];
			if (denominator == 0) {
			  //throw div0Exception();
			}
			else {
				U[k - 1][j - 1] = (A[k - 1][j - 1] - sum) / L[k - 1][k - 1];
			}
		}
	}
}

vector<double> sustitucionForwardch(vector<vector<double> > &L, vector<double> &b) {
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

vector<double> sustitucionBackwardch(vector<vector<double> > &U, vector<double> &z) {
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



vector <double> metodoCholesky(vector<vector<double> > &A, vector<double> &b) {
	int N = A.size();
	vector<double> results;
	vector<vector<double> > L(N, vector<double>(N, 0.0));
	vector<vector<double> > U(N, vector<double>(N, 0.0));
	inicializarch(L, U);
	factorizacionLUch(A, L, U, N);
//	printf("Final L matrix\n");
//	toStringMatrixCRch(L);
//	printf("Final U matrix\n");
//	toStringMatrixCRch(U);
	vector<double> Z = sustitucionForwardch(L, b);
//	printf("z vector\n");
//	for (double e : Z) {
//		printf("%f ", e);
//	}
//	printf("\n\n");
	results = sustitucionBackwardch(U, Z);
	L.clear();
	L.shrink_to_fit();
	U.clear();
	U.shrink_to_fit();
	Z.clear();
	Z.shrink_to_fit();
	return results;
}


