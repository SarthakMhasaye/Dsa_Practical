#include<iostream>
#include<stack>
using namespace std;

#define MAX 100
int adj[MAX][MAX];
bool visited[MAX];
int n;

// Recursive DFS
void dfs_recursive(int start) {
    visited[start] = true;
    cout << start << " ";
    
    for (int i = 0; i < n; i++) {
        if (adj[start][i] == 1 && !visited[i]) {
            dfs_recursive(i);
        }
    }
}

// Iterative DFS using stack
void dfs_iterative(int start) {
    stack<int> s;
    
    for (int i = 0; i < n; i++)
        visited[i] = false;
    
    s.push(start);
    visited[start] = true;
    
    while (!s.empty()) {
        int current = s.top();
        s.pop();
        cout << current << " ";
        
        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                s.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    int edges, u, v, start;
    
    cout << "Enter number of vertices: ";
    cin >> n;
    
    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    
    cout << "Enter number of edges: ";
    cin >> edges;
    
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;  // For undirected graph
    }
    
    cout << "Enter starting vertex: ";
    cin >> start;
    
    // Recursive DFS
    for (int i = 0; i < n; i++)
        visited[i] = false;
    cout << "DFS (Recursive): ";
    dfs_recursive(start);
    cout << "\n";
    
    // Iterative DFS
    cout << "DFS (Iterative): ";
    dfs_iterative(start);
    cout << "\n";
    
    return 0;
}
  