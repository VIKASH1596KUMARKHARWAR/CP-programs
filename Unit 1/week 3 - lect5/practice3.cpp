/* 
        	1
           232
          34543
         4567654
        567898765

*/

#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N; // Read the number of rows from the user
    
    int i = 1; // Start from row 1
    while (i <= N) {
        // Print leading spaces
        int spaces = N - i;
        while (spaces > 0) {//OLD LOGING IS ALSO CORRECT 
            cout << " "; // One space for alignment
            spaces--;
        }
        
        // Print increasing sequence
        int num = i;
        int j = 0;
        while (j < i) {
            cout << "*";
            num++;
            j++;
        }
        
        // Print decreasing sequence
        num -= 2; // Adjust number to start the decreasing sequence
        j = 0;
        while (j < i - 1) {
            cout << "*";
            num--;
            j++;
        }
        
        cout << endl; // Move to the next line after each row
        i++;
    }
    
    return 0;
}
