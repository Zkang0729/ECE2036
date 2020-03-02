/*
  Author: Zixuan Kang
  Date Last Modified: January 27, 2020  
  Organization: ECE2036 
  Description: Calculate input n with the following formula:
  - n → n/2 (if n is even, divide it by 2)
  - n → 3n + 1 (if n is odd, then multiple it by 3 and then add one)
  until it's one.
*/

#include <iostream>

using namespace std;

/*
  - n → n/2 (if n is even, divide it by 2)
  - n → 3n + 1 (if n is odd, then multiple it by 3 and then add one)
*/
int collatz(int n)
{
  if (n % 2 == 0)
  {
    n /= 2;
  }
  else
  {
    n = 3 * n + 1;
  }
  return n;
}

int main()
{
  int inputNum;
  int count = 1;
  int row = 1;
  cout << "Please enter a positive number (0 to exit): ";
  cin >> inputNum;
  if (inputNum < 0)
  {
    cout << "Error!" << endl;
  }
  else if (inputNum == 0)
  {
    cout << "Bye!" << endl;
  }
  else
  {
    cout << "Terms: " << inputNum << " -> ";
    while (inputNum > 1)
    {
      inputNum = collatz(inputNum);
      if (inputNum != 1)
      {
        cout << inputNum << " -> ";
      }
      count++;
      row++;
      if (row >= 10)
      {
        row -= 10;
        cout << "\n";
      }
    }
    cout << "1\nTotal number of terms: " << count << endl;
  }

  return 1;
}