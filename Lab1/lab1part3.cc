#include <iostream>
#include <cmath>

using namespace std;

float floatTerm(int n) {
  float floatResult = 1;
  for (int i = 2; i <= 2 * n + 1; i++) {
    floatResult *= i;
  }
  for (int j = 1; j <= 3 * n + 1; j++) {
    floatResult /= 2;
  }
  if (n == 0) {return floatResult;}
  for (int k = 2; k <= n; k++) {
    floatResult /= k;
    floatResult /= k;
  }
  return floatResult;
}

double doubleTerm(int n) {
  double doubleResult = 1;
  for (int i = 1; i <= 2 * n + 1; i++) {
    doubleResult *= i;
  }
  for (int j = 1; j <= 3 * n + 1; j++) {
    doubleResult /= 2;
  }
  if (n == 0) {return doubleResult;}
  for (int k = 1; k <= n; k++) {
    doubleResult /= k;
    doubleResult /= k;
  }
  return doubleResult;
}

int main() {
  float fTerms[20];
  double dTerms[80];
  for (int i = 0; i < 20; i++) {
    fTerms[i] = floatTerm(i);
  }
  for (int i = 0; i < 80; i++) {
    dTerms[i] = doubleTerm(i);
  }
  float floatForward = 0;
  float floatBackward = 0;
  double doubleForward = 0;
  double doubleBackward = 0;
  for (int i = 0; i < 20; i++) {
    if (fTerms[i] != INFINITY) {
      floatForward += fTerms[i];
    }
  }
  for (int i = 19; i >= 0; i--) {
    if (fTerms[i] != INFINITY) {
      floatBackward += fTerms[i];
    }
  }
  for (int i = 0; i < 80; i++) {
    if (dTerms[i] != INFINITY) {
      doubleForward += dTerms[i];
    }
  }
  for (int i = 79; i >= 0; i--) {
    if (dTerms[i] != INFINITY) {
      doubleBackward += dTerms[i];
    }
  }
  cout << "Float Results:\nforward answer = "
        << floatForward 
        << "\nforward %error = " 
        << 100 * (sqrt(2) - floatForward) / sqrt(2)
        << "\nbackward answer = "
        << floatBackward
        << "\n\backward %error = "
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