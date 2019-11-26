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

        void dfsHelper(T node,map<T,bool> &visited,list<T> &ans)
        {
            visited[node] = true;

            // will call dfs for unvisited neighbors of the current node
            // for each loop

            for(T neighbour : adjlist[node])
            {
                if(!visited[neighbour])
                {
                    dfsHelper(neighbour,visited,ans);
                }
            }
            // now all the children of current node have been visited
            // we can add current node to the list
            ans.push_front(node);
        }
        void topologicalSort()
        {
            map<T,bool> visited;
            list<T> ans;

            for(auto i : adjlist)
            {
                T node = i.first;
                if(!visited[node])
                {
                    dfsHelper(node,visited,ans);
                }
            }
            // prit the ordering

            for(T element : ans)
            {
                cout<<element<<"->";
            }
            cout<<endl;
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