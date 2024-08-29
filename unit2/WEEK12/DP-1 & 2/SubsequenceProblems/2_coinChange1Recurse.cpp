/*You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.*/
// Input : coins = [ 1, 2, 5 ], amount = 11 Output : 3 Explanation : 11 = 5 + 5 + 1
// incude exclude way
// the t.c. may go beyond the 2^n because of being standing at the same position

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;
        return coinChangeHelper(coins, amount, coins.size() - 1);
    }

private:
    int coinChangeHelper(vector<int> &coins, int amount, int idx)
    {
        if (amount == 0)
            return 0;
        if (amount < 0 || idx < 0)
            return -1;

        // Option 1: Exclude the current coin and move to the next coin
        int exclude = coinChangeHelper(coins, amount, idx - 1);

        // Option 2: Include the current coin (if it's valid) and stay on the same coin
        int include = (amount >= coins[idx]) ? coinChangeHelper(coins, amount - coins[idx], idx) : -1;
        if (include != -1)
            include += 1;

        // Decide the minimum of including or excluding the coin
        if (exclude == -1)
            return include;
        if (include == -1)
            return exclude;

        return std::min(include, exclude);
    }
};

int main()
{
    Solution s;
    vector<int> coins = {1, 2, 3};
    int amount = 7;
    int result = s.coinChange(coins, amount);
    cout << "Minimum number of coins needed: " << result << endl;
    return 0;
}