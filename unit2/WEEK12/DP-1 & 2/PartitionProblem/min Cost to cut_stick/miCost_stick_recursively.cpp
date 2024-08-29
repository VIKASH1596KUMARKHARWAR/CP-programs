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
        // Add the endpoints of the stick to the cuts array
        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        return helper(0, m - 1, cuts);
    }

private:
    int helper(int i, int j, const vector<int> &cuts)
    {
        // Base case: if there are no segments between i and j
        if (j - i <= 1)
            return 0;

        int mini = INT_MAX;
        // Try every possible cut between i and j
        for (int idx = i + 1; idx < j; ++idx)
        {
            int cost = cuts[j] - cuts[i] + helper(i, idx, cuts) + helper(idx, j, cuts);
            mini = min(mini, cost);
        }
        return mini;
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
