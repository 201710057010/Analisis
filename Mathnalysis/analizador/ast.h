#pragma once
#include <string>

using namespace std;

class AST {
 public:
   AST();
   virtual ~AST() = 0;
   virtual double evaluate() = 0;
};

class BinaryNode : public AST {
 public:
   BinaryNode(AST* left, AST* right);
   ~BinaryNode();

   AST* getLeftSubTree() const;
   AST* getRightSubTree() const;

 private:
   AST* leftTree;
   AST* rightTree;
};

class UnaryNode : public AST {
 public:
   UnaryNode(AST* sub);
   ~UnaryNode();

   AST* getSubTree() const;

 private:
   AST* subTree;
};

class AddNode : public BinaryNode {
 public:
   AddNode(AST* left, AST* right);

   double evaluate();
};

class SubNode : public BinaryNode {
 public:
   SubNode(AST* left, AST* right);

   double evaluate();
};

class TimesNode : public BinaryNode {
 public:
   TimesNode(AST* left, AST* right);

   double evaluate();
};

class DivideNode : public BinaryNode {
 public:
   DivideNode(AST* left, AST* right);

   double evaluate();
};

class RecallNode : public AST {
 public:
  RecallNode();
  double evaluate();
};

class NumNode : public AST {
 public:
   NumNode(double n);

   double evaluate();

 private:
   double val;
};

class ExpoNode : public UnaryNode{
    public:
     ExpoNode(AST* sub);
     double evaluate();
};

class SenNode : public UnaryNode{
    public:
     SenNode(AST* sub);
     double evaluate();
};

class CosNode : public UnaryNode{
    public:
     CosNode(AST* sub);
     double evaluate();
};

class PotNode : public BinaryNode{
    public:
     PotNode(AST* left, AST* right);
     double evaluate();
};

class SqrtNode : public UnaryNode{
    public:
     SqrtNode(AST* sub);
     double evaluate();
};

class LnNode : public UnaryNode{
    public:
     LnNode(AST* sub);
     double evaluate();
};

class TanNode : UnaryNode{
    public:
     TanNode(AST* sub);
     double evaluate();
};

class NegNode: public UnaryNode{
  public:
    NegNode(AST* sub);
    double evaluate();
};