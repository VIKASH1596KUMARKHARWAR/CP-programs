#include <iostream>
#include <vector>
#include <string>

// Function to generate all subsequences of a string
void generateSubsequences(const std::string &input, std::vector<std::string> &output, int index = 0, std::string current = "")
{
    // Base case: when index reaches end of string
    if (index == input.length())
    {
        output.push_back(current); // Add current subsequence to output

        return;
    }

    // Recursive case: include current character
    generateSubsequences(input, output, index + 1, current + input[index]);

    // Recursive case: exclude current character
    generateSubsequences(input, output, index + 1, current);
}

int main()
{
    std::string input;
    std::cout << "Enter a string: ";
    std::cin >> input;

    std::vector<std::string> output;
    generateSubsequences(input, output);

    // Print all subsequences
    std::cout << "All subsequences:" << std::endl;
    for (const auto &subseq : output)
    {
        std::cout << subseq << std::endl;
    }

    return 0;
}
