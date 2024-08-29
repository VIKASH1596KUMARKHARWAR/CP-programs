#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &ls) {
        vis[node] = 1;
        ls.push_back(node);
        // Traverse all its neighbors
        for (auto it : adj[node]) {
            // If the neighbor is not visited
            if (!vis[it]) {
                dfs(it, adj, vis, ls);
            }
        }
    }
public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[], int start) {
        vector<int> vis(V, 0);
        vector<int> ls;
        // Call DFS for the starting node
        dfs(start, adj, vis, ls);
        return ls;
    }
};

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(const vector<int> &ans) {
    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<int> adj[V];
    
    cout << "Enter the edges (each edge as two integers separated by space):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }

    int start;
    cout << "Enter the starting vertex for DFS: ";
    cin >> start;

    Solution obj;
    vector<int> ans = obj.dfsOfGraph(V, adj, start);
    printAns(ans);

    return 0;
}
