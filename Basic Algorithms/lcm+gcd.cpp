#include <iostream>
using namespace std;

int findGCD(int a, int b) {
    int gcd;
    bool x = false;
    if (a > b) {x = true;}

    if (x) {
        for (int i = 1; i <= b; i++) {
            if (a % i == 0 && b % i == 0) {
                gcd = i;
            }
        }
    } else {
        for (int i = 1; i <= a; i++) {
            if (a % i == 0 && b % i == 0) {
                gcd = i;
            }
        }
    }

    return gcd;
}

int findLCM(int a, int b) {
    return (abs(a * b) / findGCD(a, b));
}

int main() {
    cout << findLCM(12, 8) << endl;
    return 0;
}
