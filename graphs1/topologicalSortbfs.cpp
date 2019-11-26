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
        void topologicalSort()
        {
           map<T,bool> visited;
           map<T,int> indegree;
           queue<T> q;

           for(auto i : adjlist)
           {
               T node = i.first;
               visited[node]=false;
               indegree[node]=0;
           }

            // finding the indegress;
           for(auto i : adjlist)
           {
               T u = i.first;
               for(T v : adjlist[u])
               {
                   indegree[v]++;
               }
           }
        //    finding all nodes with indegreee =0;
            for(auto i : adjlist)
            {
                T node = i.first;
                if(indegree[node]==0)
                q.push(node);
            }

            while(!q.empty())
            {
                T node = q.front();
                cout<<node<<"->";
                q.pop();

                // find all the neighbors and reduce the indegree
                for(T v : adjlist[node])
                {
                    indegree[v]--;
                    // pushing nodes in queue with indegree 0
                    if(indegree[v]==0)
                    q.push(v);   
                }
            }
        }

};
int main()
{
   Graph<string> g;

//    g.addEdge("e","p",false);
//    g.addEdge("m","p");
//    g.addEdge("p","h",false);
//    g.addEdge("p","py",false);
//    g.addEdge("p","js",false);
//    g.addEdge("p","java",false);
//    g.addEdge("py","wb",false);
//    g.addEdge("java","wb",false);
//    g.addEdge("h","c",false);
//    g.addEdge("js","wb",false);
//    g.addEdge("c","js",false);
//    g.topologicalSort();

    g.addEdge("a","c",false);
    g.addEdge("c","e",false);
    g.addEdge("e","f",false);
    g.addEdge("b","c",false);
    g.addEdge("b","d",false);
    g.addEdge("d","f",false);
    g.addEdge("f","g",false);

    g.topologicalSort();
}

// list are iterated using iterators