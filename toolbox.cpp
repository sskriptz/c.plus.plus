// C++ USEFUL ALGORITHMS/FUNCTIONS!!!

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <sstream> // Used for building strings
#include <numeric> // Useful for accumulation in vectors
using namespace std;

// 1. Reverse a string

string reverseString(string s) {
    reverse(s.begin(), s.end());
    return s;
}

// 2. Reverse a number

int reverseNumber(int n) {
    string s = to_string(n);
    reverse(s.begin(), s.end());
    n = stoi(s);
    return n;
}

// 3. Searching through a string

void stringSearch(string s, char target) {
    bool found = false;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == target) {
            found = true;
            cout << "Found at index " << i << endl;
        }
    }

    if (!found) {
        cout << "Character not in string" << endl;
    }
}

// 4. Sum of digits

int sumDigits(int n) {
    string s = to_string(n);
    int sum = 0;
    for (char c : s) {
        if (isdigit(c)) {
            sum += c - '0';
            // why "- 0"?: '0' has ASCII value 48, '1' is 49, … '9' is 57.
        }
    }
    return sum;
}

// 5. Check if a string is a palindrome

bool isPalindrome(int n) {
    string s1 = to_string(n);
    string s2 = to_string(n);
    reverse(s2.begin(), s2.end());

    if (s1 == s2) {
        return true;
    } else {
        return false;
    }
}

// ---------------VECTOR OPERATIONS---------------

// 1. Print everything in a vector (VECTOR --> STRING)
    // a. generic - REQUIRES TEMPLATES!!!
template <typename T>
string printVector(const vector<T>& v) {
    stringstream ss1; // To build a string you can return later
    for (size_t i = 0; i < v.size(); i++) {
        ss1 << v[i];
        if (i != v.size()-1) {
            ss1 << ", ";
        }
    }
    return ss1.str();
}

    // b. Example of converting a vector to string specifically

string printStringVector(const vector<string> v) {
    stringstream ss2;
    for (size_t i = 0; i < v.size(); i++) {
        ss2 << v[i];
        if (i != v.size()-1) {
            ss2 << ", ";
        }
    }
    return ss2.str();
}

// 2. Turn a string/number to a vector of characters/digits
    // a. Do a string:

vector<char> stringToVector(string s) {
    vector<char> v;
    for (char c : s) {
        v.push_back(c);
    }
    return v;
}

    // b. Do a number:

vector<int> intToDigits(int n) {
    vector<int> digits;
    string s = to_string(n);

    for (char c : s) {
        if (isdigit(c)) {
            digits.push_back(c - '0');
        }
    }
    return digits;
}


// -----------------------------------------------

int main() {
    // IN ORDER

    // 1. cout << reverseString("test") << endl;
    // 2. cout << reverseNumber(12345) << endl;
    // 3. stringSearch("violin", 'i');
    // 4. cout << sumDigits(12345) << endl;
    // 5. cout << isPalindrome(141) << endl;

    // ---------------VECTORS-------------------

    // 1a. vector<int> nums = {1,2,3,4};
    // vector<string> words = {"apple", "banana"};
    // cout << printVector(nums) << endl;
    // cout << printVector(words) << endl;

    // 1b. vector<string> items = {"the", "quick", "brown", "fox"};
    // cout << printStringVector(items) << endl;

    // 2a. string s = "coding";
    // vector<char> letterVector = stringToVector(s);

    // for (char c : letterVector) {
    //     cout << c << " ";
    // }

    // 2b. vector<int> d = intToDigits(49281);

    // for (int x : d) {
    //     cout << x << " ";
    // }

    return 0;
}
