/*dp[i][j] is used to store the minimum cost of multiplying matrices from index i to index j.
If i equals j, it means that you are considering only a single matrix (i.e., no multiplication of matrices is involved).*/

#include <iostream>
#include <vector>
#include <limits.h> // For INT_MAX

using namespace std;

class Solution

{
public:
    int matrixChainMultiplication(int arr[], int n)
    {

        // Adjust the size for the matrix dimensions(if want ot work  with 1-based indexing)  ==> n+=1;

        // Create a 2D vector for DP table
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // vector<vector<int>> dp(n+1, vector<int>(n+1, 0));if gonna working on 1-index based system

        // Cost is zero when multiplying one matrix
        for (int i = 1; i < n; i++)
        {
            dp[i][i] = 0;
            // dp[1][1] represents the cost of multiplying the matrix from index 1 to index 1(which is Matrix 1 alone).Since there's only one matrix, no multiplication is required:
        }

        // L is the chain length
        for (int L = 2; L < n; L++)
        {
            for (int i = 1; i < n - L + 1; i++)
            {
                int j = i + L - 1;
                dp[i][j] = INT_MAX;
                for (int k = i; k <= j - 1; k++)
                {
                    int q = dp[i][k] + dp[k + 1][j] + (arr[i - 1] * arr[k] * arr[j]);
                    if (q < dp[i][j])
                    {
                        dp[i][j] = q;
                    }
                }
            }
        }
        return dp[1][n - 1];
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
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.matrixChainMultiplication(arr, N) << endl;
    }
    return 0;
}