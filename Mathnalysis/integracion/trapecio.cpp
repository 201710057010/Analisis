#include <stdio.h>
#include <cmath>
#include <iostream>
#include <cstring>

using namespace std;


void trapecio (double (*func)(double), double a, double b, int n){
    double suma = 0.0;
    double fa = func(a);
    double fb = func(b);
    double h = ((b-a)/n);
    for(double i = (a+h); i < b; i+=h){
        suma = suma + func(i);

    }
    double area = ((h/2)*(fa+(2*suma)+fb));
    printf("%0.10f\n", area);

}

