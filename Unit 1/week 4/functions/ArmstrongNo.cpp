#include <iostream>
#include <cmath>
using namespace std;

bool isArmstrong(int n) {
    int original = n;
    int sum = 0;
    int k = 0;

    // Determine the number of digits in n
    int temp = n;
    while (temp != 0) {
        temp /= 10;
        k++;
    }

    // Calculate the sum of the digits raised to the power of k
    temp = n;
    while (temp != 0) {
        int digit = temp % 10;
        sum += pow(digit, k);
        temp /= 10;
    }

    // Check if the sum is equal to the original number
    return (sum == original);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isArmstrong(n)) {
        cout << n << " is an Armstrong number." << endl;
    } else {
        cout << n << " is not an Armstrong number." << endl;
    }

    return 0;
}
