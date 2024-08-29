#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

class Solution
{
public:
    int matrixChainMultiplication(int arr[], int n)
    {
        // Initialize memo table with -1 to indicate uninitialized values
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return matrixChainOrder(arr, 1, n - 1, memo); // 1-based index for matrices
    }

private:
    int matrixChainOrder(int arr[], int i, int j, vector<vector<int>> &memo)
    {
        // Base case: only one matrix, no multiplication needed
        if (i == j)
            return 0;

        // Check if the result is already computed
        if (memo[i][j] != -1)
            return memo[i][j];

        // Initialize the minimum cost to a large value
        int minCost = INT_MAX;

        // Try every possible position to split the product
        for (int k = i; k < j; ++k)
        {
            int cost = matrixChainOrder(arr, i, k, memo) +
                       matrixChainOrder(arr, k + 1, j, memo) +
                       arr[i - 1] * arr[k] * arr[j];

            if (cost < minCost)
                minCost = cost;
        }

        // Store the result in memo table
        memo[i][j] = minCost;
        return minCost;
    }
};

int main()
{
    ios_base::sync_with_stdio(false); // Disable synchronization with C I/O
    cin.tie(NULL);                    // Untie cin from cout for faster input

    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];                 // Array to store matrix dimensions
        for (int i = 0; i < N; ++i) // Read dimensions into arr
            cin >> arr[i];

        Solution ob;
        cout << ob.matrixChainMultiplication(arr, N) << endl; // Pass N as size
    }
    return 0;
}
