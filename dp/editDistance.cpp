#include <iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int getMinCost(string s1,string s2)
{
    int row = s2.size()+1;
    int col = s1.size()+1;
    
    int k[row][col];
    k[0][0]=0;
    for(int i=1;i<col;i++)
    k[0][i]=i;
    for(int j=1;j<row;j++)
    k[j][0]=j;
    
    for(int i=1;i<row;i++)
    {
        for(int j=1;j<col;j++)
        {
            if(s2[i-1]==s1[j-1])
            {
                k[i][j] = k[i-1][j-1];
            }
            else
            {
                int replace  = 1+k[i-1][j-1];
                int del = 1+k[i-1][j];
                int insert = 1+k[i][j-1];
                
                k[i][j]=min(replace,min(del,insert));
            }
        }
    }
    return k[row-1][col-1];
}
int main() {
	//code
	int t,l1,l2;
	cin>>t;
	while(t--)
	{
	    cin>>l1;
	    cin>>l2;
	    
	    string s1,s2;
	    cin>>s1;
	    cin>>s2;
	    
	    int ans = getMinCost(s1,s2);
	    cout<<ans<<endl;
	}
	return 0;
}