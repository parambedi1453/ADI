#include<iostream>
using namespace std;

// void bsort(int *a,int n)
// {
//     if(n==1)
//     return;

//     //sort 1 element and call for remaining n-1 elements
//     for(int j=0;j<=n-2;j++)
//     {
//         if(a[j]>a[j+1])
//             swap(a[j],a[j+1]);
//     }
//     bsort(a,n-1);
// }

void bsort2(int a[],int j,int n)
{
    if(n==1)
    return;
    if(j==n-1)
    {
        bsort2(a,0,n-1);// so that j can loop agin and last element is sorted therfore n-1 array is called
        return;
    }

    if(a[j]>a[j+1])
    swap(a[j],a[j+1]);
    bsort2(a,j+1,n);
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    bsort2(a,0,n);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}