#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//To find and print all the connected components of an undirected graph, 
//you can use either BFS or DFS. The idea is to perform a traversal (BFS or DFS) 
//from each unvisited vertex, marking all reachable vertices as part of the same component.
// BFS function to find all vertices in the same component


void bfs(int **edges, int n, int startVertex, vector<bool>& visited, vector<int>& component) {
    queue<int> pendingVertices;
    pendingVertices.push(startVertex);
    visited[startVertex] = true;

    while (!pendingVertices.empty()) {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        component.push_back(currentVertex);

        for (int i = 0; i < n; i++) {
            if (edges[currentVertex][i] == 1 && !visited[i]) {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
}


void dfs(int **edges,int n,int currentVertex,vector<bool>&visited,vector<int>&component)
{
    visited[currentVertex]=true;
    component.push_back(currentVertex);
    for(int i =0;i<n;i++){
        if(edges[currentVertex][i] ==1 && !visited[i]){
            dfs(edges, n, i, visited, component);
        }
    }
}
// Function to find all connected components
vector<vector<int>> connectedComp(int**edges,int n){
    vector<bool>visited(n,false);
    vector<vector<int>>components;

    for(int i =0; i< n;i++){
        if(!visited[i]){
            vector<int>component;
            dfs(edges,n,i,visited,component);
            sort(component.begin(),component.end());
            components.push_back(component);
        }
    }
    return  components;
}

int main() {
    int n, e;
    cin >> n >> e;

    // adjacency matrix
    int **edges = new int *[n];
    for (int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++) {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++) {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    vector<vector<int>> result = connectedComp(edges, n);
    // Print all components
    for(const auto &component : result){
        for(int vertices : component){
            cout <<vertices <<" ";
        }
        cout<<endl;   
    }

    for (int i = 0; i < n; i++) {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}
