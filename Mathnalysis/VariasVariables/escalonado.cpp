#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include<stdlib.h>
 
using namespace std;
 
//void leerDatos(vector < vector<double> > A, int fil, int col, vector<double> b);
void gaussEliminacion(vector < vector<double> > A, int fil, int col, vector<double> b);
void intercambiarFilas(vector < vector<double> > A, int col, int k, int max );
void imprimirMatriz(vector < vector<double> > A, int fil, int col, vector<double> b);
void imprimirSolucion(vector<double>v, int fil);

int main()
{//vector<vector<double>
	int fil, col;

	cout << "\nNumero de variables: ";
	cin >> fil;
	col = fil;
	vector < vector<double> > A(fil, vector<double>(fil));
	//for( int i = 0; i < fil; i++ )
	  //  A[i] = new double[col];

	vector<double> B(fil);

	//leerDatos(A, fil, col, B);
	/*for (int i = 0; i < fil; i++) {
		
		for (int j = 0; j < col; j++) {
			
			A[i][j]= abs((double)rand() / RAND_MAX);
		}
	}
	for (int i = 0; i < fil; i++) {
		
		 B[i]= abs((double)rand() / RAND_MAX);
	}*/
	A[0][0] = 1;
		A[0][1] = -1;
		A[0][2] = -2;
		A[1][1] = 1;
		A[1][0] = 2;
		A[1][2] = -3;
		A[2][0] = 1;
		A[2][1] = 2;
		A[2][2] = 3;

		B[0] = 8;
		B[1] = 11;
		B[2] = 5;

	imprimirMatriz(A, fil, col, B);
	gaussEliminacion(A, fil, col, B);

	return 0;
}
 

/*void leerDatos(vector < vector<double> > A, int fil, int col, vector<double> B )
{
    cout << "\nIntroduzca coeficientes de la ecuacion:\n";
    for( int i = 0; i < fil; i++ ){
        cout << "\nFila " << i + 1 << ":\n";
        for( int j = 0; j < col; j++ ) {
            cout << "Columna " << j + 1 << ": ";
            cin >> A[i][j];
        }
    }
    cout << "\nIntroduzca igualdad de la ecuacion:\n";
    for(int i = 0; i < fil; i++ ){
        cout << "\nFila " << i + 1 << ": ";
        cin >> B[i];
    }
 
}*/
 
void gaussEliminacion(vector < vector<double> > A, int fil, int col, vector<double> B)
{
    int max;
    int N = fil;
    double factor, temp;
 
   for( int k = 0; k < N; k++ ){
        max = k;
        for( int i = k + 1; i < N; i++ )
            if( abs( A[i][k] ) > abs( A[max][k] ) )
                max = i;
 
        intercambiarFilas( A, col, k, max );
        temp = B[k];
        B[k] = B[max];
        B[max] = temp;
 
        for( int i = k + 1; i < N; i++ ) {
            factor = A[i][k] / A[k][k];
            B[i] -= factor * B[k];
 
            for( int j = k; j < N; j++ )
                A[i][j] -= factor * A[k][j];
 
        }
    }
    imprimirMatriz( A, fil, col, B );
  
	vector<double> solucion(fil);
	solucion[fil] = 0.0;
    double suma;
  
    for (int i = N - 1; i >= 0; i-- ){
 
        suma = 0.0;
 
        for( int j = i + 1; j < N; j++ )
            suma += A[i][j] * solucion[j];
 
        solucion[i] = (B[i] - suma) / A[i][i];
 
    }
    imprimirSolucion( solucion, fil );
}
 
void intercambiarFilas(vector < vector<double> > M, int col, int k, int max )
{
    double temp[col];
 
    for( int i = k; i < col; i++ ) {
            temp[i] = M[k][i];
            M[k][i] = M[max][i];
            M[max][i] = temp[i];
    }
}
 
void imprimirMatriz(vector < vector<double> > M, int fil, int col, vector<double> v )
{
    cout << setprecision(3) << fixed;
    cout << "\nMatriz:\n";
    for( int i = 0; i < fil; i++){
        for( int j = 0; j < col; j++){
            cout << M[i][j] << " ";
        }
        cout << "| " << v[i] << "\n";
    }
    cout << "\n";
}
 
void imprimirSolucion( vector<double> v, int fil )
{
    cout << "\nSolucion: ";
    for( int i = 0; i < fil; i++ )
        cout << "\nX" << i + 1 << ": " << v[i];
 
    cout << endl;
}

