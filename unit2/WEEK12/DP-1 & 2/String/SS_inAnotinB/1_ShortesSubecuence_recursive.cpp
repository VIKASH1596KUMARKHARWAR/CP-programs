// Gary has two string S and V. Now, Gary wants to know the length of shortest subsequence in S, which is not a subsequence in V.

/*A subsequence of a string is any sequence that can be derived from the string by deleting some or no characters without changing the order of the remaining characters

for exampel babab
"b" "a" "ba" "bb" "ab" "aa" "bab" "bba" "baa" "aba" "babb" "babab"*/

/*Subsequences can be non-contiguous and can be formed by removing some or all characters  without changing the order of the remaining characters.
Substrings are always contiguous parts of the original string.

Subsequences of "abc"
"", "a", "b", "c", "ab", "ac", "bc", "abc"

Substrings of "abc"
"a", "ab", "abc", "b", "bc", "c"

*/
#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution
{
public:
    int solve(const string &s, const string &v)
    {
        int minLength = INT_MAX;
        findShortestSubsequenceLength(s, v, 0, "", minLength);
        return minLength == INT_MAX ? -1 : minLength;
    }

private:
    // Helper function to check if sub is a subsequence of v
    bool isSubsequence(const string &sub, const string &v) const
    {
        int j = 0;
        for (int i = 0; i < v.length() && j < sub.length(); i++)
        {
            if (v[i] == sub[j])
            {
                ++j;
            }
        }
        return j == sub.length();
    }

    // Recursive function to find the shortest subsequence length not in v
    void findShortestSubsequenceLength(const string &s, const string &v, int index, string current, int &minLength) const
    {
        if (index == s.length())
        {
            if (!current.empty() && !isSubsequence(current, v))
            {
                minLength = min(minLength, static_cast<int>(current.length()));
            }
            return;
        }

        // include the current character and move to the next index
        findShortestSubsequenceLength(s, v, index + 1, current + s[index], minLength);

        // exclude the current character and move to the next index
        findShortestSubsequenceLength(s, v, index + 1, current, minLength);
    }
};

int main()
{
    Solution coderXp;
    string s, v;
    cin >> s >> v;
    cout << coderXp.solve(s, v) << endl;
    return 0;
}
/*s = "abc"
v = "xyz"

ans 1 ..... In this case, since string v does not contain any of the characters present in string s, any single character from s would not be a subsequence of v. Hence, the shortest subsequence length is 1.*/

/*s = "babab"
v = "babba"
ans 3 ...A subsequence like "aab" or "baa" in string s is not a subsequence in string v. The length of "aab" is 3, and it is the shortest such subsequence.*/