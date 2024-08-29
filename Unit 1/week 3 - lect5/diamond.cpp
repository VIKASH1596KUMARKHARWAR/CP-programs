#include <iostream>
using namespace std;

int main() {
    int rows ;
    cin >> rows;
    int i = 0;

    // Loop through each row
    while (i < rows) {
        // For the upper half of the diamond (including the middle line)
        if (i <= (rows / 2)) {
            // Print spaces before the asterisks
            int j = 0;
            while (j < (rows / 2) - i) {
                cout << " ";
                j++;
            }
            // Print asterisks for this row
            int k = 0;
            while (k < 2 * i + 1) {
                cout << "*";
                k++;
            }
        } 
        // For the lower half of the diamond
        else {
            // Print spaces before the asterisks
            int j = 0;
            while (j < i - (rows / 2)) {
                cout << " ";
                j++;
            }
            // Print asterisks for this row
            int k = 0;
            while (k < 2 * (rows - i) - 1) {
                cout << "*";
                k++;
            }
        }
        // Move to the next line after printing the row
        cout << endl;
        i++; // Move to the next row
    }
    return 0;
}
