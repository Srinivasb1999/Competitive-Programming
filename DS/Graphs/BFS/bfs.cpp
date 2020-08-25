#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *adj;

    public:
    Graph(int V){
        this->V = V;
        adj = new list<int>[V];
    };

    void add_edge(int u, int v){
        adj[u].push_back(v);
    }

    void BFS(int s){
        bool *visited = new bool[V];
        for(int i = 0; i < V; i++)
            visited[i] = false;
        
        list<int> queue;

        visited[s] = true;
        queue.push_back(s);

        while(!queue.empty()){
            s = queue.front();
            cout<<s<<" ";
            queue.pop_front();

            for(auto i : adj[s]){
                if(!visited[i]){
                    visited[i] = true;
                    queue.push_back(i);
                }
            }
        }

    }

    void DFSHelper(int s, bool visited[]){
        visited[s] = true;
        cout << s << " ";
        
        for(auto i: adj[s]){
            if(!visited[i]){
                DFSHelper(i, visited);
            }
        }
    }

    void DFS(int s){
        bool *visited = new bool[V];
        for(int v = 0; v < V; ++v){
            visited[v] = false;
        }

        DFSHelper(s, visited);
    }

};

int main(){
    Graph g(8);
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(2, 4);
    g.add_edge(4, 5);
    g.add_edge(4, 6);
    g.add_edge(4, 7);
    g.add_edge(1, 7);
    cout<<"BFS : ";
    g.BFS(0);
    cout<<"\nDFS : ";
    g.DFS(0);
    return 0;
}