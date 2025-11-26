#include <iostream>
#include <vector>
using namespace std;

int sum(vector<int> arr, int n) {
    if (n == 0) return 0;
    return arr[n-1] + sum(arr, n-1);
}

int main() {

    vector<int> arr = {1, 4, 5, 2, 7, 8, 1, 9};
    cout << sum(arr, arr.size()) << endl;

    return 0;
}
