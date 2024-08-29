#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int LongestIncreasingSubsequence(int *arr, int n)
    {
        return LISrecursively(arr, n, 0, -1);
    }

private:
    int LISrecursively(int *arr, int n, int idx, int previousIdx)
    {
        // base case:: processed all the elements
        if (idx >= n)
            return 0;

        // Option 1: Exclude the current element and move to the next
        int exclude = LISrecursively(arr, n, idx + 1, previousIdx);

        // Option 2: Include the current element if it is greater than the previous element
        int include = 0;
        if (previousIdx == -1 || arr[idx] > arr[previousIdx])
        {
            include = 1 + LISrecursively(arr, n, idx + 1, idx);
        }

        // Return the maximum of including or excluding the current element
        return max(include, exclude);
    }
};
int main()
{
    Solution s;
    int n;
    cin >> n;

    if (n <= 0)
    { // Check for invalid size
        cout << "Invalid array size." << endl;
        return 1;
    }
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << s.LongestIncreasingSubsequence(arr, n);
    delete[] arr; // Free the allocated memory
    return 0;
}