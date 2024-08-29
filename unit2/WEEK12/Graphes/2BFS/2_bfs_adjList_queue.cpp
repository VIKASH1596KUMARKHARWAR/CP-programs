#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
  private: 
    void bfs(int start, vector<vector<int>> &adjList, vector<bool> &vis, vector<int> &ls) {
        queue<int> q;
        q.push(start);
        vis[start] = true;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            ls.push_back(curr);

            // Traverse all its neighbours
            for (int neighbor : adjList[curr]) {
                if (!vis[neighbor]) {
                    q.push(neighbor);
                    vis[neighbor] = true;
                }
            }
        }
    }
  public:
    // Function to return a list containing the BFS traversal of the graph.
    vector<int> bfsOfGraph(int V, vector<vector<int>> &adjList) {
        vector<bool> vis(V, false); 
        vector<int> ls; 

        // Ensure all nodes are considered to handle disconnected components
        for (int i = 0; i < V; ++i) {
            if (!vis[i]) {
                bfs(i, adjList, vis, ls); 
            }
        }

        return ls; 
    }
};

void addEdge(vector<vector<int>> &adjList, int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u); // For undirected graph
}

void printAns(const vector<int> &ans) {
    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl; // for newline after printing all nodes
}

int main() {
    int V = 5;
    vector<vector<int>> adjList(V);
    
    addEdge(adjList, 0, 2);
    addEdge(adjList, 2, 4);
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 3);

    Solution obj;
    vector<int> bfsAns = obj.bfsOfGraph(V, adjList);
    
    cout << "BFS Traversal: ";
    printAns(bfsAns);

    return 0;
}
// Time Complexity of BFS Algorithm: O(V + E)
// BFS uses a queue to keep track of the vertices that need to be visited. In the worst case, the queue can contain all the vertices in the graph. Therefore, the space complexity of BFS is O(V).


// Answer: BFS is a graph traversal algorithm that systematically explores a graph by visiting all the vertices at a given level before moving on to the next level. It starts from a starting vertex, enqueues it into a queue, and marks it as visited. Then, it dequeues a vertex from the queue, visits it, and enqueues all its unvisited neighbors into the queue. This process continues until the queue is empty.

/* uses:: 

Shortest Path Finding,Cycle Detection,Connected Components,Topological Sorting,Level Order Traversal of Binary Trees,Network Routing::BFS can be used to find the shortest path between two nodes in a network, making it useful for routing data packets in network protocols.
*/