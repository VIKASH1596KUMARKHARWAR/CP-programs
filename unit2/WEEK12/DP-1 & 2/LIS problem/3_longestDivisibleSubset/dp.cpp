#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int size = nums.size();
        if (size == 0)
            return {};
        sort(nums.begin(), nums.end());
        vector<int> dp(size, 1);
        vector<int> prevIndex(size, -1);

        int maxIndex = 0, maxSize = 1;

        for (int i = 1; i < size; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
                {
                    dp[i] = 1 + dp[j];
                    prevIndex[i] = j;
                }
            }
            if (dp[i] > maxSize)
            {
                maxSize = dp[i];
                maxIndex = i;
            }
        }

        vector<int> answer;
        for (int i = maxIndex; i >= 0; i = prevIndex[i])
        {
            answer.push_back(nums[i]);
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};