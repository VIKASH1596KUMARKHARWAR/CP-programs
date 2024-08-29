#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    // Recursive function with memoization
    int maxSumAfterPartitioning(vector<int> &arr, int k, int idx, vector<int> &memo)
    {
        int n = arr.size();

        // Base case: If the current index is equal to or beyond the size of the array, return 0
        if (idx >= n)
            return 0;

        // If already computed, return the stored result
        if (memo[idx] != -1)
            return memo[idx];

        int maxAns = INT_MIN; // Initialize to the minimum possible value
        int maxVal = INT_MIN; // Initialize to the minimum possible value
        int len = 0;

        // Consider all possible partitions ending at index idx with length up to k
        for (int j = idx; j < min(n, idx + k); ++j)
        {
            len++;
            maxVal = max(maxVal, arr[j]); // Update the maximum value in the current window
            int currentPartitionSum = maxVal * len + maxSumAfterPartitioning(arr, k, j + 1, memo);
            maxAns = max(maxAns, currentPartitionSum); // Update the maximum answer found
        }

        // Store the computed result in the memoization table
        memo[idx] = maxAns;

        return maxAns;
    }

    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> memo(n, -1); // Initialize memoization table with -1 (indicating uncomputed)
        return maxSumAfterPartitioning(arr, k, 0, memo);
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
