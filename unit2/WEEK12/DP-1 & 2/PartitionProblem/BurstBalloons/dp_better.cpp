class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        const int n = nums.size();
        int a[305];
        memcpy(&a[1], nums.data(), n * sizeof(int));
        a[0] = a[n + 1] = 1;

        int dp[305][305];
        memset(&dp[0][0], 0, sizeof(dp));

        for (int i = n; i >= 1; --i)
        {
            for (int j = 1; j <= n; ++j)
            {
                int maxCoins = 0;
                for (int idx = i; idx <= j; ++idx)
                {
                    int coins = a[i - 1] * a[idx] * a[j + 1];
                    coins += (idx > i ? dp[i][idx - 1] : 0) + (idx < j ? dp[idx + 1][j] : 0);
                    maxCoins = max(maxCoins, coins);
                }
                dp[i][j] = maxCoins;
            }
        }
        return dp[1][n];
    }
};