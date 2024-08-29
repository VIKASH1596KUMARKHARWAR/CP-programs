#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

// Helper function to find the length of the shortest subsequence of `s` that is not a subsequence of `v`
int solve(const string &s, const string &v, int siA = 0, int siB = 0)
{
    // Base cases
    if (siA == s.length())
    {
        return 1001; // Constrain given is 1000 is the size of string
    }
    if (siB == v.length())
    {
        return 1; // If `v` is exhausted, return 1 (indicating a subsequence not found in `v`)
    }

    // Option 1: Skip the current character in `s`
    int option1 = solve(s, v, siA + 1, siB);

    // Option 2: Include the current character in `s`
    int indexB = -1;
    for (int i = siB; i < v.length(); i++)
    {
        if (v[i] == s[siA])
        {
            indexB = i;
            break;
        }
    }

    // If we can't find s[siA] in v starting from index siB, then this character cannot be matched in `v`
    if (indexB == -1)
    {
        return 1;
    }

    // If `s[siA]` is found in `v`, consider this character and proceed
    int option2 = 1 + solve(s, v, siA + 1, indexB + 1);

    // Return the minimum of the two options
    return min(option1, option2);
}