// searching algo for sorted arrays
// based on divide and conquer

#include<iostream>
using namespace std;
int bsearch(int a[],int n,int key)
{
    int l = 0,r=n-1,mid;
    while(l<=r)
    {
        mid = (l+r)/2;
        if(a[mid]==key)//element found
        return mid;
        /// key might be present in left half
        else if(a[mid]>key)
        r=mid-1;
        else
        l = mid+1;
    }
    return -1;
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
    cout<<"Enter Element to be searched =\n";
    cin>>key;
    int ans  = bsearch(a,n,key);
    if(ans == -1)
    cout<<key<<" is Not present\n";
    else
    cout<<key<<" is present at "<<ans<<endl;
}