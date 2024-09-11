#include <iostream>
#include <queue>
using namespace std;

// dfs main logic ---connected graph code
void printDFS(int **edges, int n, int sv, bool *visited)
{
    cout << sv << endl;
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[sv][i] == 1)
        {
            if (visited[i])
            {
                continue;
            }
            printDFS(edges, n, i, visited);
        }
    }
}

// making applicable for disconnected too....
void DFS_disconnected(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printDFS(edges, n, i, visited);
        }
    }
    delete[] visited;
}

// bfs main logic ---connected graph code
void printBFS(int **edges,int n,int sv, bool *visited)
{
    queue<int> q; // queue will be storing the pending vertices
    q.push(sv);
    visited[sv] = true;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        cout << curr << endl;

        for (int i = 0; i < n; i++)
        {
            if (i == curr)
                continue;
            if(edges[curr][i] == 1 && !visited[i]){
                q.push(i);
                visited[i]= true;
            }
        }
    }
}

// making applicable for disconnected graphs
void BFS_disconnected(int **edges, int n)
{
    //just maintaining the common visited array - for all the partitions of dis. graphs
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printDFS(edges, n, i, visited);
        }
    }
    delete[] visited;
}
int main()
{
    int n, e;
    cin >> n >> e;
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
    cout << "DFS" << endl;
    DFS_disconnected(edges, n);

    cout << "BFS" << endl;
    BFS_disconnected(edges, n);

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
}
/*
6 4
0 1
0 2
3 4
4 5
output :

            DFS
            0
            1
            2
            3
            4
            5


Component 1:            Component 2:

    0                     3
   / \                   / \
  1   2                 4   5
*/