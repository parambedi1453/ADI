//matrix chain multiplictaion using memoisation 

#include<iostream>
using namespace std;

int dp[100][100];
int getMinOperations(int a[],int i,int j)
{
    if(i==j)
    {
        dp[i][j]=0;
        return 0;
    }

    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int ans = INT8_MAX;
    for(int k=i;k<j;k++)
    {
        int temp = getMinOperations(a,i,k)+getMinOperations(a,k+1,j) + a[i-1]*a[k]*a[j];
        ans = min(ans,temp);
    }
    dp[i][j]=ans;
    return ans;
}
int main()
{
    int a[]= {1,2,3,4};

    int n = sizeof(a)/sizeof(int);
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            dp[i][j]=-1;
        }
    }
    int ans = getMinOperations(a,1,n-1);
    cout<<ans<<endl;
}