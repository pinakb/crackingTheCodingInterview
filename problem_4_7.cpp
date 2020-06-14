//

#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<algorithm>
using namespace std;

class build{
public:
        vector<bool> dependency;
        void getListOfProjects();
        void processDependencies(string listOfProjects, string input);
        void displayNeighbours(vector<char>adj[], int u);

private:
    void addDirectedEdge(vector<char> adj[], char u, char v);
    void directed(vector<char> adj[], char u, char v);
    int processProjects(string listOfProjects);
    void traceNode(vector<char> adj[], int V, char node,vector<char> *independent);
    void getOutput(vector<char> adj[], int V);


};

void build::displayNeighbours(vector<char>adj[], int u)
{
    for(int z=0; z<u; z++)
    {
        char c = z+'a';
        cout<<"neighbours of vertex: "<<c<<endl;
        for(int i=0; i<adj[z].size(); i++)
        {
            cout<<adj[z][i]<<"\t";
        }
        cout<<"\n";
    }

}

void build::addDirectedEdge(vector<char> adj[], char u, char v)
{
    adj[u-'a'].push_back(v);
}

void build::directed(vector<char> adj[], char u, char v)
{
    addDirectedEdge(adj, u, v);
}

int build::processProjects(string listOfProjects)
{
    string len="";
    string token;
    stringstream ss(listOfProjects);

    while(getline(ss,token,','))
    {
        len+=token;
    }
    return len.length();
}

void build::traceNode(vector<char> adj[], int V, char node, vector<char> *independent)
{
    bool flag = true;
    for(int z=0; z< V; z++)
    {
        for(int i=0; i<adj[z].size(); i++)
        {
            if(adj[z][i] == node)
            {
                flag = false;
            }
        }
    }
    if(flag == true)
    {
        independent->push_back(node);
    }
}
void build::getOutput(vector<char> adj[] , int V)
{
    vector<char> independent;
    vector<char> output;
    for(int i=0; i<V; i++)
    {
        char node = i + 'a';
        traceNode(adj, V, node, &independent);
    }

    //log

//    for(int x=0; x< independent.size(); x++)
//    {
//        cout<<x<<" independent: "<<independent[x]<<endl;
//    }

    //end log

    //visit dependent nodes to make them independent
    if(independent.empty())
    {
        cout<<"No valid dependency order"<<endl;
    }
    else
    {
        while(!independent.empty())
        {
            char node = *independent.begin();
            output.push_back(node);
            independent.erase(independent.begin());

            if(adj[node-'a'].size() ==0)
            {
                continue;
            }
            else
            {
                for(int i=0; i< adj[node-'a'].size(); i++)
                {
                    vector<char>::iterator itr;
                    itr = std::find(independent.begin(), independent.end(), adj[node-'a'][i]);
                    if(itr == independent.end())
                    {
                        independent.push_back(adj[node-'a'][i]);
                    }
                }
            }
        }

        cout<<"\noutput: ";
        vector<char>::iterator itr;
        for(itr= output.begin(); itr!=output.end(); ++itr)
        {
            cout<<*itr<<" ";
        }
        cout<<"\n";
    }//end of else
}

void build::processDependencies(string listOfProjects, string input)
{
    int V = processProjects(listOfProjects);
    vector<char> adj[V];
    stringstream ss(input);
    string token;
    size_t pos=-1;
    vector<char>pairProj;
    pairProj.clear();
    int counter=0;
    while(ss>>token)
    {
        while((pos= token.rfind('('))!= string::npos)
        {
            token.erase(pos,1);
        }
        while((pos= token.rfind(','))!= string::npos)
        {
            token.erase(pos,1);
        }
        while((pos= token.rfind(')'))!= string::npos)
        {
            token.erase(pos,1);
        }

        if(pairProj.size()==0)
        {
            char c[token.size()];
            copy(token.begin(), token.end(),c);
            pairProj.push_back(c[0]);
        }
        else if(pairProj.size()==1)
        {
            char c[token.size()];
            copy(token.begin(), token.end(),c);
            pairProj.push_back(c[0]);
            directed(adj, pairProj[0], pairProj[1]);
            pairProj.clear();
        }
    }
    cout<<"Dependency Graph: "<<endl;
    displayNeighbours(adj,V);
    getOutput(adj,V);
}

int main()
{
    build ob;
    string listOfProjects= "a,b,c,d,e,f";
    string input = "(a, d), (f, b), (b, d), (f, a), (d, c)";
    cout<<"List of Projects: "<<listOfProjects<<endl;
    cout<<"Dependencies: "<<input<<endl;
    ob.processDependencies(listOfProjects, input);
}
