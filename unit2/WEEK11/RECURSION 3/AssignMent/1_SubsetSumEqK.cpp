#include <vector>
using namespace std;

void findSubsets(vector<int> &A, int index, int sumSoFar, int K, vector<int> &currentSubset, vector<vector<int>> &result)
{
    // Base case
    if (index == A.size())
    {
        if (sumSoFar == K)
        {
            // Add currentSubset to result
            result.push_back(currentSubset);
        }
        return;
    }

    // Include current element
    currentSubset.push_back(A[index]);
    findSubsets(A, index + 1, sumSoFar + A[index], K, currentSubset, result);
    currentSubset.pop_back(); // Backtrack

    // Exclude current element
    findSubsets(A, index + 1, sumSoFar, K, currentSubset, result);
}

int subsetSumToK(int input[], int n, int output[][50], int k)
{
    vector<int> A(input, input + n);
    vector<vector<int>> result;
    vector<int> currentSubset;

    findSubsets(A, 0, 0, k, currentSubset, result);

    int count = 0;
    for (const auto &subset : result)
    {
        output[count][0] = subset.size();
        for (int i = 0; i < subset.size(); ++i)
        {
            output[count][i + 1] = subset[i];
        }
        ++count;
    }

    return count;
}

// way 2
#include <iostream>
using namespace std;

int subsetSumToKHelper(int input[], int n, int startindex, int output[][50], int k)
{
    // Base case: If we have considered all elements
    if (startindex == n)
    {
        // Check if k is reduced to 0, meaning we found a subset that sums to k
        if (k == 0)
        {
            // Store the empty subset
            output[0][0] = 0;
            return 1; // Return 1 to indicate one subset found
        }
        else
        {
            return 0; // Return 0 to indicate no subset found
        }
    }

    // Recursive case
    // Recursive call without including current element
    int smallOutput1[1000][50];
    int size1 = subsetSumToKHelper(input, n, startindex + 1, smallOutput1, k);

    // Recursive call including current element
    int smallOutput2[1000][50];
    int size2 = subsetSumToKHelper(input, n, startindex + 1, smallOutput2, k - input[startindex]);

    // Copy smallOutput1 to output
    int row = 0;
    for (int i = 0; i < size1; i++)
    {
        // Copy each subset from smallOutput1 to output
        for (int j = 0; j <= smallOutput1[i][0]; j++)
        {
            output[row][j] = smallOutput1[i][j];
        }
        row++;
    }

    // Add current element to each subset in smallOutput2 and copy to output
    for (int i = 0; i < size2; i++)
    {
        output[row][0] = smallOutput2[i][0] + 1; // Set length of subset
        output[row][1] = input[startindex];      // Add current element to subset
        // Copy the rest of the subset
        for (int j = 1; j <= smallOutput2[i][0]; j++)
        {
            output[row][j + 1] = smallOutput2[i][j];
        }
        row++;
    }

    return size1 + size2; // Return total number of subsets found
}

int subsetSumToK(int input[], int n, int output[][50], int k)
{
    // Write your code here
    return subsetSumToKHelper(input, n, 0, output, k);
}
#include <iostream>
#include "solution.h"
using namespace std;

int main()
{
    int input[20], length, output[10000][50], k;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];

    cin >> k;

    int size = subsetSumToK(input, length, output, k);

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}
