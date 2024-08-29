#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        // Create a 2D vector for memoization
        vector<vector<int>> memo(coins.size(), vector<int>(amount + 1, -1));
        return coinChangeHelper(coins, amount, coins.size() - 1, memo);
    }

private:
    int coinChangeHelper(vector<int> &coins, int amount, int idx, vector<vector<int>> &memo)
    {
        // Base cases
        if (amount == 0)
            return 0;
        if (amount < 0 || idx < 0)
            return -1;

        if (memo[idx][amount] != -1)
            return memo[idx][amount];

        // Option 1: Exclude the current coin and move to the next coin
        int exclude = coinChangeHelper(coins, amount, idx - 1, memo);

        // Option 2: Include the current coin (if it's valid) and stay on the same coin
        int include = (amount >= coins[idx]) ? coinChangeHelper(coins, amount - coins[idx], idx, memo) : -1;
        if (include != -1)
            include += 1;

        // Decide the minimum of including or excluding the coin
        if (exclude == -1)
            memo[idx][amount] = include;
        else if (include == -1)
            memo[idx][amount] = exclude;
        else
            memo[idx][amount] = min(include, exclude);

        return memo[idx][amount];
    }
};

int main()
{
    Solution s;
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    int result = s.coinChange(coins, amount);
    cout << "Minimum number of coins needed: " << result << endl;
    return 0;
}
