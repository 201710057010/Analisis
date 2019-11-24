#include "diferenciacion.h"
#include <vector>
#include <iostream>

double  metododiferenciacion(vector<int> &x, vector<int> &y, int direccion, double h, int num ){
    if(num == 2){
        return (y[1]-y[0])/h;
    }
    else if(num == 3){
        if(direccion == 0){
            return (y[0]-4*y[1]+3*y[2])/(2*h);
        }else if(direccion == 1){
            return(-y[2]+4*y[1]-3*y[0])/(2*h);
        }else if(direccion == 2){
            return(-y[0]+y[2])/(2*h);
        }else{
            cout << "error se esperaba una direccion entre 0 y 2" << endl; 
        }
    }
    else if(num == 5){
        if(direccion = 0){
            return ((25*y[4])-(48*y[3])+(36*y[2])-(16*y[1])+(3*y[0]))/(12*h);
        }else if(direccion == 1){
            return (-25*y[0]+48*y[1]-36*y[2]+16*y[3]-3*y[4])/(12*h);
        }else if(direccion == 2){
            return (y[0]-8*y[1]+8*y[3]-y[4])/(12*h);
        }else{
            cout << "error se esperaba una direccion entre 0 y 2" << endl;
        }
    }
    else{
        cout << "el metodo fallo" << endl;
    }
}