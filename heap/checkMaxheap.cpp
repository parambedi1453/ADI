/*
        in max heap parent is greater than both the left and right child

        if 1 based indexing is done then 
        left child = 2*i;
        right-child = 2*i+1;

        else 0 based indexing is done
        left-child = 2*i+1;
        right-child = 2*i+2;
 */

bool checkMaxHeap(int a[],int n)
{
    for(int i=0;i<=n/2;i++)
    {
        int lc = 2*i+1;
        int rc = 2*i+2;
        if(lc<n && a[i]<a[lc])
        return false;
        if(rc<n && a[i]<a[rc])
        return false;
    }
    return true;
}

#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter size of array =\n";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    bool k = checkMaxHeap(a,n);
    if(k)
    cout<<"Array is in max heap\n";
    else
    cout<<"Array is not on max heap\n";
}