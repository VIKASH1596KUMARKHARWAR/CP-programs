
/*Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.

Note : The order of codes are not important. And input string does not contain 0s.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= Length of String S <= 10

Sample Input:
1123
Sample Output:
aabc
kbc
alc
aaw
kw

*/

#include <iostream>
#include <string>
using namespace std;

void getCodesHelper(string input, int index, string current, int &count, string output[])
{
    // Base case: If we have considered all characters in the string
    if (index == input.length())
    {
        output[count++] = current;
        return;
    }

    // Decode current digit as a single character ('a' to 'i' for '1' to '9')
    int digit = input[index] - '0';
    if (digit >= 1 && digit <= 9)
    {
        char ch = 'a' + digit - 1;
        getCodesHelper(input, index + 1, current + ch, count, output);
    }

    // Decode current two digits as a single character ('j' to 'z' for '10' to '26')
    if (index + 1 < input.length())
    {
        int twoDigits = stoi(input.substr(index, 2));
        if (twoDigits >= 10 && twoDigits <= 26)
        {
            char ch = 'a' + twoDigits - 1;
            getCodesHelper(input, index + 2, current + ch, count, output);
        }
    }
}

int getCodes(string input, string output[])
{
    int count = 0;
    getCodesHelper(input, 0, "", count, output);
    return count;
}
#include <iostream>
#include "solution.h"
using namespace std;

int main()
{
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for (int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
