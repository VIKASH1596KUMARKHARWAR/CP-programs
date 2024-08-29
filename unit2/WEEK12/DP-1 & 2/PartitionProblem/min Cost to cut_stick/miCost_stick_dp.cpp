#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
    int minCost(int n, vector<int> &cuts)
    {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        // Fill the DP table
        for (int length = 2; length < m; ++length)
        {
            for (int i = 0; i + length < m; ++i)
            {
                int j = i + length;
                int mini = INT_MAX;

                // Try every possible cut between i and j
                for (int idx = i + 1; idx < j; ++idx)
                {
                    int cost = cuts[j] - cuts[i] + dp[i][idx] + dp[idx][j];
                    mini = min(mini, cost);
                }

                dp[i][j] = mini;
            }
        }

        return dp[0][m - 1];
    }
};

int main()
{
    Solution sol;
    int n = 7;
    vector<int> cuts = {1, 3, 4, 5};

    cout << "Minimum cost of cuts: " << sol.minCost(n, cuts) << endl;

    return 0;
}
