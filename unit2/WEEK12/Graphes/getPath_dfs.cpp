#include <iostream>
#include <vector>
using namespace std;

// DFS function to find the path between two vertices - undirected graphs
vector<int> getPath(int **edges, int n, int sv, int ev, vector<bool> &visited)
{
    // If start vertex is the same as the end vertex, return the path with the start vertex
    if (sv == ev)
    {
        vector<int> path;
        path.push_back(sv);
        return path;
    }

    visited[sv] = true;

    // Explore all adjacent vertices of sv
    for (int i = 0; i < n; i++)
    {
        if (edges[sv][i] == 1 && !visited[i])
        {
            vector<int> path = getPath(edges, n, i, ev, visited);
            if (!path.empty())
            {                       // If path from i to ev exists
                path.push_back(sv); // Add current vertex to path
                return path;
            }
        }
    }
    return {}; // Return empty vector if no path is found
}

int main()
{
    int n, e;
    cin >> n >> e;

    // adjacency matrix
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    vector<bool> visited(n, false);

    int sv, ev;
    cin >> sv >> ev;

    vector<int> ans = getPath(edges, n, sv, ev, visited);

    if (!ans.empty())
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
    else
    {
        cout << "";
    }

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}
