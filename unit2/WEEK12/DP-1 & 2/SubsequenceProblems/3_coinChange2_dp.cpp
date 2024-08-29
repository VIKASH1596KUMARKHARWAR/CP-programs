#include <iostream>
#include <vector>
using namespace std;

// dp[i] will store the number of ways to make amount i

class Solution
{
public:
    // int coinChange2 proble leetcode
    int countCombination(vector<int> &coins, int amount)
    {
        if (amount < 0)
            return 0;

        vector<int> dp(amount + 1, 0);

        dp[0] = 1; // There's one way to make amount 0 (using no coins)

        for (int coin : coins)
        {
            for (int j = coin; j <= amount; j++)
            {
                dp[j] += dp[j - coin];
                // update dp[j] by adding the number of ways to make j - coin(which is dp[j - coin]).
            }
        }
        return dp[amount];
    }
};

int main()
{
    Solution s;
    vector<int> coins = {1, 2, 5};
    int amount = 5;

    int result = s.countCombination(coins, amount);
    cout << "Number of combinations: " << result << endl;
    return 0;
}