#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double evaluate_polynomial(double x, const vector<double>& coeff_vector) {
    double result = 0.0;

    for (size_t i = 0; i < coeff_vector.size(); i++) {
        double c_i = coeff_vector[i];
        double z = pow(x, i);
        double term_val = c_i * z;
        result += term_val;
    };

    return result;
};

double riemann_sum_func(double lowerBound, double upperBound, int subIntervals, const vector<double>& coeffs) {
    
    if (subIntervals <= 0 || lowerBound >= upperBound) {
        throw invalid_argument("Invalid inputs: n must be positive and a < b.");
    };
    
    double dx = (upperBound - lowerBound) / subIntervals;
    double total_area = 0.0;
    double current_x = lowerBound;
    double total_height = 0.0;
    
    for (int i = 0; i < subIntervals; i++) {
        current_x = lowerBound + (double)i * dx;
        double height = evaluate_polynomial(current_x, coeffs);
        total_height += height;
    };
    
    double riemann_sum =  total_height * dx;
    return riemann_sum;
    
};

int main() {

    double a, b;
    int n;
    int degree;

    cout << "What is the degree of the polynomial? ";
    if (!(cin >> degree) || degree < 0) return 1;

    vector<double> coefficients;
    cout << "Enter the coefficients for all the terms:\n";
    for (int i = 0; i <= degree; i++) {
        double coeff;
        cout << "Enter coefficient c" << i << " (for x^" << i << "): ";
        if (!(cin >> coeff)) return 1;
        coefficients.push_back(coeff);
    }
    
    cout << "Enter lower bound (a): ";
    cin >> a;
    
    cout << "Enter upper bound (b): ";
    cin >> b;
    
    cout << "Enter number of subintervals (n): ";
    cin >> n;

    try {
        double result = riemann_sum_func(a, b, n, coefficients);
        cout << "Riemann Sum Result: " << result << endl;
    } catch (const exception e) {
        cerr << "Execution Error: "  << e.what() << endl;
    }

    return 0;
}
