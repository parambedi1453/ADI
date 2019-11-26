// given an undirected graph we need to check that there is cycle or not


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

        void checkCycle(T src)
        {
            map<T,T> parent;
            map<T,bool> visisted;
            queue<T> q;

            q.push(src);
            visisted[src] = true;
            parent[src]=src;

            while(!q.empty())
            {
                T node = q.front();
                q.pop();

                for(T v : adjlist[node])
                {
                    if(!visisted[v])
                    {
                        visisted[v]=true;
                        parent[v]=node;
                        q.push(v);
                    }
                    else
                    {
                        // skipping the parent array
                        if(v!=parent[node])
                        {
                            cout<<"Cycle detected"<<endl;
                            return ;
                        }
                    }
     
                }
            }
            cout<<"No cycle found"<<endl;
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


    // No cycle foundd
    //  g.addEdge(0,1);
    // g.addEdge(1,2);
    // g.addEdge(0,4);
    
    g.checkCycle(0);
    cout<<endl;
}

// list are iterated using iterators