#pragma once

#include <string>
#include <map>

using namespace std;

class Calculator {
    public:
       Calculator();
       double eval(string expr);
       void store(int val);
       int recall();
    private:
       int memory;
};

extern Calculator* calc;