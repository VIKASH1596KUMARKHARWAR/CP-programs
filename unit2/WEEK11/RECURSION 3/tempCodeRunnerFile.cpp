#include <iostream>
using namespace std;

int subSequence(string input, string output[])
{
    if (input.empty())
    {
        output[0] = " ";
        return 1;
    }

    string smallString = input.substr(1);
    int smallOutputsize = subSequence(smallString, output);
    for (int i = 0; i < smallOutputsize; i++)
    {
        output[i + smallOutputsize] = input[0] + output[i];
    }
    return 2 * smallOutputsize;
}

int main()
{
    string input;
    cin >> input;
    string *output = new string[1000];
    int count = subSequence(input, output);
    for (int i = 0; i < count; i++)
    {
        cout << output[i] << endl;
    }
}