#include <iostream>
#include<climits>
using namespace std;
int cntCoins(int a[],int n,int coins)
{
    int row = n+1;
    int col = coins+1;
    
    int k[row][col];
    k[0][0]=0;
    
    for(int i=1;i<col;i++)
    k[0][i]=INT8_MAX;
    for(int j=1;j<row;j++)
    k[j][0]=0;
    
    for(int i=1;i<row;i++)
    {
        for(int j=1;j<col;j++)
        {
            if(j<a[i-1])
            k[i][j] = k[i-1][j];
            else
            k[i][j] = min(1+k[i][j-a[i-1]] , k[i-1][j]);
        }
    }

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<k[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return k[row-1][col-1];
}
int main() {
	//code
	int t,n,coins;
    // Eneter Test Case
	cin>>t;
	while(t--)
	{
        // Enter size of array
	    cin>>n;
	    int a[n];
        // Enter Array
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    
        // Enter coins;
	    cin>>coins;
	    
	    int ans  = cntCoins(a,n,coins);
	    
	    cout<<ans<<endl;
	}
	return 0;
}