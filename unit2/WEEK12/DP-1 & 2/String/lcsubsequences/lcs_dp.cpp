#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to compute the length of the Longest Common Subsequence (LCS)
int lcs_dp(const string &s, const string &t)
{
    int m = s.size();
    int n = t.size();

    // Create a 2D DP table initialized with 0
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // The length of the LCS is in dp[m][n]
    return dp[m][n];
}

int main()
{
    string s, t;
    cin >> s >> t;

    cout << lcs_dp(s, t) << '\n';

    return 0;
}
