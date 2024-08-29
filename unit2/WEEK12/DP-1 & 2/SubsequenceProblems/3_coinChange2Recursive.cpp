/*You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

*/
#include <iostream>
#include <vector>
using namespace std;
// number of combinations

int countCombinationHelper(vector<int> &coins, int amount, int idx)
{
    if (amount == 0)
        return 1;
    if (amount < 0 || idx < 0)
        return 0;

    // Option 1: Exclude the current coin and move to the previous coin
    int exclude = countCombinationHelper(coins, amount, idx - 1);

    // Option 2: Include the current coin and try to form the remaining amount
    // since infine suppies of same coins 0r can say multiple use ...stay on the same
    int include = countCombinationHelper(coins, amount - coins[idx], idx);

    // return kr do sum of both options
    return include + exclude;
}

int countCombination(vector<int> &coins, int amount)
{
    if (amount == 0)
        return 1; // 1 way to have zero
    if (amount < 0)
        return 0; // not possibel snce having onlf coins of +ve denominations
    return countCombinationHelper(coins, amount, coins.size() - 1);
}
int main()
{

    vector<int> coins = {1, 2, 5};
    int amount = 5;

    int result = countCombination(coins, amount);
    cout << "Number of combinations: " << result << endl;
    return 0;
}