#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
// int main()
// {
//     priority_queue<int> p;
//     int a[10] = {5,6,17,18,9,11};

//     // Insert in priority queue
//     for(int i=0;i<6;i++)
//     p.push(a[i]);


//     // By Default it is a max headp
//     while(!p.empty())
//     {
//         cout<<p.top()<<" ";
//         p.pop();
//     }
// }


int main()
{
    priority_queue<int> p;
    int a[2] = {6,5};

    for(int i=0;i<2;i++)
    p.push(a[i]);

    int k;
    cin>>k;
    while(k--)
    {
        cout<<p.top()<<" ";
       int a = p.top();
       p.pop();
       p.push(floor(a/2));
    }
}