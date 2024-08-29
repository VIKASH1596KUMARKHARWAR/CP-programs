#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int minCut(string s)
    {
        int n = s.size();
        if (n == 0)
            return 0;

        // Step 1: Create the palindrome table
        vector<std::vector<bool>> isPalindrome(n, std::vector<bool>(n, false));
        for (int i = 0; i < n; ++i)
        {
            isPalindrome[i][i] = true;
        }
        for (int i = 0; i < n - 1; ++i)
        {
            if (s[i] == s[i + 1])
            {
                isPalindrome[i][i + 1] = true;
            }
        }
        for (int length = 3; length <= n; ++length)
        {
            for (int i = 0; i <= n - length; ++i)
            {
                int j = i + length - 1;
                if (s[i] == s[j] && isPalindrome[i + 1][j - 1])
                {
                    isPalindrome[i][j] = true;
                }
            }
        }

        // STEPS 2::calculate minimum cuts required

        // dp[i] represents the minimum number of cuts required to partition the substring  s[0:i + 1](i.e., from the start of the string up to index i) into palindromic substrings.

        vector<int> dp(n, n); // initialize dp with maximum possible cuts

        for (int i = 0; i < n; i++)
        {
            if (isPalindrome[0][i])
            {
                dp[i] = 0; // No cut needed if the whole substring s[0:i+1] is a palindrome
            }
            else
            {

                for (int j = 0; j < i; j++)
                {
                    if (isPalindrome[j + 1][i])
                    {
                        dp[i] = min(dp[i], dp[j] + 1);
                    }
                }
            }
        }
        return dp[n - 1];
    }
};

int main()
{
    Solution sol;
    string s = "aab";
    cout << "Minimum cuts needed for palindrome partitioning: " << sol.minCut(s) << endl;
    return 0;
}
