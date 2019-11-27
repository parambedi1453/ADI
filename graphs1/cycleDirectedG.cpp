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

        bool iscyclehelper(T node,map<T,bool> &visited,map<T,bool> &instack)
        {
            visited[node] = true;
            instack[node] =true;

            for(T neighbour : adjlist[node])
            {
                // if((!visited[neighbour]&&iscyclehelper(neighbour,visited,instack))||instack[neighbour])
                // {
                //     return true;
                // }
                if(!visited[neighbour])
                {
                    if(iscyclehelper(neighbour,visited,instack))
                    return true;
                }
                else if(instack[neighbour]==true)
                return true;                
            }
            instack[node]=false;
            return false;
        }
        bool iscycle()
        {
            map<T,bool> visited;
            map<T,bool> instack;

            for(auto i : adjlist)
            {
                T node = i.first;
                if(!visited[node])
                {
                    bool cyclePresent = iscyclehelper(node,visited,instack);
                    if(cyclePresent)
                    return true;
                }
            }
            return false;
        }
       

};
int main()
{
   Graph<int> g;
   
    g.addEdge(0,2,false);
    g.addEdge(0,1,false);
    g.addEdge(2,3,false);
    g.addEdge(3,0,false);
     g.addEdge(2,4,false);
     g.addEdge(4,5,false);
      g.addEdge(1,5,false);

   
   if(g.iscycle())
   cout<<"Cycle is found"<<endl;
   else
   cout<<"cycle is not found"<<endl;
}

// list are iterated using iterators