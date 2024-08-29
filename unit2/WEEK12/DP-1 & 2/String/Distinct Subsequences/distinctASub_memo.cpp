#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        // Memoization table: stores results of subproblems
        unordered_map<string, int> memo;
        return numDistinctHelper(s, t, 0, 0, memo);
    }

private:
    // Helper function for recursion with memoization
    int numDistinctHelper(const string &s, const string &t, int i, int j, unordered_map<string, int> &memo)
    {
        // Base case: If all characters of t are matched
        if (j == t.size())
        {
            return 1; // Successfully matched all characters of t
        }

        // Base case: If we've run out of characters in s
        if (i == s.size())
        {
            return 0; // No more characters to match t
        }

        // Create a unique key for the current state
        string key = to_string(i) + "|" + to_string(j);

        // Check if the result is already in the memo
        if (memo.find(key) != memo.end())
        {
            return memo[key];
        }

        int result;
        if (s[i] == t[j])
        {
            // If characters match, consider both including and excluding this character
            result = numDistinctHelper(s, t, i + 1, j + 1, memo) + numDistinctHelper(s, t, i + 1, j, memo);
        }
        else
        {
            // If characters don't match, skip the current character of s
            result = numDistinctHelper(s, t, i + 1, j, memo);
        }

        // Store the result in the memo and return it
        memo[key] = result;
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

    // Additional test cases
    string s3 = "aabbcc";
    string t3 = "abc";
    cout << "Number of distinct subsequences of \"" << s3 << "\" that equal \"" << t3 << "\" is: " << sol.numDistinct(s3, t3) << endl;

    string s4 = "abc";
    string t4 = "a";
    cout << "Number of distinct subsequences of \"" << s4 << "\" that equal \"" << t4 << "\" is: " << sol.numDistinct(s4, t4) << endl;

    string s5 = "";
    string t5 = "any";
    cout << "Number of distinct subsequences of \"" << s5 << "\" that equal \"" << t5 << "\" is: " << sol.numDistinct(s5, t5) << endl;

    string s6 = "any";
    string t6 = "";
    cout << "Number of distinct subsequences of \"" << s6 << "\" that equal \"" << t6 << "\" is: " << sol.numDistinct(s6, t6) << endl;

    return 0;
}
