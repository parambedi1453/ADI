#include<iostream>
using namespace std;
int bsearch(int a[],int n,int x)
{

    int l=0,r=n-1,mid;
    while(l<=r)
    {
        mid = (l+r)/2;

        if(a[mid]==x)
        return mid;
        //considering left part is sorted 
        else if(a[l]<=a[mid])
        {
            // checking if x lies in the left part or not
            if(x>=a[l]&&x<a[mid])
            r = mid-1;
            else
            l=mid+1;
        }
        else if(a[r]>=a[mid])
        {
            if(x>a[mid] && x<=a[r])
            l = mid+1;
            else
            r = mid-1;
        }
    }
    //if element no found
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