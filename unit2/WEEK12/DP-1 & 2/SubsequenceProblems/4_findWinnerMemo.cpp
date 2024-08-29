#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string findWinner(int n, int x, int y)
    {
        vector<int> memo(n + 1, -1);
        bool beerusWins = canWin(n, x, y, memo);
        return beerusWins ? "Beerus" : "Whis";
    }

private:
    bool canWin(int n, int x, int y, vector<int> &memo)
    {
        if (n == 0)
            return false;

        if (memo[n] != -1)
            return memo[n] == 1;

        bool win = false;

        if (n >= 1 && !canWin(n - 1, x, y, memo))
            win = true;

        if (n >= x && !canWin(n - x, x, y, memo))
            win = true;

        if (n >= y && !canWin(n - y, x, y, memo))
            win = true;

        memo[n] = win ? 1 : 0;
        return win;
    }
};

int main()
{
    Solution s;
    int n = 7;
    int x = 2;
    int y = 1;

    int n1 = 4;
    int x1 = 2;
    int y1 = 3;
    cout << s.findWinner(n, x, y) << endl;
    cout << s.findWinner(n1, x1, y1) << endl;
    return 0;
}
