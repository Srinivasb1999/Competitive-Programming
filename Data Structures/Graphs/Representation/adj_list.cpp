#include <bits/stdc++.h>
using namespace std;

void add_edge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void print_graph(vector<int> adj[], int V){
    for(int v = 0; v < V; ++v){
        cout<<"Adjacency List for Vertex "<<v<<"\nhead";
        for(auto i: adj[v])
        cout<<" -> "<<i;
        cout<<"\n";
    }
}

int main(){
    int V = 5;
    vector<int> adj[V];
    add_edge(adj, 0, 1);
    add_edge(adj, 0, 2);
    add_edge(adj, 0, 4);
    add_edge(adj, 1, 2);
    add_edge(adj, 2, 4);
    add_edge(adj, 2, 3);
    add_edge(adj, 3, 4);

    print_graph(adj, V);
    return 0;
}