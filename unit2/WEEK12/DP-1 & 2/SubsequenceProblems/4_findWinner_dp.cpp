#include <iostream>
#include <vector> // Include vector header for using vector
using namespace std;

class Solution
{
public:
    string findWinner(int n, int x, int y)
    {
        vector<bool> dp(n + 1, false); // dp[i] will be true if the player whose turn it is can guarantee a win with i coins

        for (int i = 0; i <= n; ++i)
        {
            // Check if removing 1 coin leads to a losing position for the opponent
            if (i >= 1 && !dp[i - 1])
            {
                dp[i] = true;
            }

            // Check if removing x coins leads to a losing position for the opponent
            if (i >= x && !dp[i - x])
            {
                dp[i] = true;
            }

            // Check if removing y coins leads to a losing position for the opponent
            if (i >= y && !dp[i - y])
            {
                dp[i] = true;
            }
        }
        return dp[n] ? "Beerus" : "Whis";
    }
};

int main()
{
    Solution s;
    int n = 7; // number of coins
    int x = 2;
    int y = 3;

    cout << s.findWinner(n, x, y) << endl; // Output the result
    return 0;
}
