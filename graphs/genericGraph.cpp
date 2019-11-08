#include<iostream>
#include<list>
#include<map>
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


    // Graph<int> g1;


}