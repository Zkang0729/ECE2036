#include <iostream>
#include <cmath>

using namespace std;

float rootFloat(bool plusMinus, float a, float b, float c) {
  float floatResult1 = 2 * c / (-1 * b + sqrt(b * b - 4 * a * c));
  float floatResult2 = 2 * c / (-1 * b - sqrt(b * b - 4 * a * c));
  if (plusMinus) {
    return floatResult1;
  } else {
    return floatResult2;
  }
}

double rootDouble(bool plusMinus, double a, double b, double c) {
  double doubleResult1 = 2 * c / (-1 * b + sqrt(b * b - 4 * a * c));
  double doubleResult2 = 2 * c / (-1 * b - sqrt(b * b - 4 * a * c));
  if (plusMinus) {
    return doubleResult1;
  } else {
     return doubleResult2;
  }
}

int main() {
  float floatPlus = rootFloat(true, 3, 9000.003, 9);
  float floatMinus = rootFloat(false, 3, 9000.003, 9);
  double doublePlus = rootDouble(true, 3, 9000.003, 9);
  double doubleMinus = rootDouble(false, 3, 9000.003, 9);
  cout << "Using the float data type the roots are:\n\t" 
        << "x(+) = " 
        << floatPlus << "\t% error = " 
        << 100 * (floatPlus - (-3000)) / floatPlus 
        << "\n\t" << "x(-) = " << floatMinus << "\t% error = " 
        << 100 * (floatMinus - (-0.001)) / floatMinus 
        << "\n\n" << "Using the double data type the roots are:\n\t" 
        << "x(+) = " 
        << doublePlus 
        << "\t% error = " 
        << 100 * (doublePlus - (-3000)) / doublePlus << "\n\t" 
        << "x(-) = " << doubleMinus << "\t% error = " 
        << 100 * (doubleMinus - (-0.001)) / doubleMinus  << endl;
  return 0;
}