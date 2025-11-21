#include <iostream>
#include <cmath>
#include <vector>
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
        }
    }
    
    return true;
}

vector<int> pfactorize(int n) {
    vector<int> pfactors;
    for (int i = 2; i <= sqrt(n); i++) {
        if (isPrime(i)) {
            while (n % i == 0) {
                pfactors.push_back(i);
                n /= i;
            }
        }
    }
    return pfactors;
}

int main() {
    
    vector<int> factorsList = pfactorize(75);

    for (size_t i = 0; i < factorsList.size(); i++) {
        cout << factorsList[i];
        if (i != factorsList.size() - 1) {
            cout << "*";
        }
    }

    cout << endl;

    return 0;    
}
