
// RECURSIVE WAY GOING OT BE BADDEST (REF. with LCsubsecquence   AND do by Dp)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Helper function for recursion with memoization
int lcSubstringRecursive(const string &s1, const string &s2, int m, int n, vector<vector<int>> &dp)
{
    // Base case: if indices are out of bounds
    if (m == 0 || n == 0)
        return 0;

    // Return the memoized result if available
    if (dp[m][n] != -1)
        return dp[m][n];

    // If characters match
    if (s1[m - 1] == s2[n - 1])
    {
        dp[m][n] = lcSubstringRecursive(s1, s2, m - 1, n - 1, dp) + 1;
    }
    else
    {
        dp[m][n] = 0;
    }

    return dp[m][n];
}

// Function to find the maximum length of Longest Common Substring
int longestCommonSubstr(const string &s1, const string &s2)
{
    int m = s1.size();
    int n = s2.size();
    int maxLength = 0;

    // Create a memoization table initialized to -1
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    // Iterate through each character of s1 and s2
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            maxLength = max(maxLength, lcSubstringRecursive(s1, s2, i, j, dp));
        }
    }

    return maxLength;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    cout << longestCommonSubstr(s1, s2) << '\n';

    return 0;
}
