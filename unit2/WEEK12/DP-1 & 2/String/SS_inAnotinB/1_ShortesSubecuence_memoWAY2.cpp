#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

// Recursive helper function to find the shortest subsequence length
int solveHelper(const string &s, const string &v, int siA, int siB, vector<vector<int>> &dp)
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

    // Check if already computed
    if (dp[siA][siB] != -1)
    {
        return dp[siA][siB];
    }

    // Option 1: Skip the current character in `s`
    int option1 = solveHelper(s, v, siA + 1, siB, dp);

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
        return dp[siA][siB] = 1;
    }

    // If `s[siA]` is found in `v`, consider this character and proceed
    int option2 = 1 + solveHelper(s, v, siA + 1, indexB + 1, dp);

    // Take the minimum of the two options
    int ans = min(option1, option2);
    return dp[siA][siB] = ans;
}

// Function to initialize DP table and call the helper
int solve(const string &s, const string &v)
{
    int m = s.length();
    int n = v.length();

    // Initialize DP table
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    int ans = solveHelper(s, v, 0, 0, dp);

    // Return result, converting INT_MAX to -1 as per the problem's specification
    return ans == 1001 ? -1 : ans;
}

int main()
{
    string S = "babab";
    string V = "babba";
    int result = solve(S, V);
    cout << "Minimum length of subsequence not in V: " << result << endl;
    return 0;
}
