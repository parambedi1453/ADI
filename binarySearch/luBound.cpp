// First occurence is lower bound

#include<iostream>
using namespace std;
int lbound(int a[],int n,int key)
{
    int l=0,r=n-1,mid,ans=-1;
    while(l<=r)
    {
        mid = (l+r)/2;
        if(a[mid]==key)
        {
            // slight change from binary search (r=mid-1) because we have to find in the left part and need to find the left occurence
            ans = mid;
            r = mid-1;
        }
        else if(a[mid]>key)
        r = mid-1;
        else
        l = mid+1;
    }
    return ans;
}
// last occurence of element
int ubound(int a[],int n,int key)
{
    int l=0,r=n-1,mid,ans=-1;
    while(l<=r)
    {
        mid = (l+r)/2;
        if(a[mid]==key)
        {
            ans = mid;
            l = mid+1;
        }
        else if(a[mid]>key)
        r = mid-1;
        else
        l = mid+1;
    }
    return ans;
}
int main()
{
    int n ;
    cout<<"Enter no of elements = \n";
    cin>>n;
    int a[n];
    cout<<"Enter Elements = \n";
    for(int i=0;i<n;i++)
    cin>>a[i];
    int key;
    cout<<"Enter Element for lower bound =\n";
    cin>>key;
    int ans  = lbound(a,n,key);
    if(ans == -1)
    cout<<key<<" is Not present\n";
    else
    cout<<key<<" 's first occurence is at "<<ans<<endl;
}