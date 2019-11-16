#include <iostream>
#include <sstream>
#include <string>
#include "calcex.h"
#include "calculator.h"
#include "analizer.h"
using namespace std;

Calculator* calc;

double analizar(string line, double x){
    try {
        calc = new Calculator();
        // line + '\n';
        calc-> store(x);
        double result = calc->eval(line);
        delete calc;
        return result;
    }
    catch(Exception ex) {
        cout << "Program Aborted due to exception!" << endl;
        return 0;
    }
}