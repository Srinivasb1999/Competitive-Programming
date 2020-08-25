#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define deb(x) cout << #x << " " << x
#define mod 1000000007

struct Graph {
    int V;
    list<int>* adj;

    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    ~Graph() {
        delete[] adj;
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void connected_components() {
        bool* visited = new bool[V];
        fill(visited, visited + V, false);

        int count = 0;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                count++;
                dfs(i, visited);

                cout << endl;
            }
        }
        cout << "Total Connected Components:" << count;

        delete[] visited;
    }

    void dfs(int i, bool* visited) {
        visited[i] = true;
        cout << i << " ";
        for (auto v : adj[i]) {
            if (!visited[v]) {
                dfs(v, visited);
            }
        }
    }
};

int main() {
    Graph g(18);
    g.add_edge(0, 4);
    g.add_edge(0, 8);
    g.add_edge(0, 13);
    g.add_edge(0, 14);
    g.add_edge(8, 14);
    g.add_edge(3, 9);
    g.add_edge(9, 2);
    g.add_edge(9, 15);
    g.add_edge(15, 2);
    g.add_edge(15, 10);
    g.add_edge(12, 12);
    g.add_edge(6, 7);
    g.add_edge(6, 11);
    g.add_edge(7, 11);
    g.add_edge(1, 5);
    g.add_edge(5, 16);
    g.add_edge(5, 17);
    cout << "The Connected Components are: " << endl;
    g.connected_components();
    return 0;
}