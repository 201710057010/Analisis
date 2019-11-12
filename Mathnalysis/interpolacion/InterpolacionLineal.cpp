#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

double mientras;
double interpolate( vector<double> &xData, vector<double> &yData,  bool extrapolate )
{
 
  cout << "X     F(X) \n";
 const int NPTS = 20;
   vector<double> xVals, yVals;
   for ( int i = 1; i <= NPTS; i++ ) xVals.push_back( (double)i );

   // Interpolate
   for ( double x : xVals )
   {

  //determino la cantidad de valores de x.
   int size = xData.size();

   int i = 0;
   //determino extremo superior e inforior
   if ( x >= xData[size - 2] )                                                 
   {
      i = size - 2;
   }
   else
   {
      while ( x > xData[i+1] ) i++;
   }
   double xL = xData[i], yL = yData[i], xR = xData[i+1], yR = yData[i+1];      
   if ( !extrapolate ){                                                         
      if(x < xL ) yR = yL;
      if ( x > xR ) yL = yR;
   }

   double dydx = ( yR - yL ) / ( xR - xL ); //gradiente
                               
   if(mientras==0 || mientras!=dydx){
     //  cout << "--->";
     cout << dydx;
     cout << "X";
     cout << "+";
     cout << yL - (dydx*xL) ;
     cout << '\n';
     mientras=dydx;
   }
   
   
   cout << x;
   cout << "   ,   ";
   cout << yL+dydx*(x-xL);
    cout<< '\n';
   
     x++;                                 
}
  
}
//======================================================================
