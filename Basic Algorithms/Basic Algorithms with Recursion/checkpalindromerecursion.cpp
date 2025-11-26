#include <iostream>
using namespace std;

bool isPalindrome(string s, int start, int end) {
    if (start >= end) return true;
    if (s[start] != s[end]) return false;
    return isPalindrome(s, start + 1, end - 1); // Recurse on inner substring
}

int main() {

    string myString = "racecar";
    cout << isPalindrome(myString, 0, myString.length()-1) << endl;

    return 0;
}
