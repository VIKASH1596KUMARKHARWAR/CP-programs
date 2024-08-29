/*Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

Example 1:
Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.

Example 2:
Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".

Example 3:
Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{

public:
    int minInsertions(string s)
    {
        int n = s.size();
        if (n == 0)
            return 0;
        vector<vector<int>> memo(n, vector<int>(n, -1));

        int lpsLength = longestPalindromeSubseq(s, 0, n - 1, memo);
        return n - lpsLength;
    }

private:
    int longestPalindromeSubseq(const string &s, int start, int end, vector<vector<int>> &memo)
    {
        if (start > end)
            return 0;
        if (start == end)
            return 1;
        if (memo[start][end] != -1)
            return memo[start][end];
        if (s[start] == s[end])
        {
            memo[start][end] = 2 + longestPalindromeSubseq(s, start + 1, end - 1, memo);
        }
        else
        {
            memo[start][end] = max(longestPalindromeSubseq(s, start + 1, end, memo), longestPalindromeSubseq(s, start, end - 1, memo));
        }
        return memo[start][end];
    }
};
#include <iostream>

int main()
{
    Solution solution;

    std::string s = "abc";
    std::cout << "Minimum number of insertions required to make \"" << s << "\" a palindrome is: " << solution.minInsertions(s) << std::endl;

    s = "bb";
    std::cout << "Minimum number of insertions required to make \"" << s << "\" a palindrome is: " << solution.minInsertions(s) << std::endl;

    s = "abcb";
    std::cout << "Minimum number of insertions required to make \"" << s << "\" a palindrome is: " << solution.minInsertions(s) << std::endl;

    return 0;
}
