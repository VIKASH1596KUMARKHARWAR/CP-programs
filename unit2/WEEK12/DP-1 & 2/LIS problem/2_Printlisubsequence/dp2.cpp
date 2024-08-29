#include <iostream>
#include <vector>
#include <algorithm> // For std::max and std::reverse
using namespace std;

class Solution
{
public:
    pair<int, vector<int>> longestIncreasingSubsequence(int *arr, int n)
    {
        // Edge case for empty array
        if (n == 0)
        {
            return {0, {}};
        }

        // DP array to store the length of the LIS ending at each index
        vector<int> dp(n, 1);
        // Array to reconstruct the LIS
        vector<int> predecessor(n, -1);

        int maxLength = 1;
        int endIndex = 0;

        // Compute LIS length ending at each index
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    predecessor[i] = j;
                }
            }
            if (dp[i] > maxLength)
            {
                maxLength = dp[i];
                endIndex = i;
            }
        }

        // Reconstruct the LIS
        vector<int> lis;
        for (int i = endIndex; i != -1; i = predecessor[i])
        {
            lis.push_back(arr[i]);
        }
        reverse(lis.begin(), lis.end());

        return {maxLength, lis};
    }
};

int main()
{
    Solution s;
    int n;
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid array size." << endl;
        return 1;
    }

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Get the result from the solution
    auto result = s.longestIncreasingSubsequence(arr, n);
    int maxLength = result.first;
    vector<int> lis = result.second;

    // Print the length of LIS
    cout << "Length of LIS: " << maxLength << endl;

    // Print the longest increasing subsequence
    cout << "Longest Increasing Subsequence: ";
    for (int num : lis)
    {
        cout << num << " ";
    }
    cout << endl;

    delete[] arr; // Free the allocated memory
    return 0;
}
