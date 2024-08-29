#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxSum(int idx, vector<int> &arr, int k)
    {
        int n = arr.size();
        // Base case: If the current index is equal to or beyond the size of the array, return 0
        if (idx >= n)
            return 0;

        int len = 0;
        int maxAns = INT_MIN;
        int maxVal = INT_MIN;

        // Consider all possible partitions ending at index ind with length up to k
        for (int j = idx; j < min(n, idx + k); j++)
        {
            len++;
            maxVal = max(maxVal, arr[j]);
            int currentPartitionSum = maxVal * len + maxSum(j + 1, arr, k);
            // int currentPartitionSum = maxValue * (j - ind + 1) + maxSum(j + 1, arr, k);if not maintaining the len

            maxAns = max(maxAns, currentPartitionSum);
        }
        return maxAns;
    }

    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        // SO PARTITION SUCH THAT NONE OF THE PARTITION HAVE LENGHT MORE THAN THE K
        // AT MAX K HONA CHAHIYA
        // AFTER PARTION entire subarry change to maximum  value
        // maximize total sum

        return maxSum(0, arr, k);
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