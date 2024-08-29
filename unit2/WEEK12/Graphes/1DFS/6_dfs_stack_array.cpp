#include <iostream>
#include <stack>
#include <cstring> // For memset

using namespace std;

class Solution {
  private: 
    void dfs(int node, int V, int adjMatrix[][5], bool vis[], int ls[], int &index) {
        stack<int> s;
        s.push(node);
        
        while (!s.empty()) {
            int curr = s.top();
            s.pop();

            if (vis[curr]) continue;

            vis[curr] = true;
            ls[index++] = curr; // Fill result array and increment index

            // Traverse all its neighbours
            for (int i = 0; i < V; ++i) {
                if (adjMatrix[curr][i] == 1 && !vis[i]) {
                    s.push(i);
                }
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    int* dfsOfGraph(int V, int adjMatrix[][5]) {
        bool vis[V]; 
        memset(vis, false, sizeof(vis)); // Initialize visitation status
        int *ls = new int[V]; // Allocate array dynamically
        int index = 0; // Index to keep track of position in ls

        // Ensure all nodes are considered to handle disconnected components
        for (int i = 0; i < V; ++i) {
            if (!vis[i]) {
                dfs(i, V, adjMatrix, vis, ls, index); 
            }
        }

        return ls; 
    }
};

void addEdge(int adjMatrix[][5], int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
}

void printAns(const int *ans, int size) {
    for (int i = 0; i < size; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl; // for newline after printing all nodes
}

int main() {
    const int V = 5;
    int adjMatrix[V][5] = {0}; // Initialize adjacency matrix to 0
    
    addEdge(adjMatrix, 0, 2);
    addEdge(adjMatrix, 2, 4);
    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 3);

    Solution obj;
    int *ans = obj.dfsOfGraph(V, adjMatrix);
    printAns(ans, V);

    delete[] ans; // Clean up dynamically allocated memory
    return 0;
}
