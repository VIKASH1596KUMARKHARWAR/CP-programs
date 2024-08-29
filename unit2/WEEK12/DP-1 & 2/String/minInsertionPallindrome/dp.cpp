#include <vector>
#include <string>
#include <algorithm>

class Solution
{
public:
    int minInsertions(string s)
    {
        int n = s.size();
        if (n == 0)
            return 0;
        int lpsLength = longestPalindromeSubseq(s);
        return n - lpsLength;
    }

private:
    int longestPalindromeSubseq(const string &s)
    {
        int n = s.size();
        // dp[i][j] will store the length of the longest palindromic subsequence
        // in the substring s[i...j]
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; ++i)
        {
            dp[i][i] = 1;
        }

        for (int len = 2; len <= n; ++len)
        {
            for (int i = 0; i <= n - len; ++i)
            {
                int j = i + len - 1;
                if (s[i] == s[j])
                {
                    dp[i][j] = 2 + (len > 2 ? dp[i + 1][j - 1] : 0);
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }
};
