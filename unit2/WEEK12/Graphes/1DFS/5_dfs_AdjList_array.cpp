#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &ls) {
        vis[node] = 1; 
        ls.push_back(node); 
        // Traverse all its neighbours
        for(int neighbor : adj[node]) {
            // If the neighbour is not visited
            if(!vis[neighbor]) {
                dfs(neighbor, adj, vis, ls); 
            }
        }
    }
public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V, 0); // Using vector for visited array
        vector<int> ls; 
        // Call dfs for every node to cover all connected components
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i, adj, vis, ls); 
            }
        }
        return ls; 
    }
};

// Function to add an edge to an undirected graph
void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Function to print the DFS result
void printAns(const vector<int> &ans) {
    for(int node : ans) {
        cout << node << " ";
    }
    cout << endl; // Print a newline at the end
}

int main() {
    const int V = 5; // Number of vertices in the graph
    vector<int> adj[V];
    
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);

    Solution obj;
    vector<int> ans = obj.dfsOfGraph(V, adj);
    printAns(ans);

    return 0;
}



    // 1
    // |
    // 0 -- 2 -- 4
    // |
    // 3

// vector<int>: This specifies a vector container that holds elements of type int. The vector is a dynamic array provided by the C++ Standard Library that can grow or shrink in size as needed.
// adj: This is the name of the array of vectors.
// [5]: This specifies the size of the array. In this case, it means that the array will have 5 elements, each of which is a vector<int>.