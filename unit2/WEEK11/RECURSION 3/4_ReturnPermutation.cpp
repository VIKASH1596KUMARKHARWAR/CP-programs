#include <iostream>
using namespace std;

int return_permutation(string input, string output[])
{

    // base case
    if (input.length() == 0 || input.length() == 1)
    {
        output[0] = input;
        return 1; // if " " or  single alphabet hai toh unka permutions whi h
    }

    string smallOutput[1000];
    int smallerOutputSize = return_permutation(input.substr(1), smallOutput);
    // retrieve a substring starting from index 1.....(leaving index zero)
    // and smallerOutput[] ke ander store kr dega

    char firstChar = input[0];
    int k = 0;
    for (int i = 0; i < smallerOutputSize; i++)
    // smallOutput ke each substring as a whole traverse kra....suppose 10 substring h in 10 rows and iterating each rows
    {
        for (int j = 0; j <= smallOutput[i].length(); j++)
        {
            output[k] = smallOutput[i].substr(0, j) + firstChar + smallOutput[i].substr(j);
            k++;
        }
    }

    return k;
}

int return_permutation_2(string input, string output[])
{
    if (input.length() == 0 || input.length() == 1)
    {
        output[0] = input;
        return 1; // if " " or  single alphabet hai toh unka permutions whi h
    }

    int k = 0;
    for (int i = 0; i < input.length(); i++)
    {
        char firrstChar = input[i];
        string remaingString = input.substr(0, i) + input.substr(i + 1); // hum hr baar  hamare input ke ith element ko rakhenge ...baaki se substring se o permtation aayegi esko  bs append kr denge

        string smallerOutput[1000];
        int smallerOutputSize = return_permutation_2(remaingString, smallerOutput);

        for (int j = 0; j < smallerOutputSize; j++)
        {
            output[k] = firrstChar + smallerOutput[j];
            k++;
        }
    }
    return k;
}

int main()
{
    string input = "abc";
    string output[1000];

    int k = return_permutation_2(input, output);

    for (int i = 0; i < k; i++)
    {
        cout << output[i] << endl;
    }
}