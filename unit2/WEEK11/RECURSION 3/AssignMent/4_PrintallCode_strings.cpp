#include <iostream>
#include <string>
using namespace std;

void printAllPossibleCodesHelper(string input, int index, string current)
{
    // Base case: If we have considered all characters in the string
    if (index == input.length())
    {
        cout << current << endl;
        return;
    }

    // Decode current digit as a single character ('a' to 'i' for '1' to '9')
    int digit = input[index] - '0';
    if (digit >= 1 && digit <= 9)
    {
        char ch = 'a' + digit - 1;
        printAllPossibleCodesHelper(input, index + 1, current + ch);
    }

    // Decode current two digits as a single character ('j' to 'z' for '10' to '26')
    if (index + 1 < input.length())
    {
        int twoDigits = stoi(input.substr(index, 2));
        if (twoDigits >= 10 && twoDigits <= 26)
        {
            char ch = 'a' + twoDigits - 1;
            printAllPossibleCodesHelper(input, index + 2, current + ch);
        }
    }
}

void printAllPossibleCodes(string input)
{
    printAllPossibleCodesHelper(input, 0, "");
}
