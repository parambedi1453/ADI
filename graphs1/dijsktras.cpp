#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

template<typename T>
class Graph
{
    unordered_map<T,list<pair<T,int>> > m;

    public:
    void addEdge(T u,T v,int dist,bool bdir = true)
    {
        m[u].push_back(make_pair(v,dist));
        if(bdir)
        {
            m[v].push_back(make_pair(u,dist));
        }
    }

    void printAdj()
    {
        for(auto i : m)
        {
            cout<<i.first<<"->";
            for(auto neighbour : i.second)
            {
                cout<<"("<<neighbour.first<<","<<neighbour.second<<")";
            }
            cout<<endl;
        }
    }

    void djk(T src)
    {
        // distance map
        unordered_map<T,int> dist;

        for(auto i : m)
        {
            dist[i.first] = INT_MAX;
        }

        // make a set to find node with min distancr
        set<pair<int,T> > s;

        dist[src] = 0;
        s.insert(make_pair(0,src));

        while(!s.empty())
        {
            // find pair at thr front
            auto p = *(s.begin());
            T node = p.second;

            int nodeDist = p.first;
            s.erase(s.begin());

            // iterate over the neighbors of the current node
            for(auto childPair : m[node])
            {
                if(nodeDist+childPair.second < dist[childPair.first])
                {
                    // in set updation is not possible so we have to 
                    // remove the old pair and insert new pair
                    T dest = childPair.first;
                    auto f = s.find(make_pair(dist[dest],dest));
                    if(f!=s.end())
                    {
                        s.erase(f);
                    }

                    dist[dest] = nodeDist+childPair.second;
                    s.insert(make_pair(dist[dest],dest));
                }
            }
        }

        for(auto d : dist)
        {
            cout<<d.first<<" is located at a distance of "<<d.second<<endl;
        }

    }


};
int main()
{
    Graph<int> g;
    g.addEdge(1,2,1);
    g.addEdge(1,3,4);
    g.addEdge(2,3,1);
    g.addEdge(3,4,2);
    g.addEdge(1,4,7);

    // g.printAdj();
    g.djk(1);

}