#include<iostream>
using namespace std;
int mem[1000];
int fib(int n)
{
    if(n==0||n==1)
    return n;
    
    if(mem[n]!=-1)
    return mem[n];

    int ans = fib(n-1)+fib(n-2);
    mem[n]=ans;
    return mem[n];
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<1000;i++)
    mem[i]=-1;
    int ans = fib(n);
    cout<<ans<<endl;
    return 0;
}