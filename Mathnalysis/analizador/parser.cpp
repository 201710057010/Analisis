#include "parser.h"
#include "calcex.h"
#include <string>
#include <sstream>
#include "calculator.h"


Parser::Parser(istream* in) {
   scan = new Scanner(in);
}

Parser::~Parser() {
   try {
      delete scan;
   } catch (...) {}
}

AST* Parser::parse() {
   return prog();
}

AST* Parser::prog() {
   AST* result = expr();
   Token* t = scan->getToken();

   if (t->getType() != eof) {
      cout << "Syntax Error: Expected EOF, found token at column " << t->getCol() << endl;
      throw ParseError;
   }

   return result;
}

AST* Parser::expr() {
   return restExpr(term());
}

AST* Parser::restExpr(AST* e) {
   Token* t = scan->getToken();

   if (t->getType() == add) {
      return restExpr(new AddNode(e,term()));
   }

   if (t->getType() == sub)
      return restExpr(new SubNode(e,term()));

   scan->putBackToken();

   return e;
}

AST* Parser::term() {
  return restTerm(special());
}

AST* Parser::restTerm(AST* e) {
  Token *t = scan->getToken();

  if (t->getType() == times) {
    return restTerm(new TimesNode(e, special()));
  }

  if (t->getType() == divide) {
    return restTerm(new DivideNode(e, special()));
  }
  
  scan->putBackToken();

  return e;
}

AST* Parser::special(){
    return specialTerm(factor());
}

AST* Parser::specialTerm(AST* e){
   Token *t = scan->getToken();

 //  if(t->getType() == keyword){
 //     if(t->getLex() == "sen"){
 //        return specialTerm(new SenNode(factor()));
 //     }
 //     if(t->getLex() == "cos"){
 //        return specialTerm(new CosNode(factor()));
 //     }
//      if(t->getLex() == "sqrt"){
//         return specialTerm(new SqrtNode(factor()));
//      }
//      if(t->getLex() == "ln"){
 //        return specialTerm(new LnNode(factor()));
 //     }
 //  }
 //     if(t->getLex() == "tan"){
 //        return specialTerm(new TanNode(factor()));
 //     }
  // }
   //if(t->getType() == expo){
   //   return specialTerm(new ExpoNode(factor()));
   //}
   if(t->getType() == pot){
      return specialTerm(new PotNode(e,factor()));
   }
   scan->putBackToken();
   return e;
}

AST* Parser::factor() {
  Token* t = scan->getToken();
  if (t->getType() == number) {
    istringstream in(t->getLex());
    int val;
    in >> val;
    return new NumNode(val);
  }

   if(t->getType() == keyword){
      if(t->getLex() == "sen"){
         return specialTerm(new SenNode(factor()));
      }
      if(t->getLex() == "cos"){
         return specialTerm(new CosNode(factor()));
      }
      if(t->getLex() == "sqrt"){
         return specialTerm(new SqrtNode(factor()));
      }
      if(t->getLex() == "ln"){
         return specialTerm(new LnNode(factor()));
      }
   }

   if(t->getType() == expo){
      return specialTerm(new ExpoNode(factor()));
   }

  if (t->getType() == var) {
    return new RecallNode();
  }
  if (t->getType() == lparen) {
    AST* result = expr();
    t = scan->getToken();
    if (t->getType() != rparen) {
      cout << "Expected )"
	   << endl;
      throw ParseError;
    }
    return result;
  }

  if(t->getType() == sub){
     return new NegNode(factor());
  }

  cout << "Expected Number, x, '('" << endl;
  throw ParseError;
}