#include <bits/stdc++.h>
using namespace std;

// Function to add an edge to the adjacency list
void addEdge(vector<vector<int>> &adj, int s, int t){
    // Add edge from vertex s to t
    adj[s].push_back(t); 
    // Due to undirected Graph
    adj[t].push_back(s);
}

// Recursive function for DFS traversal
void DFSRec(vector<vector<int>> &adj, vector<bool> &visited, int s){
    // Mark the current vertex as visited
    visited[s] = true;

    // Print the current vertex
    cout << s << " ";

    // Recursively visit all adjacent vertices that are not visited yet
    for (int i : adj[s])
        if (visited[i] == false)
            DFSRec(adj, visited, i);
}

// Main DFS function that initializes the visited array
// and call DFSRec
void DFS(vector<vector<int>> &adj, int s){
    vector<bool> visited(adj.size(), false);
    // Call the recursive DFS function
    DFSRec(adj, visited, s);
}

int main(){
    int V = 5; // Number of vertices in the graph

    // Create an adjacency list for the graph
    vector<vector<int>> adj(V);

    // Define the edges of the graph
    vector<vector<int>> edges={{1, 2},{1, 0},{ 0,2},{2, 3},{2, 4}};

    // Populate the adjacency list with edges
    for (auto &e : edges)
        addEdge(adj, e[0], e[1]);

    int source =1; // Starting vertex for DFS
    
    cout << "DFS from source: " << source << endl;
    DFS(adj, source); // Perform DFS starting from the source vertex

    return 0;
}
