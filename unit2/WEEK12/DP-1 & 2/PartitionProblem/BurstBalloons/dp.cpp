// combined proiblem of mcm and min cost to cut_Stick
/*You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

Example 1:
Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167

Example 2:
Input: nums = [1,5]
Output: 10*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int i = n; i >= 1; i--)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i > j)
                    continue; // because there  willl not be any valid range for us
                int maxCoins = 0;
                for (int idx = i; idx <= j; ++idx)
                {
                    int coins = nums[i - 1] * nums[idx] * nums[j + 1];
                    coins += dp[i][idx - 1] + dp[idx + 1][j];
                    maxCoins = max(maxCoins, coins);
                }
                dp[i][j] = maxCoins;
            }
        }
        return dp[1][n];
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {3, 1, 5, 8};
    vector<int> nums2 = {1, 5};

    cout << "Max coins for [3,1,5,8]: " << s.maxCoins(nums1) << endl;
    cout << "Max coins for [1,5]: " << s.maxCoins(nums2) << endl;

    return 0;
}