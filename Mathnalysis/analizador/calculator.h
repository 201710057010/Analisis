#pragma once

#include <string>
#include <map>

using namespace std;

class Calculator {
    public:
       Calculator();
       double eval(string expr);
       void store(double val);
       double recall();
    private:
       double memory;
};

extern Calculator* calc;