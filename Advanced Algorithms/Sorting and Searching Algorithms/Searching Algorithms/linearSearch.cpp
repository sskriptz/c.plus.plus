#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int> arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;  // return index if found
        }
    }
    return -1; // not found
}

int main() {
    vector<int> arr = {4, 7, 1, 9, 5};
    int target = 9;

    int index = linearSearch(arr, target);
    if (index != -1) {
        cout << "Found at index: " << index << endl;
    } else {
        cout << "Not found" << endl;
    }
}
