//Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .

// There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.



#include <iostream>
#include <vector>
using namespace std;

const string TARGET = "CODINGNINJA";
const int TARGET_LENGTH = TARGET.length();
const vector<pair<int, int>> DIRECTIONS = {
    {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
};

bool isSafe(int x, int y, int N, int M) {
    return (x >= 0 && x < N && y >= 0 && y < M);
}

bool dfs(vector<vector<char>>& matrix, int x, int y, int index, vector<vector<bool>>& visited) {
    if (index == TARGET_LENGTH) return true;

    if (!isSafe(x, y, matrix.size(), matrix[0].size()) ||
        visited[x][y] || matrix[x][y] != TARGET[index]) return false;

    visited[x][y] = true;
    bool found = false;
    
    for (const auto& dir : DIRECTIONS) {
        int newX = x + dir.first;
        int newY = y + dir.second;
        if (dfs(matrix, newX, newY, index + 1, visited)) {
            found = true;
            break;
        }
    }

    visited[x][y] = false; // Unmark the cell to allow other paths
    return found;
}

bool findPath(vector<vector<char>>& matrix) {
    int N = matrix.size();
    int M = matrix[0].size();
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (matrix[i][j] == TARGET[0] && dfs(matrix, i, j, 0, visited)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<char>> matrix(N, vector<char>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << (findPath(matrix) ? 1 : 0) << endl;
    return 0;
}



/*
bool bfs(vector<vector<char>>& matrix, int x, int y) {
    int N = matrix.size();
    int M = matrix[0].size();
    vector<vector<vector<bool>>> visited(N, vector<vector<bool>>(M, vector<bool>(TARGET_LEN, false)));

    queue<pair<pair<int, int>, int>> q; // ((x, y), index in TARGET)
    q.push({{x, y}, 0});
    visited[x][y][0] = true;

    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        
        int curX = current.first.first;
        int curY = current.first.second;
        int index = current.second;

        // If we have reached the last character in TARGET
        if (index == TARGET_LEN - 1) {
            return true;
        }

        // Explore all 8 possible directions
        for (int d = 0; d < 8; ++d) {
            int newX = curX + DIRECTIONS_X[d];
            int newY = curY + DIRECTIONS_Y[d];
            
            if (isSafe(newX, newY, N, M) && !visited[newX][newY][index + 1] && matrix[newX][newY] == TARGET[index + 1]) {
                visited[newX][newY][index + 1] = true;
                q.push({{newX, newY}, index + 1});
            }
        }
    }

    return false;
}*/