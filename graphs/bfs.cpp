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
    void bfs(T src)
    {
        queue<T> q;
        map<T,bool> m;//visited hash

        q.push(src);
        m[src] = true;

        while(!q.empty())
        {
            T node = q.front();
            cout<<node<<"->";
            q.pop();
            for(auto child : adjlist[node])
            {
                if(!m[child])
                {
                    q.push(child);
                    m[child]=true;
                }
            }
        }
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
    
    g.bfs(0);
}