#include "gaussSeidel.h"
#include <iostream>
#include <stdio.h>


vector<double> metodoGaussSeidel(vector<double> &variables, vector<vector<double> > &matriz, vector<double> &indepterms) {
	double sum;
	vector<double> results(indepterms.size());
	int N = variables.size();
	results = variables;
	for (int i = 0; i < N; i++) {
		sum = 0;
		for (int j = 0; j < N; j++) {
			if (j != i) {
				sum = sum + (matriz[i][j] * results[j]);
			}
		}
		results[i] = (indepterms[i] - sum) / matriz[i][i];
		cout << results[i] << endl;
	}
	return results;
}