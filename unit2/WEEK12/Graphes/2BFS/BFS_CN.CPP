/*Given an undirected and disconnected graph G(V, E), print its BFS traversal.

Note:

1. Here you need to consider that you need to print BFS path starting from vertex 0 only.
2. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
3. E is the number of edges present in graph G.
4. Take graph input in the adjacency matrix.
5. Handle for Disconnected Graphs as well

9 10
0 8
1 6
1 7
1 8
5 8
6 0
7 3
7 4
8 7
2 5

OUTPUT 0 6 8 1 5 7 2 3 4
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
private:
    void bfs(int start, int V, const vector<vector<int>> &adjMatrix, vector<bool> &vis, vector<int> &ls)
    {
        queue<int> q;
        q.push(start);
        vis[start] = true;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            ls.push_back(curr);

            for (int i = 0; i < V; i++)
            {
                if (adjMatrix[curr][i] == 1 && !vis[i])
                {
                    q.push(i);
                    vis[i] = true;
                }
            }
        }
    }

public:
    // Function to return a list containing the BFS traversal of the graph.
    vector<int> bfsOfGraph(int V, const vector<vector<int>> &adjMatrix)
    {
        vector<bool> vis(V, false);
        vector<int> ls;

        // Perform BFS starting from vertex 0
        if (V > 0)
        {
            bfs(0, V, adjMatrix, vis, ls);
        }

        // If no edges, we might still want to include all vertices
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                ls.push_back(i);
            }
        }

        return ls;
    }
};

void addEdges(vector<vector<int>> &adjMatrix, int u, int v)
{
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
}

void printAns(const vector<int> &ans)
{
    if (ans.empty())
    {
        // Output nothing if the result is empty
        cout << endl;
    }
    else
    {
        for (int i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main()
{
    int V, E;
    cin >> V;

    // If there are no vertices, handle this case by not processing edges or graph
    if (V == 0)
    {
        cout << endl; // No vertices, so output is just a blank line
        return 0;
    }

    vector<vector<int>> adjMatrix(V, vector<int>(V, 0));
    cin >> E;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u >= 0 && u < V && v >= 0 && v < V)
        {
            addEdges(adjMatrix, u, v);
        }
    }

    Solution obj;
    vector<int> bfsans = obj.bfsOfGraph(V, adjMatrix);

    printAns(bfsans);

    return 0;
}
