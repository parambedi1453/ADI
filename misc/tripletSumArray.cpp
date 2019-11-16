#include <iostream>
#include<algorithm>
using namespace std;
int checkThreeSum(int a[],int n,int target)
{
        int sum;
        sort(a,a+n);
	    for(int i=0;i<n-2;i++)
	    {
	        sum=target-a[i];
	        int j = i+1;
	        int k = n-1;
	        while(j<k)
	        {
	            if(a[j]+a[k]==sum)
	            return 1;
	            else if(a[j]+a[k]<sum)
	            j=j+1;
	            else
	            k=k-1;
	        }
	    }
	    return 0;
}
int main() {
	
	int t,n,target;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    cin>>target;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    
	    cout<<checkThreeSum(a,n,target)<<endl;
	    
	}
	return 0;
}