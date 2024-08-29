#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        for (int idx = n - 1; idx >= 0; idx--)
        {
            int len = 0;
            int maxAns = INT_MIN;
            int maxVal = INT_MIN;

            for (int j = idx; j < min(idx + k, n); j++)
            {
                len++;
                maxVal = max(maxVal, arr[j]);
                int currentPartitonSum = len * maxVal + dp[j + 1];
                maxAns = max(maxAns, currentPartitonSum);
            }
            dp[idx] = maxAns;
        }
        return dp[0];
    }
};
int main()
{
    Solution s;
    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;
    int maxSum = s.maxSumAfterPartitioning(arr, k);
    cout << "The maximum sum after partitioning is: " << maxSum << "\n";
    return 0;
}