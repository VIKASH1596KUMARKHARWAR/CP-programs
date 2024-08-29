/*DP Table Construction:

The dp table is used to compute the length of the LCS between substrings of word1 and word2.
Reconstructing the LCS:

The reconstructLCS function traces back from dp[m][n] to reconstruct the LCS string.
Removing Non-LCS Characters:

The removeNonLCS function generates the string with only LCS characters kept and others removed.
Output:

Print the LCS and the modified versions of word1 and word2 that only contain characters from the LCS.*/

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

class Solution
{
public:
    void minDistance(const std::string &word1, const std::string &word2)
    {
        int m = word1.size();
        int n = word2.size();

        // Create a 2D DP table to store lengths of LCS
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

        // Fill the DP table
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1; // Characters match
                }
                else
                {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]); // Take the max of excluding one character from either string
                }
            }
        }

        // Reconstruct the LCS
        std::string lcs = reconstructLCS(word1, word2, dp);

        // Print the results
        std::cout << "LCS: " << lcs << std::endl;
        std::cout << "Modified word1: " << removeNonLCS(word1, lcs) << std::endl;
        std::cout << "Modified word2: " << removeNonLCS(word2, lcs) << std::endl;
    }

private:
    std::string reconstructLCS(const std::string &word1, const std::string &word2, const std::vector<std::vector<int>> &dp)
    {
        std::string lcs;
        int i = word1.size();
        int j = word2.size();

        while (i > 0 && j > 0)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                lcs.push_back(word1[i - 1]);
                --i;
                --j;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                --i;
            }
            else
            {
                --j;
            }
        }

        std::reverse(lcs.begin(), lcs.end());
        return lcs;
    }

    std::string removeNonLCS(const std::string &word, const std::string &lcs)
    {
        std::string result;
        int lcsIndex = 0;

        for (char c : word)
        {
            if (lcsIndex < lcs.size() && c == lcs[lcsIndex])
            {
                ++lcsIndex;
            }
            else
            {
                result.push_back(c);
            }
        }

        return result;
    }
};

int main()
{
    Solution solution;

    // Test cases
    std::string word1 = "abc";
    std::string word2 = "ac";

    std::cout << "Original strings:" << std::endl;
    std::cout << "word1: " << word1 << std::endl;
    std::cout << "word2: " << word2 << std::endl;

    std::cout << "\nProcessing..." << std::endl;
    solution.minDistance(word1, word2);

    return 0;
}