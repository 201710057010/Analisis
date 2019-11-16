#include "calculator.h"
#include "parser.h"
#include "ast.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

Calculator::Calculator():
  memory(0)
{}

double Calculator::eval(string expr) {

   Parser* parser = new Parser(new istringstream(expr));

   AST* tree = parser->parse();

   double result = tree->evaluate();

   delete tree;
   
   delete parser;
   
   return result;
}

void Calculator::store(double val) {
   memory = val;
}


double Calculator::recall() {
   return memory;
}
