#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Helper function to check if a substring is a palindrome
    bool isPalindrome(int start, int end, const string &s)
    {
        while (start < end)
        {
            if (s[start] != s[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    // Recursive function to find the minimum number of partitions to make palindromes
    int minPartitions(int i, int n, const string &str)
    {
        // Base case: If we've reached the end of the string
        if (i >= n)
            return 0;

        int minCost = INT_MAX;

        // Consider all possible substrings starting from the current index
        for (int j = i; j < n; ++j)
        {
            if (isPalindrome(i, j, str))
            {
                // If the substring is a palindrome, calculate the cost and minimize it
                int cost = 1 + minPartitions(j + 1, n, str);
                minCost = min(minCost, cost);
            }
        }
        return minCost;
    }

    // Function to start the recursion and adjust the result to be the number of cuts
    int palindromePartitioning(const string &str)
    {
        int n = str.size();
        // Calling the recursive function and subtracting 1 as it counts partitions, not cuts
        return minPartitions(0, n, str) - 1;
    }
};

int main()
{
    Solution s;
    string str = "BABABCBADCEDE";
    int partitions = s.palindromePartitioning(str);
    cout << "The minimum number of partitions: " << partitions << "\n";
    return 0;
}
