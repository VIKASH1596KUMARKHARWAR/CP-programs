#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter the number of terms in the Fibonacci series: ";
    cin >> N;

    // Check for invalid input
    if (N <= 0) {
        cout << "Input should be a positive integer." << endl;
    } else if (N == 1) {
        cout << "Fibonacci series: 1" << endl;
    } else {
        int first_number = 1;
        int second_number = 1;

        cout << "Fibonacci series: " << first_number << " " << second_number;

        for (int i = 3; i <= N; ++i) {
            int fib_number = first_number + second_number;
            cout << " " << fib_number;
            first_number = second_number;
            second_number = fib_number;
        }

    }

    return 0;
}
