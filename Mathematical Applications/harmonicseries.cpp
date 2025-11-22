#include <iostream>
using namespace std;

long double computeSum(int n) {
    long double totalSum = 0;
    for (long double i = 1; i <= n; i++) {
        totalSum += (1.0 / i);
    }
    return totalSum;
}

int findTerms(int n) {
    long long terms = 0;
    long double totalSum2 = 0;
    long long step = 1;

    while (totalSum2 <= n) {
        totalSum2 += (1.0 / step);
        step++;
        terms++;
    }
    return terms;
}

int main() {

    int userChoice;
    cout << "Do you want to 1. Compute the sum of the first n terms or 2. Find out how many terms it take to approach a certain value: ";
    cin >> userChoice;

    if (userChoice == 1) {
        int termNumber;
        cout << "Enter number of terms: ";
        cin >> termNumber;

        cout << "Sum: " << computeSum(termNumber) << endl;
    } else if (userChoice == 2) {
        int finalNumber;
        cout << "Enter the targeted number: ";
        cin >> finalNumber;

        cout << "Number of terms required: " << findTerms(finalNumber) << endl;
    }

    return 0;
}
