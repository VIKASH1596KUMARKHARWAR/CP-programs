// Input : coins = [ 1, 2, 5 ], amount = 11 Output : 3 Explanation : 11 = 5 + 5 + 1
// incude exclude way
// REMEMBER :: whenever there is infinite supply or of multiple use...u after including u have to br stay on that  index and do computation

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int result = coinChangeRecursive2(coins, amount);

        // Return -1 if result is INT_MAX, indicating that it's not possible
        return (result == INT_MAX) ? -1 : result;
    }

private:
    int coinChangeRecursive2(vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;

        int minCoins = INT_MAX;

        // explore each coins
        for (int coin : coins)
        {
            int result = coinChangeRecursive2(coins, amount - coin);

            // If the result is valid and less than current minCoins
            if (result >= 0 && result < minCoins)
            {
                minCoins = result + 1;
            }
        }
        // If the result is valid and less than current minCoins
        return (minCoins == INT_MAX) ? -1 : minCoins;
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