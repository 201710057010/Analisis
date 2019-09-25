#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;


void secante(double (*func)(double), double tol, double x0, double x1, int niter){
    if(tol<0){
        cout << "Invalid tolerance" << endl;
    }else{
        double fx0 = func(x0);
        cout << fixed;
        cout.precision(5);
        if(fx0 == 0){
            cout << x0 << " is a root" << endl;
        }else{
            cout << "|  i  |   x0  |  fx0  |   x1  |  fx1  | fx0 - fx1 |  Error  |" << endl;
            double fx1 = func(x1);
            int cont = 0;
            double error = tol+1;
            double den = fx1-fx0;
            double x2;

            while(error>tol && fx1 != 0 && den != 0 && cont < niter){
                cout << " | " << cont << " | " << x0 << " | " << fx0 << " | " << x1 << " | " << fx0 - fx1 << " | " << error << " |" << endl;
                x2 = x1 - fx1 * (x1 - x0) / den;
                error = abs(x2-x1);
                x0 = x1;
                fx0 = fx1;
                x1 = x2;
                fx1 = func(x1);
                den = fx1- fx0;
                cont++;
            }

            if(fx1==0){
                cout << x1 << " is a root" << endl;    
            }else if(error < tol){
                cout << x1 << " is an aproximation of a root with a tolerance =" << tol << endl;
            } else if (den == 0) {
                cout << "There is a posible multiple root" << endl;
            }else{
                cout << "The program fails in " << niter << " iterations" << endl;
            }
        } 
    }
}


