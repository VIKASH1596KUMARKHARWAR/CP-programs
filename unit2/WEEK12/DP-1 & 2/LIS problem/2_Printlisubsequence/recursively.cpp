#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // recursive function
    vector<int> findLIS(int idx, const vector<int> &arr)
    {
        vector<int> longestSubseq;
        longestSubseq.push_back(arr[idx]);

        // explore all previous indices to extend the LIS ending at the idx
        for (int i = 0; i < idx; ++i)
        {
            if (arr[i] < arr[idx])
            {
                vector<int> candidate = findLIS(i, arr);
                if (candidate.size() > longestSubseq.size() - 1)
                {
                    longestSubseq = candidate;
                    longestSubseq.push_back(arr[idx]);
                }
            }
        }
    }

    vector<int> longestIncreasingSubsequence(int n, vector<int> &arr)
    {
        vector<int> maxLIS;
        for (int i = 0; i < n; i++)
        {
            vector<int> currentLIS = findLIS(i, arr);
            if (currentLIS.size() > maxLIS.size())
            {
                maxLIS = currentLIS;
            }
        }
        return maxLIS;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
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
    }
    return 0;
}