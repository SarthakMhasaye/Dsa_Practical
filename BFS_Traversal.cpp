#include <iostream>
#include <queue>
using namespace std;
#define MAX 100
int adj[MAX][MAX];
bool visited[MAX];
int n;
void BFS(int start) {
    queue<int> q;
    for (int i = 0; i < n; i++)
        visited[i] = false;
    q.push(start);
    visited[start] = true;
    cout << "BFS Traversal: ";
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";
        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
int main() {
    int edges, u, v, start;
    cout << "Enter number of vertices: ";
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    cout << "Enter number of edges: ";
    cin >> edges;
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    cout << "Enter starting vertex: ";
    cin >> start;
    BFS(start);

    return 0;
}