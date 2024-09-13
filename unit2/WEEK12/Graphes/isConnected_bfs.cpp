#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS function to check connectivity
bool isConnected(const vector<vector<int>>& edges, int n) {
    vector<bool> visited(n, false);
    queue<int> pendingVertices;

    pendingVertices.push(0);
    visited[0] = true;

    while (!pendingVertices.empty()) {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();

        for (int i = 0; i < n; i++) {
            if (edges[currentVertex][i] == 1 && !visited[i]) {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            return false; // If any vertex is not visited, graph is not connected
        }
    }

    return true; // All vertices are visited, graph is connected
}

int main() {
    int n, e;
    cin >> n >> e;

    // adjacency matrix using vector
    vector<vector<int>> edges(n, vector<int>(n, 0));

    for (int i = 0; i < e; i++) {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    // Check if the graph is connected
    bool result = isConnected(edges, n);
    cout << (result ? "true" : "false") << endl;

    return 0;
}


/*
4 4
0 1
0 3
1 2


2 3
true*/