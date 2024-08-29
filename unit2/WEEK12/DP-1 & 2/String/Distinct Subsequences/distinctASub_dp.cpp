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
        // Initialize memoization table with -1 indicating uncomputed values
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; i++)
        {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    // If characters match, we can either include this character or skip it
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else
                {
                    // If characters don't match, skip the current character of s
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[m][n];
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

    // Test case 3
    string s3 = "aaaa";
    string t3 = "aa";
    cout << "Number of distinct subsequences of \"" << s3 << "\" that equal \"" << t3 << "\" is: " << sol.numDistinct(s3, t3) << endl;

    // Test case 4
    string s4 = "abc";
    string t4 = "def";
    cout << "Number of distinct subsequences of \"" << s4 << "\" that equal \"" << t4 << "\" is: " << sol.numDistinct(s4, t4) << endl;

    // Test case 5
    string s5 = "";
    string t5 = "any";
    cout << "Number of distinct subsequences of \"" << s5 << "\" that equal \"" << t5 << "\" is: " << sol.numDistinct(s5, t5) << endl;
    // To form the string t from s, you need at least as many characters in s as there are in t. Since s is empty, it is impossible to form any non-empty string t from it.
    // The number of distinct subsequences of an empty string s that match a non-empty string t is 0. This is because there are no characters in s to match against t, so no subsequence of s can form t.

    // Test case 6
    string s6 = "any";
    string t6 = "";
    cout << "Number of distinct subsequences of \"" << s6 << "\" that equal \"" << t6 << "\" is: " << sol.numDistinct(s6, t6) << endl;
    return 0;
}