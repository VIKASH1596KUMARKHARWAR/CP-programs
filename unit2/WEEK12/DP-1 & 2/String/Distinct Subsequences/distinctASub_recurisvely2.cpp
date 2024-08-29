// starting from 0th idx

#include <string>
using namespace std;

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        return numDistinctHelper(s, t, 0, 0);
    }

private:
    int numDistinctHelper(const string &s, const string &t, int i, int j)
    {
        // If all characters of t are matched
        if (j == t.size())
        {
            return 1; // We've successfully matched all characters of t
        }

        // If we've run out of characters in s
        if (i == s.size())
        {
            return 0; // No more characters to match t
        }

        // If the current characters match
        if (s[i] == t[j])
        {
            // Consider both using the current character of s or not using it
            return numDistinctHelper(s, t, i + 1, j + 1) + numDistinctHelper(s, t, i + 1, j);
        }
        else
        {
            // If characters don't match, skip the current character of s
            return numDistinctHelper(s, t, i + 1, j);
        }
    }
};
