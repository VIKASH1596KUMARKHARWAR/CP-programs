/*Write a C++ program to search for specified words within a 2D board of characters. The program should be able to find each word's starting position and trace the path taken to form the word, indicating the directions (RIGHT, DOWN, LEFT, UP) taken between consecutive characters.

The program should include:

A function exist that searches for a given word (word) in a 2D grid (board) of characters. The function should return true if the word is found, along with the starting position (row, col) of the word and the sequence of directions taken to form the word.
The directions should be recorded in a vector and printed alongside the path coordinates.
Assume the following:

The board is represented as a vector of vectors (vector<vector<char>>).
The directions of movement are: RIGHT (→), DOWN (↓), LEFT (←), UP (↑).*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Directions for right, down, left, up (clockwise order)
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};
vector<string> direction_names = {"RIGHT", "DOWN", "LEFT", "UP"};

// Function to check if the word exists starting from position (row, col)
bool searchWord(vector<vector<char>> &board, int row, int col, string &word, int index,
                vector<pair<int, int>> &path, unordered_set<int> &visited)
{
    int R = board.size();
    int C = board[0].size();

    // If we've matched all characters in the word
    if (index == word.length())
    {
        return true;
    }

    // Check boundaries and if current character matches
    if (row < 0 || row >= R || col < 0 || col >= C || board[row][col] != word[index] ||
        visited.find(row * C + col) != visited.end())
    {
        return false;
    }

    // Mark current cell as visited
    visited.insert(row * C + col);
    path.push_back({row, col});

    // Recursively search in all 4 directions
    for (int d = 0; d < 4; ++d)
    {
        if (searchWord(board, row + dx[d], col + dy[d], word, index + 1, path, visited))
        {
            return true;
        }
    }

    // Backtrack
    path.pop_back();
    visited.erase(row * C + col);

    return false;
}

// Function to check if the word exists in the board and return the path and directions
bool exist(vector<vector<char>> &board, string word, vector<pair<int, int>> &path, vector<string> &directions, pair<int, int> &start)
{
    int R = board.size();
    int C = board[0].size();

    // Iterate through each cell in the board
    for (int row = 0; row < R; ++row)
    {
        for (int col = 0; col < C; ++col)
        {
            // If the first character matches, start searching
            if (board[row][col] == word[0])
            {
                unordered_set<int> visited;
                path.clear();
                if (searchWord(board, row, col, word, 0, path, visited))
                {
                    start = {row, col};

                    // Collect directions for the path
                    directions.clear();
                    for (size_t i = 1; i < path.size(); ++i)
                    {
                        int prevRow = path[i - 1].first;
                        int prevCol = path[i - 1].second;
                        int currRow = path[i].first;
                        int currCol = path[i].second;

                        if (prevRow == currRow)
                        {
                            if (prevCol < currCol)
                                directions.push_back("RIGHT");
                            else
                                directions.push_back("LEFT");
                        }
                        else
                        {
                            if (prevRow < currRow)
                                directions.push_back("DOWN");
                            else
                                directions.push_back("UP");
                        }
                    }

                    return true;
                }
            }
        }
    }

    return false;
}

// Example usage
int main()
{
    vector<vector<char>> board = {
        {'G', 'E', 'E', 'K', 'S', 'F', 'O', 'R', 'G', 'E', 'E', 'K', 'S'},
        {'G', 'E', 'E', 'K', 'S', 'Q', 'U', 'I', 'Z', 'G', 'E', 'E', 'K'},
        {'I', 'D', 'E', 'Q', 'A', 'P', 'R', 'A', 'C', 'T', 'I', 'C', 'E'}};

    string word1 = "GEEKS";
    string word2 = "SAP";

    vector<pair<int, int>> path;
    vector<string> directions;
    pair<int, int> start;

    if (exist(board, word1, path, directions, start))
    {
        cout << "Found '" << word1 << "' starting at index (" << start.first << ", " << start.second << ")" << endl;
        cout << "Path: ";
        for (size_t i = 0; i < path.size(); ++i)
        {
            cout << "(" << path[i].first << ", " << path[i].second << ")";
            if (i < directions.size())
            {
                cout << " -> " << directions[i];
            }
            cout << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Did not find '" << word1 << "'" << endl;
    }

    path.clear();
    directions.clear();
    if (exist(board, word2, path, directions, start))
    {
        cout << "Found '" << word2 << "' starting at index (" << start.first << ", " << start.second << ")" << endl;
        cout << "Path: ";
        for (size_t i = 0; i < path.size(); ++i)
        {
            cout << "(" << path[i].first << ", " << path[i].second << ")";
            if (i < directions.size())
            {
                cout << " -> " << directions[i];
            }
            cout << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Did not find '" << word2 << "'" << endl;
    }

    return 0;
}
