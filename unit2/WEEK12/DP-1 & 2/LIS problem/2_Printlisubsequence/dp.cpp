#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> longestIncreasingSubsequence(int n, vector<int> &arr)
    {
        if (n == 0)
            return {};

        vector<int> dp(n, 1);
        vector<int> prev(n, -1);

        int maxLength = 1;
        int maxIndex = 0;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[j] < arr[i] && dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > maxLength)
            {
                maxLength = dp[i];
                maxIndex = i; // Fix: Update maxIndex instead of maxLength
            }
        }

        // Reconstruct LIS
        vector<int> lis;
        for (int i = maxIndex; i >= 0; i = prev[i])
        {
            lis.push_back(arr[i]);
            if (prev[i] == -1)
                break;
        }
        reverse(lis.begin(), lis.end());
        return lis;
    }
};

int main()
{
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    Solution obj;
    vector<int> res = obj.longestIncreasingSubsequence(N, arr);
    for (auto x : res)
        cout << x << " ";
    cout << "\n";

    return 0;
}
