#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

void newton(double (*func)(double), double (*dfunc)(double), double x0, double tol, int niter){
    if(tol<0){
        cout << "tolerancia no valida" << endl;
    }
    else if(niter<=0){
        cout << "numero de iteraciones no valido" << endl;
    } else {
        double y0 = func(x0);
        double dy0= dfunc(x0);
        int cont =0;
        double error = tol+1;
        cout << fixed;
        cout.precision(7);
        cout << "| niter |    xn    |    fxn   |   dfxn   |  error |" << endl;
        cout << "|   " << cont <<"   |" << x0 <<"|" << y0 << "|" << dy0  <<"|"<< "        " << "|" << endl;
        while((error>tol)&&(dy0!=0)&&(y0!=0)&&(cont<niter)){
            double x1= x0 -(y0/dy0);
            y0 = func(x1);
            dy0= dfunc(x1);
            error=abs(x1-x0);
            x0=x1;
            cont++;
            cout << "|   " << cont <<"   |" << x0 <<"|" << y0 << "|" << dy0  <<"|"<<error << "|" << endl;
        }
        if(y0==0){
            cout << x0 << " es raiz" << endl;
        } else if(error< tol){
             cout << "xm es una aproximacion a una raiz con una tolerancia = " << tol << endl;

        } else {
            cout << "fracaso en el numero de iteracciones" << endl;
        
        }
    } 
}
