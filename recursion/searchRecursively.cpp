#include<iostream>
using namespace std;
int findPos(int *a,int i,int n,int k)
{
    if(i>=n)
    return -1;
    if(a[i]==k)
    return i;
    int ans = findPos(a,i+1,n,k);
    return ans;
}
int main()
{
    int n,key;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    cin>>key;
    int  k = findPos(a,0,n,key);
    cout<<k;
}