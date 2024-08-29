
#include <iostream>
#include <vector>
using namespace std;

void printSubsets(vector<int> &input, int index, int sumSoFar, int k, vector<int> &currentSubset)
{
    // Base case: If we have considered all elements
    if (index == input.size())
    {
        // Check if current subset sums to k
        if (sumSoFar == k)
        {
            // Print current subset
            //  cout << "Subset that sums to " << k << ": ";
            for (int num : currentSubset)
            {
                cout << num << " ";
            }
            cout << endl;
        }
        return;
    }

    // Recursive case
    // Exclude current element
    printSubsets(input, index + 1, sumSoFar, k, currentSubset);

    // Include current element
    currentSubset.push_back(input[index]);
    printSubsets(input, index + 1, sumSoFar + input[index], k, currentSubset);

    // Backtrack
    currentSubset.pop_back();
}

void printSubsetSumToK(int input[], int size, int k)
{
    vector<int> nums(input, input + size); // Convert input array to vector
    vector<int> currentSubset;
    printSubsets(nums, 0, 0, k, currentSubset);
}
#include <iostream>
using namespace std;
#include "solution.h"

int main()
{
    int input[1000], length, k;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];
    cin >> k;
    printSubsetSumToK(input, length, k);
}
