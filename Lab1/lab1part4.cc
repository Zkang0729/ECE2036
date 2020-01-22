#include <iostream>

using namespace std;

int collatz(int n) {
  if (n % 2 == 0) {
    n /= 2;
  } else {
    n = 3 * n + 1;
  }
  return n;
}

int main() {
  int inputNum;
  int count = 1;
  cout << "Please enter a positive number (0 to exit): ";
  cin >> inputNum;
  if (inputNum < 0) {
    cout << "Error!" << endl;
  } else if (inputNum == 0) {
    cout << "Bye!" << endl;
  } else {
    cout << "Terms: " << inputNum << " -> ";
    while (inputNum > 1) {
      inputNum = collatz(inputNum);
      if (inputNum != 1) {
        cout << inputNum << " -> ";
      }
      count++;
    }
    cout << "1\nTotal number of terms: " << count << endl;
  }

  return 1;
}