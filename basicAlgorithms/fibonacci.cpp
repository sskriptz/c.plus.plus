#include <iostream>
#include <vector>
using namespace std;

void fibonnaciIt(int terms) {
    long long a = 0;
    long long b = 1;
    vector<long long> sequence = {0, 1};

    for (int i = 0; i < terms-2; i++) {
        long long new_val = a + b;
        sequence.push_back(new_val);
        a = b;
        b = new_val;
    }

    for (long long n : sequence) {
        cout << n << " ";
    }
    cout << endl;
}

int main() {
    int input;
    cout << "How many n fibonnaci terms would you like to generate? ";
    cin >> input;

    fibonnaciIt(input);

    return 0;
};
