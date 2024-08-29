/*Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.
A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

//like en dono string ka baap nikalna h
Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation:
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
Example 2:

Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Finding the LCS
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Recursive helper function to build SCS
        return buildSCS(str1, str2, n, m, dp);
    }

private:
    string buildSCS(const string &str1, const string &str2, int i, int j, const vector<vector<int>> &dp)
    {
        // Base cases
        if (i == 0)
            return str2.substr(0, j);
        if (j == 0)
            return str1.substr(0, i);

        // If characters are the same
        if (str1[i - 1] == str2[j - 1])
        {
            return buildSCS(str1, str2, i - 1, j - 1, dp) + str1[i - 1];
        }
        else
        {
            // Choose the better option
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                return buildSCS(str1, str2, i - 1, j, dp) + str1[i - 1];
            }
            else
            {
                return buildSCS(str1, str2, i, j - 1, dp) + str2[j - 1];
            }
        }
    }
};

int main()
{
    Solution sol;
    string str1 = "abac";
    string str2 = "cab";
    cout << "Shortest Common Supersequence: " << sol.shortestCommonSupersequence(str1, str2) << endl;
    return 0;
}

/*If i (index for str1) is 0, then the SCS is simply the remaining substring of str2 from index 0 to j.
If j (index for str2) is 0, then the SCS is simply the remaining substring of str1 from index 0 to i*/

/*Apprach::  common guys firs(lcs) - just taken once
length of scs is n+m -lcs*/
/*DP Table Construction:

The dp table is filled to find the length of the LCS for all substrings of str1 and str2.
Building the SCS:

Start from dp[n][m] and trace back through the DP table to build the SCS.
If str1[i-1] == str2[j-1], add that character to the SCS and move diagonally.
If the characters are different, choose the direction with the higher value to ensure that the SCS is constructed correctly.
Final Steps:

Add remaining characters of str1 or str2 if one string is exhausted before the other.
Reverse the result because we build the SCS from end to start*/