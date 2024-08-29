#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minCuts(string s)
    {
        int n = s.size();
        if (n == 0)
            return 0;
        vector<bool> isPalindrome(n, false);
        vector<int> dp(n, n);

        for (int i = 0; i < n; ++i)
        {
            int minCut = i; // Initialize minimum cuts as worst case (all single letters)
            for (int j = 0; j <= i; ++j)
            {
                if (s[j] == s[i] && (i - j <= 2 || isPalindrome[j + 1]))
                {
                    isPalindrome[j] = true; // Update palindrome status
                    minCut = j == 0 ? 0 : std::min(minCut, dp[j - 1] + 1);
                }
                else
                {
                    isPalindrome[j] = false;
                }
            }
            dp[i] = minCut; // Update dp with the minimum cut for substring s[0:i+1]
        }

        return dp[n - 1];
    }
};

int main()
{
    Solution sol;
    string s = "aab";
    cout << "Minimum cuts needed for palindrome partitioning: " << sol.minCuts(s) << endl;
    return 0;
}

/*Minimum Cuts Calculation:
For each possible start position j (from 0 to i), the algorithm checks if the substring s[j:i+1] is a palindrome.
If s[j:i+1] is a palindrome, the algorithm updates dp[i] with the minimum value between the current minCut and the number of cuts needed if the current substring is palindromic. Specifically:
If j == 0, the substring s[0:i+1] is already a palindrome, so no cut is needed.
Otherwise, the minimum cuts needed is updated as dp[j - 1] + 1, where dp[j - 1] is the minimum number of cuts for the substring s[0:j-1], plus one additional cut to separate the current palindromic substring.
Updating dp:

After evaluating all possible start positions j for the substring ending at i, dp[i] is updated to reflect the minimum number of cuts required for s[0:i+1].*/
