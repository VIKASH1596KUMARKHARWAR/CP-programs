// Each cell dp[i][j] represents the number of ways to make amount j using coins up to index i.class Solution
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<vector<int>> memo(coins.size(), vector<int>(amount + 1, -1));
        return countCombinations(amount, coins, coins.size() - 1, memo);
    }

private:
    int countCombinations(int amount, const vector<int> &coins, int index, vector<vector<int>> &memo)
    {
        if (amount == 0)
            return 1;
        if (amount < 0 || index < 0)
            return 0;

        if (memo[index][amount] != -1)
            return memo[index][amount];

        int exclude = countCombinations(amount, coins, index - 1, memo);
        int include = (amount >= coins[index]) ? countCombinations(amount - coins[index], coins, index, memo) : 0;

        memo[index][amount] = include + exclude;
        return memo[index][amount];
    }
};

int main()
{
    Solution s;
    vector<int> coins = {1, 2, 5};
    int amount = 5;

    int result = s.change(amount, coins);
    cout << "Number of combinations: " << result << endl;
    return 0;
}
