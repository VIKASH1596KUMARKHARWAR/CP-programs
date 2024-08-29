/*Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.



Example 1:

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int minDistance(const string &word1, const std::string &word2)
    {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        int lecsLenght = lcsLenghtRecu(word1, word2, m - 1, n - 1, memo);

        // Calculate the minimum number of deletions
        return (m - lecsLenght) + (n - lecsLenght);
    }

private:
    int lcsLenghtRecu(const string &word1, const string &word2, int i, int j, vector<vector<int>> &memo)
    {
        if (i < 0 || j < 0)
            return 0;

        if (memo[i][j] != -1)

            return memo[i][j];

        if (word1[i] == word2[j])
        {
            memo[i][j] = 1 + lcsLenghtRecu(word1, word2, i - 1, j - 1, memo);
        }
        else
        {
            memo[i][j] = max(lcsLenghtRecu(word1, word2, i - 1, j, memo), lcsLenghtRecu(word1, word2, i, j - 1, memo));
        }
        return memo[i][j];
    }
};

int main()
{
    Solution solution;

    // Test cases
    std::string word1 = "sea";
    std::string word2 = "eat";

    std::cout << "word1: " << word1 << std::endl;
    std::cout << "word2: " << word2 << std::endl;

    int result = solution.minDistance(word1, word2);
    std::cout << "Minimum number of steps required: " << result << std::endl;

    return 0;
}
