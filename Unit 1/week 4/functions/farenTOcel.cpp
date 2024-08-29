#include <iostream>
using namespace std;

void printTable(int start, int end, int step) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output and don't return it.
     * Taking input is handled automatically.
     */
    
    int fahrenheit = start;
    while (fahrenheit <= end) {
        // Convert Fahrenheit to Celsius
        int celsius = (5.0 / 9) * (fahrenheit - 32);
        cout << fahrenheit << "\t" << celsius << endl;
        fahrenheit += step; // Increment Fahrenheit by the step size
    }
}

int main() {
    int start, end, step;
    cout << "Enter Start Fahrenheit Value: ";
    cin >> start;
    cout << "Enter End Fahrenheit Value: ";
    cin >> end;
    cout << "Enter Step Size: ";
    cin >> step;
    
    printTable(start, end, step);
    
    return 0;
}
