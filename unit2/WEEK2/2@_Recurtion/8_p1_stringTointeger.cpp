#include <iostream>
using namespace std;

// Helper function to calculate the length of a null-terminated string
int length(char input[]) {
    if (input[0] == '\0') {
        return 0;
    }
    return 1 + length(input + 1);
}

// Recursive function to convert numeric string to integer
int stringToNumber(char input[], int len) {
    // Base case: if the string length is 0, return 0
    if (len == 0) {
        return 0;
    }
    
    // Convert the first character to integer
    int first_digit = input[0] - '0';
    
    // Recursively convert the rest of the string
    int recursive_result = stringToNumber(input + 1, len - 1);
    
    // Construct the number
    int result = first_digit;
    for (int i = 0; i < len - 1; ++i) {
        result *= 10;
    }
    result += recursive_result;
    
    return result;
}

// Wrapper function to call stringToNumber with length calculation
int stringToNumber(char input[]) {
    int len = length(input);
    return stringToNumber(input, len);
}

int main() {
    char input_str1[] = "00001231";
    char input_str2[] = "12567";
    
    int output1 = stringToNumber(input_str1);
    int output2 = stringToNumber(input_str2);
    
    cout << "Input: " << input_str1 << "\tOutput: " << output1 << endl;
    cout << "Input: " << input_str2 << "\tOutput: " << output2 << endl;
    
    return 0;
}
