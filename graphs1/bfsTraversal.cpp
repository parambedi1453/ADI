#include<iostream>
#include<map>
#include<list>
#include<vector>
#include<queue>
using namespace std;

template<typename T>
class Graph
{
    map<T,vector<T> > adjlist;

    public:
        void addEdge(T u,T v, bool bdir=true)
        {
            adjlist[u].push_back(v);
            if(bdir){
                adjlist[v].push_back(u);
            }
        }
        void print()
        {
            typename map<T,vector<T>>::iterator itr;
            for(itr=adjlist.begin();itr!=adjlist.end();itr++)
            {
                cout<<itr->first<<"-->";
                for(int i=0;i<itr->second.size();i++)
                {
                    cout<<itr->second[i]<<"->";
                }
                cout<<endl;
            }
        }

        void bfs(T src)
        {
            map<T,bool> m;
            queue<T> q;

            q.push(src);
            m[src]=true;

            while(!q.empty())
            {
                T node = q.front();
                q.pop();
                cout<<node<<"->";
                for(int i=0;i<adjlist[node].size();i++)
                {
                    if(!m[adjlist[node][i]])
                    {
                        q.push(adjlist[node][i]);
                        m[adjlist[node][i]]=true;
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
    cout<<endl;
}

// list are iterated using iterators