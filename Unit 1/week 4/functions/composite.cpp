#include <iostream>
using namespace std;

// Function to check if a single number is composite
bool is_composite(int num) {
    if (num <= 1) return false; // Numbers less than or equal to 1 are not composite
    for (int divisor = 2; divisor * divisor <= num; divisor++) {
        if (num % divisor == 0) {
            return true; // If num has a divisor other than 1 and itself, it is composite
        }
    }
    return false; // If no such divisor is found, it is not composite
}

int main() {
    int n;
    cin >> n;

    cout << "Composite numbers up to " << n << ": ";
    for (int i = 2; i <= n; i++) {
        if (is_composite(i))
            cout << i << " ";
    }
    cout << endl;

    return 0;
}
