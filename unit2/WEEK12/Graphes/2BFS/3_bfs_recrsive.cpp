#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Function to recursively process nodes
void bfs_recursive(const vector<vector<int>>& graph, set<int>& visited, vector<int>& result, int node) {
    if (visited.find(node) != visited.end()) {
        return; // Node already visited
    }

    visited.insert(node);
    result.push_back(node);

    // Recursively visit all unvisited neighbors
    for (int neighbor : graph[node]) {
        if (visited.find(neighbor) == visited.end()) {
            bfs_recursive(graph, visited, result, neighbor);
        }
    }
}

vector<int> bfs(const vector<vector<int>>& graph, int start_node) {
    set<int> visited;  // To keep track of visited nodes
    vector<int> result;

    // Start the recursion from the starting node
    bfs_recursive(graph, visited, result, start_node);

    return result;
}

int main() {
    // Example graph represented as an adjacency list
    vector<vector<int>> graph = {
    {1, 2},       // Node 0 is connected to Node 1 and Node 2
    {0, 2, 3},    // Node 1 is connected to Node 0, Node 2, and Node 3
    {0, 1, 4},    // Node 2 is connected to Node 0, Node 1, and Node 4
    {1, 4},       // Node 3 is connected to Node 1 and Node 4
    {2, 3}        // Node 4 is connected to Node 2 and Node 3
};

    int start_node = 0;
    vector<int> result = bfs(graph, start_node);

    cout << "BFS traversal starting from node " << start_node << ": ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
