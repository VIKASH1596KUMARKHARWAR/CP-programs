#include <bits/stdc++.h>
using namespace std;

// Function to remove duplicates from a sorted vector and return the new size
int removeDuplicates(vector<int> &arr)
{
    int k = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] != arr[k])
        {
            arr[++k] = arr[i];
        }
    }
    return k + 1;
}

// Function to return the size of the longest increasing subsequence
int LISusingLCS(vector<int> &seq)
{
    int n = seq.size();

    if (n == 0)
        return 0; // Handle empty input

    // Create a 2D vector for DP table
    vector<vector<int>> L(n + 1, vector<int>(n + 1));

    // Create and sort a copy of the sequence to use as the second sequence
    vector<int> sortedseq(seq);
    sort(sortedseq.begin(), sortedseq.end());

    // Remove duplicates from the sorted sequence
    int m = removeDuplicates(sortedseq);

    // Classical Dynamic Programming algorithm for Longest Common Subsequence
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (seq[i - 1] == sortedseq[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    // Return the length of the longest increasing subsequence
    return L[n][m];
}

// Driver code
int main()
{
    vector<int> sequence{0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};

    cout << "Length of LIS is " << LISusingLCS(sequence) << endl;

    return 0;
}
