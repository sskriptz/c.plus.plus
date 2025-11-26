#include <iostream>
using namespace std;

void reverse(string &s, int start, int end) {
    if (start >= end) return;
    swap(s[start], s[end]);
    reverse(s, start + 1, end - 1);
}

int main() {

    string myString = "hello world";
    reverse(myString, 0, myString.length()-1);
    cout << "Reversed: " << myString << endl;

    return 0;
}
