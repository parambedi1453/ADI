#include<iostream>
#include<list>
#include<map>
#include<queue>
using namespace std;

template<typename T>
class Graph
{
    map<T,list<T > > adjlist;

    public :

    void addEdge(T u,T v,bool bdir=true)
    {
        adjlist[u].push_back(v);
        if(bdir)
        adjlist[v].push_back(u);
    }

    void print()
    {
        for(auto i : adjlist)
        {
            cout<<i.first;
            for(auto j :i.second)
            cout<<"->"<<j;

            cout<<endl;
        }
    }

    void dfsHelper(T node,map<T,bool> &m)
    {
        m[node]=true;
        cout<<node<<"->";

        for(T neighbour : adjlist[node])
        {
            if(!m[neighbour])
            {
                dfsHelper(neighbour,m);
            }
        }
    }
    void dfs(T src)
    {
        map<T,bool> m;//for checking the visite node
        dfsHelper(src,m);
    }
  
};
int main()
{
    Graph<int> g;
   
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,4);
    g.addEdge(2,4);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(3,4);
    
    g.dfs(0);
}