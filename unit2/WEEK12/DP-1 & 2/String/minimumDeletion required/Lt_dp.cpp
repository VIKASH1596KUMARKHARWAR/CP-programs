
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minDistance(const string &word1, const string &word2)
    {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Length of LCS
        int lcsLength = dp[m][n];

        // Calculate the minimum number of deletions
        return (m - lcsLength) + (n - lcsLength);
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
