/*If the character is a lowercase English alphabet ('a' to 'z') or a digit ('0' to '9'), we increment the respective count variables (charCount or digitCount) and reset the isWhitespace flag to false.
If the character is a whitespace character (space ' ', tab '\t', or newline '\n'), we increment spaceCount only if it's the first whitespace character encountered or if it's consecutive whitespace. We then set the isWhitespace flag to true to indicate that the previous character was a whitespace.*/
#include <iostream>
using namespace std;

int main() {
    char ch;
    int charCount = 0, digitCount = 0, spaceCount = 0;
    bool isWhitespace = false; // Flag to track consecutive whitespace characters
    
    // Read characters until '$' is encountered
    while (cin.get(ch) && ch != '$') {
        if ((ch >= 'a' && ch <= 'z')) { // Check for lowercase English alphabet
            charCount++;
            isWhitespace = false; // Reset the whitespace flag
        } else if (ch >= '0' && ch <= '9') { // Check for digit
            digitCount++;
            isWhitespace = false; // Reset the whitespace flag
        } else if (ch == ' ' || ch == '\t' || ch == '\n') { // Check for whitespace
            // Check if it's the first whitespace character or consecutive whitespace
            if (!isWhitespace) {
                spaceCount++;
                isWhitespace = true; // Set the whitespace flag
            }
        }
    }
    
    // Output counts
    cout << charCount << " " << digitCount << " " << spaceCount << endl;

    return 0;
}
