/*
  Author: Zixuan Kang
  Date Last Modified: January 27, 2020  
  Organization: ECE2036 
  Description: A C++ program to calculate the roots of the following quadratic equation:
  3x^2 + 9000.003xx + 9 = 0, using the non-conventional Muller’s method with float and double variable type.
  Compare the precision of those two kind of variables.
*/

#include <iostream>
#include <cmath>

using namespace std;

/*
  Calculate the root of the quadratic equation with the variable type of float
*/
float rootFloat(bool plusMinus, float a, float b, float c)
{
  float floatResult1 = 2 * c / (-1 * b + sqrt(b * b - 4 * a * c));
  float floatResult2 = 2 * c / (-1 * b - sqrt(b * b - 4 * a * c));
  if (plusMinus)
  {
    return floatResult1;
  }
  else
  {
    return floatResult2;
  }
}

/*
  Calculate the root of the quadratic equation with the variable type of double
*/
double rootDouble(bool plusMinus, double a, double b, double c)
{
  double doubleResult1 = 2 * c / (-1 * b + sqrt(b * b - 4 * a * c));
  double doubleResult2 = 2 * c / (-1 * b - sqrt(b * b - 4 * a * c));
  if (plusMinus)
  {
    return doubleResult1;
  }
  else
  {
    return doubleResult2;
  }
}

int main()
{
  float floatPlus = rootFloat(true, 3, 9000.003, 9);
  float floatMinus = rootFloat(false, 3, 9000.003, 9);
  double doublePlus = rootDouble(true, 3, 9000.003, 9);
  double doubleMinus = rootDouble(false, 3, 9000.003, 9);
  cout << "Using the float data type the roots are:\n\t"
       << "x(+) = "
       << floatPlus << "\t% error = "
       << 100 * (-3000 - floatPlus) / (-3000) // Calculate the error for float(+)
       << "\n\t"
       << "x(-) = " << floatMinus << "\t% error = "
       << 100 * (-0.001 - floatMinus) / (-0.001) // Calculate the error for float(-)
       << "\n\n"
       << "Using the double data type the roots are:\n\t"
       << "x(+) = "
       << doublePlus
       << "\t% error = "
       << 100 * (-3000 - doublePlus) / (-3000) << "\n\t" // Calculate the error for double(+)
       << "x(-) = " << doubleMinus << "\t% error = "
       << 100 * (-0.001 - doubleMinus) / (-0.001) << endl; // Calculate the error for double(-)
  return 0;
}