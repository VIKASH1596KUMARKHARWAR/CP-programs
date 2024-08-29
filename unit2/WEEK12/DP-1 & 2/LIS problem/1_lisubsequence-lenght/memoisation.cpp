#include <vector>

int LISmemo(int *arr, int n, int idx, int previousIndex, vector<vector<int>> &memo)
{
    if (idx >= n)
        return 0;

    if (memo[idx][previousIndex + 1] != -1)
        return memo[idx][previousIndex + 1];

    int exclude = LISmemo(arr, n, idx + 1, previousIndex, memo);
    int include = 0;
    if (arr[previousIndex] == -1 || arr[previousIndex] < arr[idx])
    {
        include = 1 + LISmemo(arr, n, idx + 1, idx, memo);
    }
    memo[idx][previousIndex + 1] = max(include, exclude);
    return memo[idx][previousIndex + 1];
}

int longestIncreasingSubsequence(int *arr, int n)
{
    if (n <= 0)
        return 0;
    vector<vector<int>> memo(n, vector<int>(n + 1, -1));
    return LISmemo(arr, n, 0, -1, memo);
}