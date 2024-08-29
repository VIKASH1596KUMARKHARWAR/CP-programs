#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
private:
        void bfs(int start, vector<vector<int>> &adjMatrix, vector<bool> &vis, vector<int> &ls) {
        queue<int> q;
        q.push(start);
        vis[start] = true;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            ls.push_back(curr);

            // Traverse all its neighbours
            for (int i = 0; i < adjMatrix.size(); ++i) {
                if (adjMatrix[curr][i] == 1 && !vis[i]) {
                    q.push(i);
                    vis[i] = true;
                }
            }
        }
    }

public:
    // Function to return a list containing the BFS traversal of the graph.
    vector<int> bfsOfGraph(int V, vector<vector<int>> &adjMatrix)
    {
        vector<bool> vis(V, false);
        vector<int> ls;

        // Ensure all nodes are considered to handle disconnected components
        for (int i = 0; i < V; ++i)
        {
            if (!vis[i])
            {
                bfs(i, adjMatrix, vis, ls);
            }
        }

        return ls;
    }
};

void addEdge(vector<vector<int>> &adjMatrix, int u, int v)
{
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
}

void printAns(const vector<int> &ans)
{
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl; // for newline after printing all nodes
}

int main()
{
    int V = 5;
    vector<vector<int>> adjMatrix(V, vector<int>(V, 0));

    addEdge(adjMatrix, 0, 2);
    addEdge(adjMatrix, 2, 4);
    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 3);

    Solution obj;
    vector<int> bfsAns = obj.bfsOfGraph(V, adjMatrix);

    cout << "BFS Traversal: ";
    printAns(bfsAns);

    return 0;
}