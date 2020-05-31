#include<iostream>
#include<vector>
using namespace std;

void addDirectedEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

void directed(vector<int> adj[], int u, int v)
{
    addDirectedEdge(adj, u, v);
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

bool findNeighbours(vector<int>adj[], int i, int dest)
{
    bool returnFlag = false;
    for(int z=0; z<adj[i].size(); z++)
    {
        if(adj[i][z]==dest)
        {
            returnFlag = true;
            break;
        }
    }

    return returnFlag;
}

bool findRoute(int V, vector<int>adj[], int source, int dest)
{
    static bool found = false;
    static vector<int>path;
    static int d = dest;
    if(adj[source].size()==0)
    {
        return found;
    }
    else
    {
        for(int i=0; i<V; i++)
        {
            bool searchNeighbour= findNeighbours(adj, i, dest);
            if(searchNeighbour== true)
            {
                if(i != source&& i != d)
                {
                        path.push_back(i);
                        findRoute(V, adj, source, i);

                }
                else if(i==d)
                {
                    found = false;
                    return found;
                }
                else
                {
                    found = true;
                    return found;
                }
            }
        }
    }
    return found;
}

int main()
{
    int V =6;
    vector<int> adj[V];

    directed(adj, 0,1);
    directed(adj, 1,4);
    directed(adj, 4,5);
    directed(adj, 1,3);
    directed(adj, 1,2);
    directed(adj, 4,3);
    directed(adj, 3,2);
    directed(adj, 5,0);
    //displayNeighbours(adj,V);

    //function
    bool answer= findRoute(V, adj, 0,3);
    cout<<"\nanswer: "<<answer<<endl;
}
