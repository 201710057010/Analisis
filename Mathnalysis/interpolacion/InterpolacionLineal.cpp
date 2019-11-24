#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

double mientras;
double interpolate( vector<double> &xData, vector<double> &yData )
{
 
  cout << "X     F(X) \n";
 const int NPTS = 20;
   vector<double> xVals, yVals;
   for ( int i = 1; i <= NPTS; i++ ) xVals.push_back( (double)i );

   // Interpolate
   for ( double x : xData )
   {

  //determino la cantidad de valores de x.
   int size = xData.size();

   int i = 0;
   //determino extremo superior e inforior
   if ( x >= xData[size - 1] )                                                 
   {
      i = size - 2;
   }
   else
   {
      while ( x > xData[i+1] ) i++;
   }
   double xL = xData[i], yL = yData[i], xR = xData[i+1], yR = yData[i+1];      
                                                            
      if(x < xL ) yR = yL;
      if ( x > xR ) yL = yR;
   

   double dydx = ( yR - yL ) / ( xR - xL ); //gradiente
                               
   if(mientras==0 || mientras!=dydx){
     //  cout << "--->";
     cout << dydx;
     cout << "X";
     cout << "+";
     cout << yL - (dydx*xL) ;
     cout << "    " << xData[i] << " <=X<= "<<xData[i+1]<<'\n';
     
     
     mientras=dydx;
     }
   
   /*
   cout << x;
   cout << "   ,   ";
   cout << yL+dydx*(x-xL);
    cout<< '\n';
   */
     x++;                                 
}
  
}
//======================================================================

/*int main()
{
  vector<double> xData = { 1, 3, 4, 5, 7  };
  vector<double> yData = { 4.31, 1.5, 3.2, 2.6, 1.8  };


      double y = interpolate( xData, yData);
      
      }*/

  
