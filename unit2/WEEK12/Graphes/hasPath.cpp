/*Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), check if there exists any path between them or not. Print true if the path exists and false otherwise.

Note:

1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
2. E is the number of edges present in graph G.*/
#include <iostream>
#include <queue>
using namespace std;

bool bfs(vector<vector<int>> &edges, int sv, int ev)
{
    int n = edges.size();
    vector<bool> visited(n, false);
    queue<int> pendingVertex;
    pendingVertex.push(sv);
    visited[sv] = true;

    while (!pendingVertex.empty())
    {
        int node = pendingVertex.front();
        pendingVertex.pop();

        if (node == ev)
            return true;

        for (int neighbour = 0; neighbour < n; neighbour++)
        {
            if (edges[node][neighbour] == 1 && !visited[neighbour])
            {
                pendingVertex.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }
    return false;
}

bool hasPath(vector<vector<int>> &edges, int sv, int ev)
{
    cout << (bfs(edges, sv, ev) ? "true" : "false") << endl;
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> edges(n, vector<int>(n, 0));

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    int v1, v2;
    cin >> v1 >> v2;

    hasPath(edges, v1, v2);
}