#include<iostream>
using namespace std;

int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cout << "Enter the value of n to find the nth Fibonacci number: ";
    cin >> n;
    
    // Print Fibonacci numbers from 0th to (n)th
    for (int i = 0; i <= n; i++) {
        cout << fibonacci(i) << " ";
    }
    
    // Print the nth Fibonacci number
    cout << "\nThe " << n << "th Fibonacci number is: " << fibonacci(n) << endl;

    return 0;
}
