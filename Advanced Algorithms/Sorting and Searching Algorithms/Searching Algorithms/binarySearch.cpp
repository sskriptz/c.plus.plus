#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size()-1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else if (arr[mid] > target) {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {

    vector<int> myArray = {2, 5, 6, 10, 12, 13, 24, 56};
    cout << binarySearch(myArray, 5) << endl;

    return 0;
}
