#include<iostream>
using namespace std;
// in Forward heapify the chuld sets the parent

// always call the heapify fucntion for those elements due to which index therre is a change in the maxheap or minheap
void forwardHeapify(int a[],int child)
{
    if(child<0)
    return;

    int parent = child/2;
    if(a[child]>a[parent])
    {
        swap(a[child],a[parent]);
        forwardHeapify(a,parent);
    }
}


int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<"Entered array is =\n";
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    // buildHeap(a,n);
    // cout<<"max heap array is =\n";
    // for(int i=0;i<n;i++)
    // cout<<a[i]<<" ";
    // cout<<endl;
    int e;
    cout<<"Enter Element to be inserted = \n";
    cin>>e;
    a[n]=e;
    forwardHeapify(a,n);
    // in this the child checks that because of me if parent element is disturbed then i get swapped by it

    cout<<"Array after insertion is =\n";
    for(int i=0;i<=n;i++)
    cout<<a[i]<<" ";
    cout<<endl;

}