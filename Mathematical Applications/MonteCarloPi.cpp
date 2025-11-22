#include <iostream>
#include <random>
#include <ctime>
using namespace std;

long double approximate(int throws) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<long double> dist(0.0, 1.0);
    long double working_points = 0.0;

    for (int i = 0; i < throws; i++) {
        long double x = dist(gen);
        long double y = dist(gen);

        if (x*x + y*y <= 1) {
            working_points++;
        }
    }

    return 4 * (working_points / throws);
}

int main() {

    int userThrowNum;
    cout << "How many throws do you want to do? ";
    cin >> userThrowNum;

    cout << "Your Pi approximation is: " << approximate(userThrowNum) << endl;

    return 0;
}
