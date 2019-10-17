#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int,vector<int>,greater<int> > p;
    int a[10] = {5,6,17,18,9,11};

    // Insert in priority queue
    for(int i=0;i<6;i++)
    p.push(a[i]);


    // By Default it is a max headp
    while(!p.empty())
    {
        cout<<p.top()<<" ";
        p.pop();
    }
}