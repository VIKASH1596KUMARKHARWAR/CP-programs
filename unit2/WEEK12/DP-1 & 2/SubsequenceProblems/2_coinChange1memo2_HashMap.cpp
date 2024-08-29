// Added unordered_map<int, int> memo to store results of subproblems.
// The key for the memoization map is a combination of amount and idx to uniquely identify each subproblem. This is done by hashing amount * coins.size() + idx.

#include <iostream>
#include <vector>
#include <unordered_map> // For std::unordered_map
#include <climits>       // For INT_MAX
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        // Create a memoization map
        unordered_map<int, int> memo;
        return coinChangeHelper(coins, amount, coins.size() - 1, memo);
    }

private:
    int coinChangeHelper(vector<int> &coins, int amount, int idx, unordered_map<int, int> &memo)
    {
        // Base cases
        if (amount == 0)
            return 0;
        if (amount < 0 || idx < 0)
            return -1;

        // Check if the result is already in the memoization map
        if (memo.find(amount * coins.size() + idx) != memo.end())
            return memo[amount * coins.size() + idx];

        // Option 1: Exclude the current coin and move to the next coin
        int exclude = coinChangeHelper(coins, amount, idx - 1, memo);

        // Option 2: Include the current coin (if it's valid) and stay on the same coin
        int include = (amount >= coins[idx]) ? coinChangeHelper(coins, amount - coins[idx], idx, memo) : -1;
        if (include != -1)
            include += 1;

        // Decide the minimum of including or excluding the coin
        if (exclude == -1)
            memo[amount * coins.size() + idx] = include;
        else if (include == -1)
            memo[amount * coins.size() + idx] = exclude;
        else
            memo[amount * coins.size() + idx] = min(include, exclude);

        return memo[amount * coins.size() + idx];
    }
};

int main()
{
    Solution s;
    vector<int> coins = {1, 2, 5}; // Example coins
    int amount = 11;               // Example amount
    int result = s.coinChange(coins, amount);
    cout << "Minimum number of coins needed: " << result << endl;
    return 0;
}
