
/*Whis and Beerus are playing a new game today. They form a tower of N coins and make a move in alternate turns. Beerus plays first. In one step, the player can remove either 1, X, or Y coins from the tower. The person to make the last move wins the game. Can you find out who wins the game?*/

// approach :: yaha pe ese harayenge - beerus ko

#include <iostream>
using namespace std;
class Solution
{

public:
    string findWinner(int n, int x, int y)
    {
        if (n == 0)
            return "Whis"; // if there is no coin the current player loos ie. Beerus (he started the first)

        // Check if removing 1 coin leads to a losing position for the opponent
        if (n >= 1 && findWinner(n - 1, x, y) == "Whis")
            return "Beerus";

        // Check if removing x coins leads to a losing position for the opponent
        if (n >= x && findWinner(n - x, x, y) == "Whis")
            return "Beerus";

        // Check if removing y coins leads to a losing position for the opponent
        if (n >= y && findWinner(n - y, x, y) == "Whis")
            return "Beerus";

        // If no move leads to a losing position for the opponent, the current player loses
        return "Whis";
    }
};

int main()
{
    Solution s;
    int n = 7; // number of coins
    int x = 2;
    int y = 3;

    cout << s.findWinner(n, x, y) << endl; // Output the result
    return 0;
}
