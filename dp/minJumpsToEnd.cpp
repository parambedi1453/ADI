#include <iostream>
#include<climits>
using namespace std;
int minJump(int a[],int n)
{
    int b[n];
    int min;
    b[n-1] = 0;
    for(int i=n-2;i>=0;i--)
    {
        if(a[i]==0)
        b[i]=INT_MAX;
        
        else if(a[i]>=n-i-1)
        b[i]=1;
        
        else
        {
            min = INT_MAX;
            for(int j=i+1;j<=i+a[i];j++)
            {
                if(b[j]<min)
                min=b[j];
            }
            if(min!=INT_MAX)
            b[i]=min+1;
            else
            b[i]=min;
            // check case 2 1 0 3imp
        }
       
    }
    
    
    return b[0];
}
int main() {
	//code
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    int ans;
	   
	    ans = minJump(a,n);
	    if(ans==INT_MAX)
	    ans=-1;
	    
	    cout<<ans<<endl;
	}
	return 0;
}