#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
using namespace std;

long double computeArea(const vector<pair<float, float>> &points) {
    double sumLeft, sumRight = 0;
    for (int i = 0; i < points.size(); i++) {
        int next_i = (i + 1) % points.size();  
        sumLeft += (points[i].first * points[next_i].second);
        sumRight += (points[i].second * points[next_i].first);
    }
    return (abs(sumLeft - sumRight)) / 2.0L;
}

int main() {
    int sides;
    cout << "How many sides do you want your polygon to have? ";
    cin >> sides;

    vector<pair<float, float>> polygon;

    for (int i = 0; i < sides; i++) {
        float x, y;
        cout << "Enter x and y for point " << i + 1 << ": ";
        cin >> x >> y;
        polygon.push_back({x, y});
    }

    long double area = computeArea(polygon);
    cout << "Polygon area: " << area << endl;

    return 0;
}
