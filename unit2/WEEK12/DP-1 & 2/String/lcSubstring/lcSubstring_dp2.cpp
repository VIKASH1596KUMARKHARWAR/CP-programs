#include <iostream>
#include <vector>
#include <string>
using namespace std;

// The DP table is used to store lengths of the longest common substring ending at various indices in the two strings.Specifically, dp[i][j](in a 2D table) or curr[j](in a 1D table) represents the length of the longest common substring that ends at s1[i - 1] and s2[j - 1]

/*Why Length of Arrays Based on s2 (n + 1):

The length of the 1D array prev or curr is n + 1, where n is the length of the second string (s2), because each entry in this array represents the state of the DP table for one specific character in s2 as you iterate through s1.
For each character of s1, you need to compare it with every character of s2, so the size of the array corresponds to the length of s2 plus one for the base case (empty substring comparison).
*/
int longestCommonSubstr(const string &s1, const string &s2)
{
    int m = s1.size();
    int n = s2.size();

    // Create two 1D DP tables (previous and current rows)
    vector<int> prev(n + 1, 0), curr(n + 1, 0);

    int maxLength = 0; // Variable to store the maximum length of LCSubstring

    // Fill the DP table
    for (int i = 1; i <= m; ++i)
    {
        // Swap the rows: make the current row previous and reset the current row
        swap(prev, curr);

        for (int j = 1; j <= n; ++j)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                curr[j] = prev[j - 1] + 1;
                maxLength = max(maxLength, curr[j]); // Update the maximum length
            }
            else
            {
                curr[j] = 0; // Reset to 0 if characters don't match
            }
        }
    }

    // The length of the Longest Common Substring is in maxLength
    return maxLength;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    cout << longestCommonSubstr(s1, s2) << '\n';

    return 0;
}

/*ABCDGH
ACDGHR
4*/