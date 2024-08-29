// / another way to ewrite jaisa sikha tha striver se

class Solution
{
public:
    int minCost(int n, vector<int> &cuts)
    {

        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        int c = cuts.size();

        vector<vector<int>> dp(c, vector<int>(c, 0));

        for (int i = c - 1; i >= 0; --i)
        { // Start from the end
            for (int j = i + 1; j < c; ++j)
            { // Start from i + 1
                if (j - i <= 1)
                    continue; // No segment to cut

                int mini = INT_MAX;

                for (int ind = i + 1; ind < j; ++ind)
                {
                    // Calculate the cost for making a cut at position 'ind'
                    int cost = cuts[j] - cuts[i] + dp[i][ind] + dp[ind][j];
                    mini = min(mini, cost);
                }

                dp[i][j] = mini;
            }
        }

        return dp[0][c - 1];
    }
};

// AN0THER WAY
class Solution
{
public:
    int minCost(int n, vector<int> &cuts)
    {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(cuts.size(), vector<int>(cuts.size(), 0));

        for (int i = cuts.size() - 2; i >= 1; i--)
        {
            for (int j = 1; j <= cuts.size() - 2; j++)
            {
                if (i > j)
                    continue;
                ;
                int mini = 1e9;
                for (int k = i; k <= j; k++)
                {
                    int cost = cuts[j + 1] - cuts[i - 1];
                    mini = min(mini, cost + dp[i][k - 1] + dp[k + 1][j]);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][cuts.size() - 2];
    }
};

// BEST WAY
class Solution
{
public:
    int dp[105][105];

    int minCost(int n, vector<int> &cuts)
    {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        memset(dp, 0, sizeof(dp));

        for (int i = cuts.size() - 2; i >= 1; i--)
        {
            for (int j = 1; j <= cuts.size() - 2; j++)
            {
                if (i > j)
                    continue;
                ;
                int mini = 1e9;
                for (int k = i; k <= j; k++)
                {
                    int cost = cuts[j + 1] - cuts[i - 1];
                    mini = min(mini, cost + dp[i][k - 1] + dp[k + 1][j]);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][cuts.size() - 2];
    }
};