#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> pascal(int n) {
    vector<vector<int>> triangle(n);

    triangle[0] = {1};
    triangle[1] = {1, 1};

    for (int i = 2; i < n; i++) {
        triangle[i].push_back(1);
        for (int j = 1; j < i; j++) {
            triangle[i].push_back(
                triangle[i-1][j-1] + triangle[i-1][j]
            );
        }
        triangle[i].push_back(1);
    }

    return triangle;
}

int main() {

    vector<vector<int>> matrix = pascal(10);

    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
