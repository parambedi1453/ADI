#include<iostream>
using namespace std;
int getMinOperations(int a[],int i,int j)
{
    if(i==j)
    return 0;

    int ans = INT8_MAX;
    for(int k=i;k<j;k++)
    {
        int temp = getMinOperations(a,i,k)+getMinOperations(a,k+1,j) + a[i-1]*a[k]*a[j];
        ans = min(ans,temp);
    }
    return ans;
}
int main()
{
    int a[]= {1,2,3,4};

    int n = 4;

    int ans = getMinOperations(a,1,n-1);
    cout<<ans<<endl;
}