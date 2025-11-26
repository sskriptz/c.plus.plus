#include <iostream>
#include <vector>
using namespace std;

int findMax(vector<int> arr, int n) {
    if (n == 1) return arr[0]; // Base case: If array only has one element
    
    // Recursive case: compare last element with max of first n-1 elements
    return max(arr[n-1], findMax(arr, n-1));
}

int main() {
    
    vector<int> arr = {3, 5, 7, 2, 9, 1, 8};
    int n = arr.size();

    cout << "Maximum element in the array is: " << findMax(arr, n) << endl;
    return 0;

    return 0;
}
