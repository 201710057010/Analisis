#include <cstdlib>
#include <iostream> 
#include <vector>
#include <cfloat>
//#include "PivParcial.h"
#include <string>

using namespace std;

void toStringdd(vector<vector<double> > &matrix) {
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

double diferenciasDivididas(vector<double> x, vector<double> y, int n, double v){
  vector<vector<double>> dd(n, vector<double>(n,0.0)); 
  for(int i =0; i<n; i++ ){
    dd[i][0] = y[i];
  }
  
  for(int j =1; j<n; j++){
    int k = j;
    for(int i = 1; i<n; i++){
      double den = (x[k]-x[i-1]);
      if (den ==0){
	//div0
      } else {
      dd[k][j]= (dd[k][j-1]-dd[k-1][j-1])/den;
      k= k+1;
      if(k==n){
	i=n;
      }
      }
    }
  }

  toStringdd(dd);
  double suma =0;
  for(int i=0; i<n; i++){
    double factor =1;
    string f;
    if(i!=0){
      for(int p=0; p < i; p++){
	factor = factor * (v- x[p]);
	f = f + "(x-"+ to_string(x[p])+ ")";
      }
    }
    suma = suma + (dd[i][i]*factor);
     if(i==0){
       cout <<"p(x)=" << dd[i][i];
    } else {
      cout << " + " << dd[i][i] << f ;  
    }
     
  }
  cout << endl;
  return suma;
}

int main(){

  vector<double> x ={1,3,4,5,7};
  vector<double> y ={4.31,1.5,3.2,2.6,1.8};
  int n =5;
  double v = 2.5;
  double res=  diferenciasDivididas(x,y,n,v);
  cout << "p(" << v << ")=" << res << endl;

}
