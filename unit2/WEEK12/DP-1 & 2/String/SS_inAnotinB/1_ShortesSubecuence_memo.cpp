#include <iostream>
#include <string>
#include <climits>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int solve(const string &s, const string &v)
    {
        int minLength = INT_MAX;
        // Memoization table: stores results of subproblems (index, current subsequence)
        unordered_map<string, int> memo;
        findShortestSubsequenceLength(s, v, 0, "", minLength, memo);
        return minLength == INT_MAX ? -1 : minLength;
    }

private:
    // Helper function to check if 'sub' is a subsequence of 'v'
    bool isSubsequence(const string &sub, const string &v) const
    {
        int j = 0; // Pointer for 'sub'
        for (int i = 0; i < v.length() && j < sub.length(); i++)
        {
            if (v[i] == sub[j])
            {
                ++j; // Move to next character in 'sub'
            }
        }
        // Return true if all characters of 'sub' are found in 'v' in the same order
        return j == sub.length();
    }

    // Recursive function to find the shortest subsequence length not in 'v'
    void findShortestSubsequenceLength(const string &s, const string &v, int index, string current, int &minLength, unordered_map<string, int> &memo) const
    {
        // Create a unique key for the current state
        string key = to_string(index) + "|" + current;

        // Check if this state has been computed before
        if (memo.find(key) != memo.end())
        {
            // Update minLength with the memoized result if it's smaller
            minLength = min(minLength, memo[key]);
            return;
        }

        // Base case: if all characters of 's' have been processed
        if (index == s.length())
        {
            if (!current.empty() && !isSubsequence(current, v))
            {
                // Update minLength if current subsequence is not in 'v'
                minLength = min(minLength, static_cast<int>(current.length()));
            }
            // Store the result in the memoization table
            memo[key] = minLength;
            return;
        }

        // Include the current character and move to the next index
        findShortestSubsequenceLength(s, v, index + 1, current + s[index], minLength, memo);

        // Exclude the current character and move to the next index
        findShortestSubsequenceLength(s, v, index + 1, current, minLength, memo);

        // Store the result in the memoization table after processing both scenarios
        memo[key] = minLength;
    }
};

int main()
{
    Solution coderXp;
    string s, v;
    cin >> s >> v;
    // Output the length of the shortest subsequence of 's' not found in 'v'
    cout << coderXp.solve(s, v) << endl;
    return 0;
}

// if (memo.find(key) != memo.end()) // It returns an iterator to the element if it is found, or an iterator to the end of the container if it is not found