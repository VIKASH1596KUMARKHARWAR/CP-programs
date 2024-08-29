#include <iostream>
#include <string>

// Function to return string options corresponding to a numeric key on a keypad
std::string getString(int d)
{
    switch (d)
    {
    case 2:
        return "abc";
    case 3:
        return "def";
    case 4:
        return "ghi";
    case 5:
        return "jkl";
    case 6:
        return "mno";
    case 7:
        return "pqrs";
    case 8:
        return "tuv";
    case 9:
        return "wxyz";
    default:
        return "";
    }
}

// Function to generate keypad combinations recursively
int keyPad(int input, std::string output[])
{
    // Base case: When input becomes 0, initialize output with an empty string and return 1
    if (input == 0)
    {
        output[0] = "";
        return 1;
    }

    // Extract last digit
    int lastDigit = input % 10;
    // Remaining number after removing last digit
    int smallnumber = input / 10;

    // Recursive call to get the number of combinations for remaining number
    int smallOutputSize = keyPad(smallnumber, output);

    // Get the string options for the current last digit
    std::string options = getString(lastDigit);
    int optionsLength = options.length();

    // Generate new combinations by appending each character from options to existing output

    for (int i = 0; i < optionsLength - 1; ++i)
    {
        for (int j = 0; j < smallOutputSize; ++j)
        {
            output[j + (i + 1) * smallOutputSize] = output[j];
        }
    }

    int k = 0; // appending last digit
    for (int i = 0; i < optionsLength; ++i)
    {
        for (int j = 0; j < smallOutputSize; ++j)
        {
            output[k] += options[i];
            ++k;
        }
    }

    return smallOutputSize * optionsLength;
}

int main()
{
    int n;
    std::cout << "Enter a number (keypad digits): ";
    std::cin >> n;

    std::string output[1000]; // Assuming a maximum of 1000 combinations
    int count = keyPad(n, output);

    std::cout << "All possible combinations:" << std::endl;
    for (int i = 0; i < count; ++i)
    {
        std::cout << output[i] << std::endl;
    }

    return 0;
}
