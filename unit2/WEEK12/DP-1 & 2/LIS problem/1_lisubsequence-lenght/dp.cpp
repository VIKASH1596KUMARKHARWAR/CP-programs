#include <iostream>
#include <vector>
#include <algorithm> // For std::max_element
using namespace std;

int LIS(int *arr, int n)
{
    if (n <= 0)
        return 0;

    vector<int> dp(n, 1); // Each element is a LIS of length 1 initially

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end()); // Return the maximum value in dp
}

int main()
{
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

    cout << LIS(arr, n); // Call the correct function
    delete[] arr;        // Free the allocated memory
    return 0;
}
// n=16  and  0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15