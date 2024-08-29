
#include <string>
#include <climits>
#include <vector>
using namespace std;

int solve(const string &s, const string &v)
{
    int n = s.length();
    int m = v.length();

    // Initialize dp and next tables
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    vector<vector<int>> next(n + 1, vector<int>(m + 1));

    // Compute next occurrence of characters in `s` within `v`
    for (int i = 0; i < n; ++i)
    {
        int previous = -1; // Track the last occurrence of s[i] in `v`
        for (int j = 0; j < m; ++j)
        {
            if (s[i] == v[j])
            {
                previous = j;
            }
            next[i + 1][j + 1] = previous;
        }
    }

    // Initialize dp values
    for (int i = 1; i <= n; ++i)
    {
        dp[i][0] = 1; // If `v` is empty, any non-empty `s` subsequence is valid
    }
    for (int j = 0; j <= m; ++j)
    {
        dp[0][j] = 1e9; // If `s` is empty, we can't form a valid subsequence
    }

    // Fill the dp table
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (next[i][j] == -1)
            {
                // Character s[i-1] does not appear in v[0..j-1], hence this character can be part of the subsequence
                dp[i][j] = 1;
            }
            else
            {
                // Compute the minimum value by considering both possibilities:
                // 1. Exclude s[i-1] from the subsequence
                // 2. Include s[i-1] and use the position where s[i-1] appears in v[0..j-1]
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i - 1][next[i][j]]);
            }
        }
    }

    // Return result or -1 if no valid subsequence found
    return dp[n][m];
}
#include <iostream>
int main()
{
    string s = "babab";
    string v = "babba";
    cout << solve(s, v) << endl;
    return 0;
}