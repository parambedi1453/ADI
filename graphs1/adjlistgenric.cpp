#include<iostream>
#include<map>
#include<list>
#include<vector>
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


};
int main()
{
    Graph<string> g;
    g.addEdge("delhi","haryana",false);
    g.addEdge("delhi","chd",false);
    g.addEdge("delhi","mumbai",false);
    g.addEdge("chd","haryana",true);
    g.addEdge("mohali","chd",false);
    g.addEdge("panchkula","chd",false);
    g.addEdge("mohali","panchkula",false);

    g.print();
}