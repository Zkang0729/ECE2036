/*
  Author: Zixuan Kang
  Date Last Modified: January 27, 2020  
  Organization: ECE2036 
  Description: Code to calculate the sqrt(2) using:
  - 20 terms using float precision
  - 80 terms using double precision
  and compare the answer to the actual value to 20 decimal places of sqrt(2)
  Each term is calculated using the formula (2k+1)!/2^(3k+1)/(k!)^2
*/

#include <iostream>
#include <cmath>

using namespace std;

/*
  Calculate each term in float.
  Instead calculating the factorial and the power and then divide by them, dividing the number one by one will provide better precision.
*/
float floatTerm(int n)
{
  float floatResult = 1;
  for (int i = n + 1; i <= 2 * n + 1; i++)
  {
    floatResult *= i;
  }
  for (int j = 1; j <= 3 * n + 1; j++)
  {
    floatResult /= 2;
  }
  if (n == 0)
  {
    return floatResult;
  }
  for (int k = 2; k <= n; k++)
  {
    floatResult /= k;
  }
  return floatResult;
}

/*
  Calculate each term in double.
  Instead calculating the factorial and the power and then divide by them, dividing the number one by one will provide better precision.
*/
double doubleTerm(int n)
{
  double doubleResult = 1;
  for (int i = n + 1; i <= 2 * n + 1; i++)
  {
    doubleResult *= i;
  }
  for (int j = 1; j <= 3 * n + 1; j++)
  {
    doubleResult /= 2;
  }
  if (n == 0)
  {
    return doubleResult;
  }
  for (int k = 1; k <= n; k++)
  {
    doubleResult /= k;
  }
  return doubleResult;
}

int main()
{
  float fTerms[20];
  double dTerms[80];
  // Generate float term array
  for (int i = 0; i < 20; i++)
  {
    fTerms[i] = floatTerm(i);
  }
  //Generate double term array
  for (int i = 0; i < 80; i++)
  {
    dTerms[i] = doubleTerm(i);
  }
  float floatForward = 0;
  float floatBackward = 0;
  double doubleForward = 0;
  double doubleBackward = 0;
  for (int i = 0; i < 20; i++)
  {
      floatForward += fTerms[i];
  }
  for (int i = 19; i >= 0; i--)
  {
      floatBackward += fTerms[i];
  }
  for (int i = 0; i < 80; i++)
  {
      doubleForward += dTerms[i];
  }
  for (int i = 79; i >= 0; i--)
  {
      doubleBackward += dTerms[i];
  }
  cout << "Float Results:\nforward answer = "
       << floatForward
       << "\nforward %error = "
       << 100 * (sqrt(2) - floatForward) / sqrt(2)
       << "\nbackward answer = "
       << floatBackward
       << "\nbackward %error = "
       << 100 * (sqrt(2) - floatBackward) / sqrt(2)
       << "\n\nDouble Results:\nforward answer: "
       << doubleForward
       << "\nforward %error = "
       << 100 * (sqrt(2) - doubleForward) / sqrt(2)
       << "\nbackward answer = "
       << doubleBackward
       << "\n\backward %error = "
       << 100 * (sqrt(2) - doubleBackward) / sqrt(2)
       << endl;
  return 1;
}