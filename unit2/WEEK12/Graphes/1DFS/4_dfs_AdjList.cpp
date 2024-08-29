#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
private:
    void dfs(int node, vector<vector<int>> &adjList, vector<bool> &vis, vector<int> &ls) {
        stack<int> s;
        s.push(node);

        while (!s.empty()) {
            int curr = s.top();
            s.pop();

            if (vis[curr]) continue;

            vis[curr] = true;
            ls.push_back(curr);

            // Traverse all its neighbours in sorted order
            vector<int> neighbors = adjList[curr];
            sort(neighbors.begin(), neighbors.end()); // Ensure neighbors are processed in ascending order
            for (int neighbour : neighbors) {
                if (!vis[neighbour]) {
                    s.push(neighbour);
                }
            }
        }
    }

public:
    vector<int> dfsOfGraph(int V, vector<vector<int>> &adjList) {
        vector<bool> vis(V, false); 
        vector<int> ls; 

        for (int i = 0; i < V; ++i) {
            if (!vis[i]) {
                dfs(i, adjList, vis, ls);
            }
        }

        return ls;
    }
};

void addEdge(vector<vector<int>> &adjList, int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u); // For undirected graph
}

void printGraph(const vector<vector<int>> &adjList) {
    for (int i = 0; i < adjList.size(); ++i) {
        cout << "Adjacency list of vertex " << i << ": ";
        for (int v : adjList[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
}

void printAns(const vector<int> &ans) {
    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int V = 5;
    vector<vector<int>> adjList(V);

    addEdge(adjList, 0, 2);
    addEdge(adjList, 2, 4);
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 3);

    cout << "Graph representation (adjacency lists):" << endl;
    printGraph(adjList); // Print the adjacency list to debug

    Solution obj;
    vector<int> ans = obj.dfsOfGraph(V, adjList);
    cout << "DFS Traversal: ";
    printAns(ans);

    return 0;
}
