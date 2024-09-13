#include <iostream>
#include <vector>
using namespace std;

// DFS function to mark all reachable vertices from the given vertex
void dfs(int **edges, int n, int currentVertex, vector<bool>& visited) {
    visited[currentVertex] = true;

    for (int i = 0; i < n; i++) {
        if (edges[currentVertex][i] == 1 && !visited[i]) {
            dfs(edges, n, i, visited);
        }
    }
}

// Function to check if the graph is connected
bool isConnected(int **edges, int n) {
    vector<bool> visited(n, false);

    // Perform DFS starting from vertex 0
    dfs(edges, n, 0, visited);

    // Check if all vertices were visited
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

    // adjacency matrix
    int **edges = new int *[n];
    for (int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++) {
            edges[i][j] = 0;
        }
    }

    // Input edges
    for (int i = 0; i < e; i++) {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    // Check if the graph is connected
    bool result = isConnected(edges, n);
    cout << (result ? "true" : "false") << endl;

    // Free dynamically allocated memory
    for (int i = 0; i < n; i++) {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}
