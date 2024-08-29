#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to compute the length of the Longest Common Substring (LCSubstring)
int lcsubstring_dp(const string &s, const string &t)
{
    int m = s.size();
    int n = t.size();

    // Create a 2D DP table initialized with 0
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    int maxLength = 0; // Variable to store the maximum length of LCSubstring

    // Fill the DP table
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxLength = max(maxLength, dp[i][j]); // Update the maximum length
            }
            else
            {
                dp[i][j] = 0; // Reset to 0 if characters don't match
            }
        }
    }

    // The length of the Longest Common Substring is in maxLength
    return maxLength;
}

int main()
{
    string s, t;
    cin >> s >> t;

    cout << lcsubstring_dp(s, t) << '\n';

    return 0;
}
