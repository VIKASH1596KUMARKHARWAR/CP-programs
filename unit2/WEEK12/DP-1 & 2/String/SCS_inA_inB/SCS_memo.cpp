#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        int n = str1.size();
        int m = str2.size();

        // Create a memoization table
        vector<vector<string>> memo(n + 1, vector<string>(m + 1, ""));

        // Fill the memoization table
        return buildSCS(str1, str2, n, m, memo);
    }

private:
    string buildSCS(const string &str1, const string &str2, int i, int j, vector<vector<string>> &memo)
    {
        // Base cases
        if (i == 0)
            return str2.substr(0, j);
        if (j == 0)
            return str1.substr(0, i);

        // Check if the result is already computed
        if (!memo[i][j].empty())
            return memo[i][j];

        // If characters are the same
        if (str1[i - 1] == str2[j - 1])
        {
            memo[i][j] = buildSCS(str1, str2, i - 1, j - 1, memo) + str1[i - 1];
        }
        else
        {
            // If characters are different, choose the better option
            string option1 = buildSCS(str1, str2, i - 1, j, memo) + str1[i - 1];
            string option2 = buildSCS(str1, str2, i, j - 1, memo) + str2[j - 1];
            memo[i][j] = (option1.size() < option2.size()) ? option1 : option2;
        }

        return memo[i][j];
    }
};

int main()
{
    Solution sol;
    string str1 = "abac";
    string str2 = "cab";
    cout << "Shortest Common Supersequence: " << sol.shortestCommonSupersequence(str1, str2) << endl;
    return 0;
}
