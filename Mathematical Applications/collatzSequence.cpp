#include <iostream>
#include <vector>
using namespace std;

vector<int> collatz(int n) {
    int x = n;
    vector<int> sequence = {x};

    while (x != 1) {
        if (x % 2 == 0) {
            x /= 2;
            sequence.push_back(x);
        } else {
            x = 3*x + 1;
            sequence.push_back(x);
        }
    }
    return sequence;
}

int main() {

    vector<int> mySequence = collatz(19);

    for (size_t i = 0; i < mySequence.size(); i++) {
        cout << mySequence[i];
        if (i != mySequence.size() - 1) {
            cout << ", ";
        }
    }
    
    cout << endl;
    cout << "Steps: " << mySequence.size() - 1 << endl << endl;

    return 0;
}
