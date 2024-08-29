/*prev Array: Stores the results of the previous row of the DP table.
curr Array: Stores the results of the current row being computed.
2. Array Size n + 1
Size n + 1: This is required to accommodate the results for all prefixes of t, including the case where t is empty.*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int m = s.size();
        int n = t.size();

        // Initialize previous and current arrays
        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);

        // An empty t can always be formed from any prefix of s
        prev[0] = 1;

        for (int i = 1; i <= m; i++)
        {
            // For each character in s, update the current row of dp table
            curr[0] = 1; // An empty t can always be formed from any prefix of s
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    // If characters match, add the number of ways including and excluding this character
                    curr[j] = prev[j - 1] + prev[j];
                }
                else
                {
                    // If characters don't match, skip the current character of s
                    curr[j] = prev[j];
                }
            }
            // Swap prev and curr
            swap(prev, curr); // or prev = curr
        }

        return prev[n];
    }
};

int main()
{
    Solution sol;

    // Test case 1
    string s1 = "rabbbit";
    string t1 = "rabbit";
    cout << "Number of distinct subsequences of \"" << s1 << "\" that equal \"" << t1 << "\" is: " << sol.numDistinct(s1, t1) << endl;

    // Test case 2
    string s2 = "abcabcabb";
    string t2 = "abc";
    cout << "Number of distinct subsequences of \"" << s2 << "\" that equal \"" << t2 << "\" is: " << sol.numDistinct(s2, t2) << endl;

    return 0;
}
