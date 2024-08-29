#include <iostream>
#include <vector>  // Include the vector header
#include <climits> // For INT_MAX
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0; // 0 coins needed to make 0 amount

        // Iterate through each amount from 1 to amount
        for (int i = 1; i <= amount; ++i)
        {
            // Check each coin
            for (int coin : coins)
            {
                // If the coin can be used to make the amount i
                if (i >= coin && dp[i - coin] != INT_MAX)
                {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        // If dp[amount] is still INT_MAX, it means it's not possible to make that amount
        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
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

/*Time Complexity Analysis
DP Array Initialization:

Initializing the dp array of size amount + 1 takes
𝑂(𝑛) time, where n is the amount.
Nested Loops:
Outer Loop: Iterates through each amount from 1 to amount. This loop runs 𝑂(𝑛)
O(n) times, where 𝑛 is the amount.
Inner Loop: For each amount, you check each coin. If there are m coins, this loop runs 𝑂(𝑚) times.
Therefore, the total time complexity of the nested loops is:O(n)×O(m)=O(n×m)
where 𝑛
n is the amount and
𝑚
m is the number of coin denominations.*/

/*Implementation 1(this one). iterates over amounts from 1 to amount and then over coins. This structure explicitly checks all coins for each amount, ensuring that all possible ways to form the amount are considered.

lets minimise and make it efficient*/