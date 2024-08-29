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
        /*Alternatively we can do line*/
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        /*nums.begin() returns an iterator pointing to the first element of the nums vector.
nums.insert(nums.begin(), 1); inserts 1 at the position indicated by the iterator, which is the beginning of the vector.*/

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return maxCoinshelper(nums, 1, nums.size() - 2, dp);
    }

private:
    int maxCoinshelper(vector<int> &balloons, int left, int right, vector<vector<int>> &dp)
    {
        if (left > right)
            return 0;
        if (dp[left][right] != -1)
            return dp[left][right];
        int maxCoins = 0;
        for (int idx = left; idx <= right; ++idx)
        {
            int coins = balloons[left - 1] * balloons[idx] * balloons[right + 1];
            coins += maxCoinshelper(balloons, left, idx - 1, dp) + maxCoinshelper(balloons, idx + 1, right, dp);
            maxCoins = max(maxCoins, coins);
        }
        return dp[left][right] = maxCoins;
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