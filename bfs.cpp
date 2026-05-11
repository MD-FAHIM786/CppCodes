#include<bits/stdc++.h>
using namespace std;

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    vector<int> graph[vertices];

    cout << "Enter the edges: ";
    cin >> edges;
    for (int i = 0; i < edges; i++) {
        int src, dest;
        cout << src << " -> " << dest << ": ";
        cin >> src >> dest;
        graph[src].push_back(dest);
        graph[dest].push_back(src);
    }

    vector<int> visited(vertices, 0);

    int start;
    cout << "Enter the starting vertex: ";
    cin >> start;

    visited[start] = 1;
    queue<int> q;
    q.push(start);

    cout << "BFS Traversal:\n";
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " " << endl;

        for (int i = 0; i < graph[current].size(); i++) {
            int neighbor = graph[current][i];
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }

    return 0;
}
