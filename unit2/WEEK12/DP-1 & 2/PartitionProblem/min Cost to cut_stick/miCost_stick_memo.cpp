/*Time Complexity Analysis
Number of Subproblems:

The memoization table memo[i][j] stores results for all possible subproblems defined by pairs (i, j). Since i and j can range from 0 to m - 1 (where m is the number of cuts plus two endpoints), the total number of subproblems is approximately 𝑂(𝑚2)

Cost of Each Subproblem :

    For each subproblem defined
    by(i, j),
    the function considers every possible cut idx between i and j.The number of possible cuts between i and j is approximately O(m),
    as idx can range from i + 1 to j - 1. Total Time Complexity :

    Each subproblem is solved in O(m) time(due to iterating over possible cuts idx)
        .There are 𝑂(𝑚2) subproblems.Thus,

   `````````````````````` the overall time complexity is O(m 3),

    where m is the number of elements in the cuts array plus the two endpoints.Space Complexity
    Memoization Table :

    The memo table has a size of m×m,
    where m is the number of elements in cuts plus the two endpoints.Thus,
    the space complexity due to memoization is
    O(m 2)
        .Recursive Call Stack :

    The maximum depth of the recursion stack is O(m)
in the worst case, where each level represents a segment between two cuts.Total Space Complexity:

The total space complexity is

    O(m 2) due to the memoization table and O(m) due to the recursion stack,
    so the overall space complexity is dominated by
    O(m 2).
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
    int minCost(int n, vector<int> &cuts)
    {
        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());

        int m = cuts.size();

        vector<vector<int>> memo(m, vector<int>(m, -1));

        return helper(0, m - 1, cuts, memo);
    }

private:
    int helper(int i, int j, const vector<int> &cuts, vector<vector<int>> &memo)
    {
        if (j - i <= 1)
            return 0;

        if (memo[i][j] != -1)
            return memo[i][j];

        int mini = INT_MAX;

        for (int idx = i + 1; idx < j; ++idx)
        {
            int cost = cuts[j] - cuts[i] + helper(i, idx, cuts, memo) + helper(idx, j, cuts, memo);
            mini = min(mini, cost);
        }

        return memo[i][j] = mini;
    }
};

int main()
{
    Solution sol;
    int n = 7;
    vector<int> cuts = {1, 3, 4, 5};

    cout << "Minimum cost of cuts: " << sol.minCost(n, cuts) << endl;

    return 0;
}
