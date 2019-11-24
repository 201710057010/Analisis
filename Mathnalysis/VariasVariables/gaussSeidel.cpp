#include "gaussSeidel.h"
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <omp.h>

vector<double> metodoGaussSeidel(vector<double> &variables, vector<vector<double> > &matriz, vector<double> &indepterms) {
	double sum;
	vector<double> results(indepterms.size());
	int N = variables.size();
	results = variables;
	//#pragma omp parallel for
	for (int i = 0; i < N; i++) {
		sum = 0;
		#pragma omp parallel for
		for (int j = 0; j < N; j++) {
			if (j != i) {
				sum = sum + (matriz[i][j] * results[j]);
			}
		}
		results[i] = (indepterms[i] - sum) / matriz[i][i];
		//cout << results[i] << endl;
	}
	return results;
}

vector<double> solveGaussSeidel(vector<vector<double>> &A, vector<double> &b, vector<double> &initValues,double tol, int nIter,double lamda){
	int count;
	double dispersion;
	vector<double> x0(initValues),x1,ultimox1;

	count = 0;
	dispersion = tol +1;

	while(dispersion > tol && count < nIter){
		if(count != 0){
			ultimox1 = x1;
		}
		x1 = metodoGaussSeidel(x0,A,b);
		if(count != 0){
			for(unsigned int i = 0; i < x1.size(); i++){
				x1[i] = lamda * x1[i] + (1-lamda) * ultimox1[i];
			}
		}
		dispersion = absNorm(x1,x0);
		x0 = x1;
		count ++;
		cout << "Iteración " << count << endl;
		for(int i=0; i<x1.size(); i++){
        	cout << " x" << i << " = " << x1[i] << endl;
      	}
		cout << "error: " << dispersion << endl;
	}
	if(dispersion < tol){
		return x1;
	}else{
		cout << "el metodo super las iteraciones" << endl;  
	}
}

double absNorm(vector<double> &x1, vector<double> &x0){
	double sum = 0;
	for(long unsigned int i =0; i < x1.size(); i++){
		sum += pow(fabs(x1[i] - x0[i]), 2);
	}
	return sqrt(sum);
}