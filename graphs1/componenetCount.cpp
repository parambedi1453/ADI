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

        void dfsHelper(T node,map<T,bool> &visited)
        {
            visited[node] = true;
            cout<<node<<"->";

            for(int i=0;i<adjlist[node].size();i++)
            {
                if(!visited[adjlist[node][i]])
                {
                    dfsHelper(adjlist[node][i],visited);
                }
            }
        }
        void dfs(T src)
        {
            map<T,bool> visited;

            int component = 1;
            dfsHelper(src,visited); 

            cout<<endl;
            for(auto i : adjlist)
            {
                if(!visited[i.first])
                {
                    component++;
                    dfsHelper(i.first,visited);
                    cout<<endl;
                }
            }
           
            cout<<"Total number of componenets are "<<component<<endl;
        }

};
int main()
{
   Graph<string> g;

   g.addEdge("amritsar","jaipur");
   g.addEdge("amritsar","delhi");
   g.addEdge("delhi","jaipur");
   g.addEdge("mumbai","jaipur");
   g.addEdge("delhi","bhopal");
   g.addEdge("mumbai","banglore");
   g.addEdge("agra","delhi");
   g.addEdge("andaman","nicobar");//2 componenets
//    g.addEdge("llll","hhhhh"); 3 components

   g.dfs("amritsar");
   
}

// list are iterated using iterators