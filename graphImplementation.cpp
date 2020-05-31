#include<iostream>
#include<vector>
using namespace std;

void addUndirectedEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void addDirectedEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

void displayNeighbours(vector<int>adj[], int u)
{
    for(int z=0; z<u; z++)
    {
        cout<<"neighbours of vertex: "<<z<<endl;
        for(int i=0; i<adj[z].size(); i++)
        {
            cout<<adj[z][i]<<"\t";
        }
        cout<<"\n";
    }

}

void directed(vector<int> adj[], int u, int v)
{
    addDirectedEdge(adj, u, v);
}

void undirected(vector<int> adj[], int u, int v)
{
    addUndirectedEdge(adj, u, v);
}

int main()
{
    int V =6;
    vector<int> adj[V];

    undirected(adj, 0,1);
    undirected(adj, 0,4);
    undirected(adj, 0,5);
    undirected(adj, 1,4);
    undirected(adj, 1,2);
    undirected(adj, 1,3);
    undirected(adj, 2,3);
    undirected(adj, 3,4);
    undirected(adj, 4,5);
    displayNeighbours(adj,V);
}
