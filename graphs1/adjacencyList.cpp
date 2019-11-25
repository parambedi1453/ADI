#include<iostream>
#include<list>
using namespace std;
class Graph
{
    private:
    int V;
    list<int> *l;

    public:
    Graph(int v)
    {
        V =v;
        l = new list<int>[V];
    }
    void addEdge(int u,int v,bool bdir=true)
    {
        l[u].push_back(v);
        if(bdir)
        l[v].push_back(u);
    }

    void print()
    {
        for(int i=0;i<V;i++)
        {
            // l[i] is the link list

            cout<<i<<"->>";
            list<int> &p = l[i];
            list<int>::iterator it ;
            for(it=p.begin();it!=p.end();it++)
            {
                cout<<*it<<"->";
            }

            cout<<endl;
         }
    }
};
int main()
{
    // graph has 5 vertices numbered from 0 to 4
     Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(4,3);
    g.addEdge(1,4);
    g.addEdge(1,3);
    g.addEdge(1,2);
    g.addEdge(2,3);

    g.print();

}