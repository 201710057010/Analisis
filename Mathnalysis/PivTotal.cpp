#include <cstdlib>
#include <iostream>
#include <vector>
#include <cfloat>

using namespace std;

vector<vector<double>> swapRows(vector<vector<double>> Ab, int filaMayor, int k){
  
    vector<double> aux = Ab[k];

    Ab[k]=Ab[filaMayor];
    Ab[filaMayor]=aux;

    return Ab;
}

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





vector<vector<double>> swapCol(vector<vector<double>> Ab, int colMayor, int k){
  int n=Ab.size();
  
    for(int i=0;i<n;i++){
    int l=0;
    l=Ab[i][k];
    Ab[i][k]=Ab[i][colMayor];
    Ab[i][colMayor]=l;
    }

    return Ab;
}

vector<vector <double> > pivTotal (vector<vector<double>> &Ab, int n, int k){
  vector<int> marcas(n);
  double mayor = 0;
  double filaMayor = k;
  double columnaMayor=k;
  for (int i=0;i<n;i++){
    marcas[i]=i;
  }
  for (int r=k;r<n;r++){
    for(int s=k;s<n; s++){
      
      if (abs(Ab[r][s]) > mayor){
	
	mayor=abs(Ab[r][s]);
       filaMayor=r;
       columnaMayor=s;
       
    }
   }
  }  
    if(mayor==0){
      cout << "El sistema no tiene solucion unica";
    } else {
      if(filaMayor != k){
        Ab=swapRows(Ab,filaMayor,k);
	
      }if(columnaMayor != k){
	Ab=swapCol(Ab,columnaMayor,k);
	int temp=marcas[k];
	marcas[k]=marcas[columnaMayor];
	marcas[columnaMayor]=temp;
      }
    

    }
    
    
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



vector<vector<double>> EliminacionGaussPivoteo(vector<vector<double> > &Ab,int n){
  for(int k =0; k<n-1; k++){
    Ab = pivTotal(Ab,n,k);
    cout << "primera ";
    toStringIn(Ab);
    double multiplicador=0;
    for(int i=k+1; i<n; i++){
      multiplicador = (Ab[i][k]/Ab[k][k]);
      for(int j=k; j<n+1; j++){
        Ab[i][j]=(Ab[i][j]-(multiplicador*Ab[k][j]));
      }
    }
    toStringIn(Ab);
  }
  return Ab;
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

vector <double> EliminacionGauss(vector<vector<double>> &A, vector<double> b, int n){
  vector<double> x(n, 0.0);
  vector<vector<double> > Ab(n, vector<double>(n+1, 0.0));
  Ab = formaMatrizAumentada(A,b,n);
   Ab=EliminacionGaussPivoteo(Ab,n);
   x=sustitucionBackward(Ab,n);
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
