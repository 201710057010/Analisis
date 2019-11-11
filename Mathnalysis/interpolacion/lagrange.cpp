#include <cstdlib>
#include <iostream> 
#include <vector>
#include <cfloat>
//#include "PivParcial.h"
#include <string>

using namespace std;

double lagrange(vector<double>x, vector<double>y, int n, double v){
  vector<double> L(n);
  cout << "p(x)= ";
  for(int i =0; i <n; i++){
    vector<string> Li(n);
    double num =1;
    double den =1;
    for(int p=0; p<n; p++){
      string lis;
      if(i!=p){
	num = num *(v-x[p]);
	den = den *(x[i]-x[p]);
        lis= "[(x-"+to_string(x[p])+")/("+to_string(x[i])+"-"+to_string(x[p])+")]";
      }
      Li[p]=lis; 

    }
    
    cout << y[i];
    for(int j=0; j<n; j++){
      cout << Li[j];
    }
    cout << endl;
    cout << "+";
    if(den==0){
      //div0
    }else{ 
      L[i]= (num/den);
    }
  }

  double suma=0;
  for(int i =0; i<n; i++){
    suma = suma+(L[i]*y[i]);
  }
  cout << endl;
  return suma;

}

int main(){

  vector<double> x ={1,3,4,5,7};
  vector<double> y ={4.31,1.5,3.2,2.6,1.8};
  int n =5;
  double v =3;
  double res=  lagrange(x,y,n,v);
  cout << "p(" << v << ")=" << res << endl;

}
