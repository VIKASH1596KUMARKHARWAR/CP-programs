#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int m = s.size();
        int n = t.size();

        // Initialize the dp array
        vector<int> dp(n + 1, 0);
        dp[0] = 1; // An empty t can always be formed from any prefix of s

        for (int i = 1; i <= m; i++)
        {
            // Start from the end to avoid overwriting values of dp[j] needed for dp[j + 1]
            for (int j = n; j >= 1; j--)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[j] = dp[j - 1] + dp[j];
                }
            }
        }

        return dp[n];
    }
};

int main()
{
    Solution sol;

    // Test case 1
    string s1 = "rabbbit";
    string t1 = "rabbit";
    cout << "Number of distinct subsequences of \"" << s1 << "\" that equal \"" << t1 << "\" is: " << sol.numDistinct(s1, t1) << endl;

    // Test case 2
    string s2 = "abcabcabb";
    string t2 = "abc";
    cout << "Number of distinct subsequences of \"" << s2 << "\" that equal \"" << t2 << "\" is: " << sol.numDistinct(s2, t2) << endl;

    return 0;
}
