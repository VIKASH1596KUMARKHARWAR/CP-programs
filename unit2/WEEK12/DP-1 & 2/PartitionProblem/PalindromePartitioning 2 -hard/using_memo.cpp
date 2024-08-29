/*Given a string s, partition s such that every substringof the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

 Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.


*/
#include <iostream>
#include <string>
#include <functional>
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
        vector<vector<int>> memo(n, vector<int>(n, -1));
        vector<vector<bool>> isPallindrome(n, vector<bool>(n, false));
        // isPalindrome[i][j] will be true if the substring s[i:j+1] is a palindrome, and false otherwise.

        auto computePallindrome = [&]()
        {
            for (int i = 0; i < n; i++)
            {
                isPallindrome[i][i] = 0; // single char
            }

            for (int i = 0; i < n - 1; i++)
            {
                if (s[i] == s[i + 1])
                {
                    isPallindrome[i][i + 1] = true;
                }
            }
            for (int length = 3; length <= n; length++)
            {
                for (int i = 0; i <= n - length; i++)
                {
                    int j = i + length - 1;
                    if (s[i] == s[j] && isPallindrome[i + 1][j - 1])
                    {
                        isPallindrome[i][j] = true;
                    }
                }
            }
        };

        computePallindrome();
        function<int(int, int)> dfs = [&](int start, int end) -> int
        {
            if (start >= end)
                return 0;
            if (isPallindrome[start][end])
                return 0;
            int mincut = end - start;
            for (int i = start; i < end; i++)
            {
                if (isPallindrome[start][i])
                {
                    mincut = min(mincut, dfs(i + 1, end) + 1);
                }
            }
            memo[start][end] = mincut;
            return mincut;
        };

        return dfs(0, n - 1);
    }
};

int main()
{
    Solution sol;
    string s = "aab";
    cout << "Minimum cuts needed for palindrome partitioning: " << sol.minCut(s) << endl;
    return 0;
}
