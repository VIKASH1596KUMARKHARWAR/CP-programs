#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS 
vector<int> getPathBFS(int **edges, int n, int sv, int ev) {
    queue<int> pendingVertices;
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);

    pendingVertices.push(sv);
    visited[sv] = true;

    bool pathFound = false;

    while (!pendingVertices.empty()) {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();

        for (int i = 0; i < n; i++) {
            if (!visited[i] && edges[currentVertex][i] == 1) {
                pendingVertices.push(i);
                visited[i] = true;
                parent[i] = currentVertex;

                if (i == ev) {
                    pathFound = true;
                    break;
                }
            }
        }

        if (pathFound) {
            break;
        }
    }

    if (!pathFound) {
        return {};
    }

    // Reconstruct the path from ev to sv using the parent vector
    vector<int> path;
    int current = ev;
    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }

    // The path is constructed from ev to sv, so we return it as is (reverse order)
    return path;
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

    int sv, ev;
    cin >> sv >> ev;

    vector<int> ans = getPathBFS(edges, n, sv, ev);

    if (!ans.empty()) {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
    } else {
        cout << "";
    }

    for (int i = 0; i < n; i++) {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}
