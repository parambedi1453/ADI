/*
    given a n step staicase find the total no of ways to reach the top
    with the maximum jumps of  1 2 3
*/

#include<iostream>
#include<vector>
using namespace std;
int cnt = 0,fcall=0;
void func(int *a,int s,int e,int n,vector<int> &v)
{
    fcall++;
    if(n==0)
    {
        for(int j=0;j<v.size();j++)
        cout<<v[j]<<" ";
        cout<<endl;
        cnt++;
        return;
    }
    if(n<0)
    return ;

    for(int i=s;i<=e;i++)
    {
        v.push_back(a[i]);
        if(n-a[i]>=0)//reducing that calls in which n would become -ve and waste fucntion call
        func(a,s,e,n-a[i],v);

        v.pop_back();
    }
}
int main()
{
    int  n;//Enter no of steps;
    cin>>n;
    int a[3];
    a[0]=1;
    a[1]=2;
    a[2]=3;
    cnt=0;
    vector<int> v;
    func(a,0,2,n,v);
    cout<<cnt<<endl;//no of ways to reach the top
    cout<<fcall<<endl;//no  of functions calls
}