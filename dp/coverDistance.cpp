#include <iostream>
using namespace std;
int getWays(int n)
{
    int k[n+1];
    k[1]=1;
    k[2]=2;
    k[3]=4;
    for(int i=4;i<n+1;i++)
    {
        k[i]=k[i-1]+k[i-2]+k[i-3];
    }
    return k[n];
}
int main() {
	//code
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int ans = getWays(n);
	    cout<<ans<<endl;
	}
	return 0;
}