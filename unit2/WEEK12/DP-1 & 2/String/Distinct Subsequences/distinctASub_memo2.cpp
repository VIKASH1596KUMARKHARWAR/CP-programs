// this avoids creating the large string keys for the memoization map and can be more space-efficient for problems with bounded input sizes.

// The value at memo[i][j] represents the number of distinct subsequences of s[0..i] (i.e., the substring from the start of s up to index i) that match t[0..j] (i.e., the substring from the start of t up to index j).
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
        // Initialize memoization table with -1 indicating uncomputed values
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
        return numDistinctHelper(s, t, m - 1, n - 1, memo);
    }

private:
    int numDistinctHelper(const string &s, const string &t, int i, int j, vector<vector<int>> &memo)
    {
        // Base cases
        if (j < 0)
        {
            return 1; // An empty t can always be formed from any prefix of s
        }
        if (i < 0)
        {
            return 0; // If s is empty but t is not, we can't form t
        }

        // Check if the result is already in the memo table
        if (memo[i][j] != -1)
        {
            return memo[i][j];
        }

        int result;
        if (s[i] == t[j])
        {
            // If characters match, we can either include this character or skip it
            result = numDistinctHelper(s, t, i - 1, j - 1, memo) + numDistinctHelper(s, t, i - 1, j, memo);
        }
        else
        {
            // If characters don't match, skip the current character of s
            result = numDistinctHelper(s, t, i - 1, j, memo);
        }

        // Store the result in the memo table and return it
        memo[i][j] = result;
        return result;
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

    // Test case 3
    string s3 = "aaaa";
    string t3 = "aa";
    cout << "Number of distinct subsequences of \"" << s3 << "\" that equal \"" << t3 << "\" is: " << sol.numDistinct(s3, t3) << endl;

    // Test case 4
    string s4 = "abc";
    string t4 = "def";
    cout << "Number of distinct subsequences of \"" << s4 << "\" that equal \"" << t4 << "\" is: " << sol.numDistinct(s4, t4) << endl;

    // Test case 5
    string s5 = "";
    string t5 = "any";
    cout << "Number of distinct subsequences of \"" << s5 << "\" that equal \"" << t5 << "\" is: " << sol.numDistinct(s5, t5) << endl;
    // To form the string t from s, you need at least as many characters in s as there are in t. Since s is empty, it is impossible to form any non-empty string t from it.
    // The number of distinct subsequences of an empty string s that match a non-empty string t is 0. This is because there are no characters in s to match against t, so no subsequence of s can form t.

    // Test case 6
    string s6 = "any";
    string t6 = "";
    cout << "Number of distinct subsequences of \"" << s6 << "\" that equal \"" << t6 << "\" is: " << sol.numDistinct(s6, t6) << endl;
    // Here, s is "any", which is a non-empty string, and t is an empty string "".
    //  To form an empty string t from s, you can do so by selecting no characters from s at all.In other words, any string s can form the empty string t by simply not selecting any characters.

    return 0;
}