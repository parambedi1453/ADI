/*
    Basics of this problem is the array is circulary sorted that means that half partbof array is always sorted
     ques can be how many times array is sorted 
     // Naive approch find the mininmum and the index of mininmum element would be the pivot


     eg
     11 12 15 18 2 5 6 8

     2 is minimum and the pivot elelmet


 */


#include<iostream>
using namespace std;
int pivot(int a[],int n)
{
    int l=0,r=n-1,mid,next,prev;
    while(l<=r)
    {
        if(a[l]<=a[r])//means array is already sorted
        return l;
        mid = (l+r)/2;
        next = (mid+1)%n;
        prev = (mid+n-1)%n;

        if(a[mid]<=a[next] && a[mid]<=a[prev])
        return mid;
        else if(a[mid]<=a[r])//means that part is sorted
        r = mid-1;
        else if(a[mid]>=a[l])//means this part is sorted
        l = mid+1;
    }
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
    int ans  = pivot(a,n);
   cout<<"pivot is at "<<ans<<endl;
}