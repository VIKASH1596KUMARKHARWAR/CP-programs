#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{

private:

void dfs(int node , vector<vector<int>> &adjMatrix,vector<bool>&visited,vector<int> &ls){
    stack<int> s;
    s.push(node);

    while (!s.empty())
    {
        int curr = s.top();
        s.pop();
        if(visited[curr]) continue;
        visited[curr] = true;
        ls.push_back(curr);

        for(int i = 0; i<adjMatrix.size(); i++){
            if(adjMatrix[curr][i]==1  && !visited[i]){
                s.push(i);
            }
        }

    }
    
}
public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<vector<int>> &adjMatrix)
    {
        vector<bool> visited(V, false);
        vector<int> ls;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, adjMatrix, visited, ls);
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
    vector<int> ans = obj.dfsOfGraph(V, adjMatrix);
    printAns(ans);

    return 0;
}