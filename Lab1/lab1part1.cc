#include <iostream>
#include <stdlib.h>

using namespace std;

int powerInt(int n) {
    int intResult = 7;
    for (int i = 1; i < n; i++) {
        intResult *= 7;
    }
    return intResult;
}

long long powerLongLong(int n) {
    long long longlongResult = 7;
    for (int i = 1; i < n; i++) {
        longlongResult *= 7;
    }
    return longlongResult;
}

int main() {
    int intResult = 0;
    int i = 1;
    long long longLongResult = 0;
    cout << "7 to the n power results using int\n" << endl;
    while (intResult >= 0) {
        intResult = powerInt(i);
        cout << "7^" << i << " = " << intResult << endl;
        i++;
    }
    i = 1;
    cout << "7 to the n power results using long long" << endl;
    while (longLongResult >= 0) {
        longLongResult = powerLongLong(i);
        cout << "7^" << i << " = " << longLongResult << endl;
        i++;
    }
    return 0;
}