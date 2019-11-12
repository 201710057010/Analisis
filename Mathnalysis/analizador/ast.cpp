#include "ast.h"
#include <iostream>
#include "calculator.h"
#include <cmath>

using namespace std;

AST::AST() {}

AST::~AST() {}

BinaryNode::BinaryNode(AST* left, AST* right):
   AST(),
   leftTree(left),
   rightTree(right)
{}

BinaryNode::~BinaryNode() {
   try {
      delete leftTree;
   } catch (...) {}

   try {
      delete rightTree;
   } catch(...) {}
}

AST* BinaryNode::getLeftSubTree() const {
   return leftTree;
}

AST* BinaryNode::getRightSubTree() const {
   return rightTree;
}

UnaryNode::UnaryNode(AST* sub):
   AST(),
   subTree(sub)
{}

UnaryNode::~UnaryNode() {
   try {
      delete subTree;
   } catch (...) {}
}

AST* UnaryNode::getSubTree() const {
   return subTree;
}

AddNode::AddNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

double AddNode::evaluate() {
   return getLeftSubTree()->evaluate() + getRightSubTree()->evaluate();
}

SubNode::SubNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

double SubNode::evaluate() {
   return getLeftSubTree()->evaluate() - getRightSubTree()->evaluate();
}

TimesNode::TimesNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

double TimesNode::evaluate() {
   return getLeftSubTree()->evaluate() * getRightSubTree()->evaluate();
}

DivideNode::DivideNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

double DivideNode::evaluate() {
   return getLeftSubTree()->evaluate() / getRightSubTree()->evaluate();
}

NumNode::NumNode(double n) :
   AST(),
   val(n)
{}

double NumNode::evaluate() {
   return val;
}

RecallNode::RecallNode() : AST() { }

double RecallNode::evaluate() {
  return calc->recall();
}

ExpoNode::ExpoNode(AST* sub): UnaryNode(sub) {}

double ExpoNode::evaluate(){
    return exp(getSubTree()->evaluate());
}

SenNode::SenNode(AST* sub):
    UnaryNode(sub)
{}

double SenNode::evaluate(){
    return sin((getSubTree()->evaluate()*3.14159265 / 180));
}

CosNode::CosNode(AST* sub):
    UnaryNode(sub)
{}

double CosNode::evaluate(){
    return cos((getSubTree()->evaluate()*3.14159265 / 180));
}

PotNode::PotNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

double PotNode::evaluate(){
    return pow(getLeftSubTree()->evaluate(),getRightSubTree()->evaluate());
}

SqrtNode::SqrtNode(AST* sub):
    UnaryNode(sub)
{}

double SqrtNode::evaluate(){
    return sqrt(getSubTree()->evaluate());
}

LnNode::LnNode(AST* sub):
    UnaryNode(sub)
{}

double LnNode::evaluate(){
    return log(getSubTree()->evaluate());
}

TanNode::TanNode(AST* sub):
    UnaryNode(sub)
{}

double TanNode::evaluate(){
    return tan((getSubTree()->evaluate()*3.14159265 / 180));
}
