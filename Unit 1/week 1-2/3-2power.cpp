#include <iostream>
#include <iomanip>
using namespace std;

double power(double x, int n) {
    if (n == 0)
        return 1;
    
    double halfPower = power(x, n / 2);
    
    if (n % 2 == 0)
        return halfPower * halfPower;
    else
        return x * halfPower * halfPower;
}

int main() {
    double x;
    int n;
    cout << "Enter the base (x): ";
    cin >> x;
    cout << "Enter the exponent (n): ";
    cin >> n;

    double result = 1;

    if (n < 0) {
        x = 1 / x;
        n = -n;
    }

    result = power(x, n);

    // Set the output format to fixed-point notation with 0 decimal places
    cout << fixed << setprecision(0);
    cout << "Result: " << result << endl;

    return 0;
}
