#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// void print_query(priority_queue<int,vector<int>,greater<int> q)
// {
//     cout<<q.top()
// }
int main()
{
    priority_queue<int,vector<int>,greater<int> > p;

    int a[]={1,2,3,4,-1,5,9,10,-1,12,15,8,6,-1};

    int k =3;
    int cs=0;
    for(int i=0;i<14;i++)
    {
        if(a[i]==-1)
        {
        //    print_query( p);
        cout<<p.top()<<" ";
        }
        else if(cs<k)
        {
            p.push(a[i]);
            cs++;
        }
        else
        {
            if(a[i]>p.top())
            {
                p.pop();
                p.push(a[i]);
            }
        }
        
    }
}