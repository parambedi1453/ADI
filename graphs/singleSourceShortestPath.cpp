#include<iostream>
#include<list>
#include<vector>
#include<map>
#include<queue>
using namespace std;

template<typename T>
class Graph
{
    map<T,vector<T> > adjlist;

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
        map<T,bool> m;

        q.push(src);
        m[src] = true;

        while(!q.empty())
        {
            T node = q.front();
            cout<<node<<"->";
            q.pop();
            for(auto child : adjlist[node] )
            {
                if(!m[child])
                {
                    q.push(child);
                    m[child]=true;
                }
            }
        }
    }
    
    void sssp(T src)
    {
        queue<T> q;
        map<T,int> m;
        map<T,T> parent;

        typename map<T,vector<T> >::iterator it;
        for(it=adjlist.begin();it!=adjlist.end();it++)
        {
            m[it->first]=INT8_MAX;
        }

        // with auto
        // for(auto i:adjlist)
        // {
        //     m[i.first]=INT8_MAX;
        // }
        
        q.push(src);
        m[src] = 0;
        // considering parent of src as src
        parent[src] = src;

        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            for(auto neighbour : adjlist[node])
            {
                if(m[neighbour]==INT8_MAX)
                {
                    q.push(neighbour);
                    m[neighbour] = m[node]+1;
                    parent[neighbour]=node;
                }
            }
        }

        for(auto i : adjlist)
        {
            T node = i.first;
            cout<<"Ditnace of node"<<node<<" from src is =" <<m[node]<<endl;
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
    

    cout<<"bfs Trversal of the graph \n";
    g.bfs(0);
    cout<<endl;

    g.sssp(0);

}