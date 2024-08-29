int coinChange(vector<int> &coins, int amount)
{
    cout.tie(0);
    vector<int> dp(amount + 1, amount + 1); // instead intmax se initalise krne ke initialise with amount +1 which is also out of bound toh chalta h
    dp[0] = 0;

    for (auto i : coins)
    {
        for (int j = i; j <= amount; ++j)
        {
            dp[j] = min(dp[j], dp[j - i] + 1);
        }
    }

    if (dp[amount] > amount)
        return -1;
    return dp[amount];
}
/*Implementation 2.  initializes dp with amount + 1, which is effectively an upper bound on the number of coins needed. This is simpler and avoids using INT_MAX, which is more standard in practice.

This can potentially reduce the number of iterations in cases where the coins are smaller than the current coin.*/
// Implementation 2 is slightly more efficient because it avoids checking all previous amounts that are smaller than the current coin.This avoids some redundant calculations.
/*cout.tie(0); // Untie cout from cerr

    cout << "This is a test message to cout." << endl;
    cerr << "This is an error message to cerr." << endl;

    // Without cout.tie(0), the output might be flushed before the error message is displayed.
    // With cout.tie(0), the messages are displayed independently of each other.



cout.tie(&cerr); // Re-tie cout to cerr

 */