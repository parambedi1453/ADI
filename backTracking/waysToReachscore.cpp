#include<iostream>
using namespace std;

int dp[1000];
int  getCount(int a[],int s,int e,int sum)
{
    // base case
    // if(dp[sum]!=0)
    // return dp[sum];

    if(sum==0)
    {
        return 1;
    }
    else if(sum<0)
    return 0;


    // backtrack and recursive case
    int ans = 0;
    for(int i=s;i<e;i++)
    {
        
        sum = sum-a[i];
        ans+=getCount(a,i,e,sum);
        sum = sum+a[i];
    }
    dp[sum] = ans;
    return dp[sum];
}
int main()
{
    int a[] = {3,5,10};
    int n;
    cin>>n;
    for(int i=0;i<1000;i++)
    dp[i]=0;
    getCount(a,0,3,n);
    cout<<dp[n]<<endl; 
}