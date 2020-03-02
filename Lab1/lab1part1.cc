/*
  Author: Zixuan Kang
  Date Last Modified: January 27, 2020  
  Organization: ECE2036 
  Description: A program to calculate the results of 7 n for n = 1, 2, 3, 4, ... using first the
  int type and then the long long type. An application showing the maximum value of n that can still store
  the results of 7 n in an int, and long long variables without overflow.
*/

#include <iostream>

using namespace std;

/*
  Computing the power of seven with an int type input and int output.
*/
int powerInt(int n)
{
  int intResult = 1;
  for (int i = 0; i < n; i++)
  {
    intResult *= 7;
  }
  return intResult;
}

/*
  Computing the power of seven with an long long type input and long long output.
*/
long long powerLongLong(int n)
{
  long long longlongResult = 1;
  for (int i = 0; i < n; i++)
  {
    longlongResult *= 7;
  }
  return longlongResult;
}

int main()
{
  int intResult = 0;
  int i = 1;
  long long longLongResult = 0;
  cout << "7 to the n power results using int" << endl;
  while (powerInt(i) / powerInt(i - 1) == 7) 
  // Since when there is an overflow, the value of the variable will change to the negative maximum it can go.
  {
    intResult = powerInt(i);
    cout << "7^" << i << " = " << intResult << endl;
    i++;
  }
  i = 1;
  cout << "7 to the n power results using long long" << endl;
  while (powerLongLong(i) / powerLongLong(i - 1) == 7)
  // Since when there is an overflow, the value of the variable will change to the negative maximum it can go.
  {
    longLongResult = powerLongLong(i);
    cout << "7^" << i << " = " << longLongResult << endl;
    i++;
  }
  return 0;
}