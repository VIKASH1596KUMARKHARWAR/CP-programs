#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        return numDistinctHelper(s, t, n - 1, m - 1); // Starting from the last index
    }

private:
    int numDistinctHelper(const string &s, const string &t, int i, int j)
    {
        // Base case: If all characters of t are matched
        if (j < 0)
        {
            return 1; // Successfully matched all characters of t
        }

        // Base case: If we've run out of characters in s
        if (i < 0)
        {
            return 0; // No more characters to match t
        }

        // If the current characters match
        if (s[i] == t[j])
        {
            // Consider both using the current character of s or not using it
            return numDistinctHelper(s, t, i - 1, j - 1) + numDistinctHelper(s, t, i - 1, j);
        }
        else
        {
            // If characters don't match, skip the current character of s
            return numDistinctHelper(s, t, i - 1, j);
        }
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
    string s2 = "babgbag";
    string t2 = "bag";
    cout << "Number of distinct subsequences of \"" << s2 << "\" that equal \"" << t2 << "\" is: " << sol.numDistinct(s2, t2) << endl;

    return 0;
}
