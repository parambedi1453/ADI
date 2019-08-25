/*
    given numbers numbers exist 3 times except the one number find that number

    for eg 
     7 7 3 4 2 4 3 3 4 7
     ans is 2

 */

#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];

    int bit[32]={0};

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<32;j++)
        {
            if((1<<j)&a[i])
            {
                bit[j]+=1;
            }
        }
    }
    for(int i=0;i<32;i++)
    {
        bit[i]=bit[i]%3;//or any number whose occurence is alll the numbers other than the one existing
    }
    for(int i=0;i<32;i++)
    cout<<bit[i]<<" ";
    cout<<endl;
    int ans=0,t=1;
    for(int i=0;i<32;i++)
    {
        ans = ans+bit[i]*t;
        t=t*2;
    }
     cout<<ans<<endl;

}