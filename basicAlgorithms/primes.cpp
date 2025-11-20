#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n == 2) {
        return true;
    }

    if (n < 2 || n % 2 == 0) {
        return false;
    }

    for (int i = 3; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        } else {
            return true;
        }
    }
}

int main() {
    int num;
    cout << "Enter a number to check if it is prime: ";
    cin >> num;

    bool result = isPrime(num);
    cout << result << endl;

    return 0;
};
