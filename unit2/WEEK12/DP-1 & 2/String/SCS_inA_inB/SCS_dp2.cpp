// syntactical sugar
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

        // Create a DP table initialized with 0
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Fill the DP table to find the length of the Longest Common Subsequence (LCS)
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
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

        // Use DP table to build the SCS
        return buildSCS(str1, str2, n, m, dp);
    }

private:
    string buildSCS(const string &str1, const string &str2, int i, int j, const vector<vector<int>> &dp)
    {
        string scs;

        // Trace back to construct the SCS
        while (i > 0 && j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                scs += str1[i - 1];
                --i;
                --j;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                scs += str1[i - 1];
                --i;
            }
            else
            {
                scs += str2[j - 1];
                --j;
            }
        }

        // Add remaining characters of str1 or str2
        while (i > 0)
        {
            scs += str1[i - 1];
            --i;
        }
        while (j > 0)
        {
            scs += str2[j - 1];
            --j;
        }

        // The scs string is built in reverse order
        reverse(scs.begin(), scs.end());

        return scs;
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
