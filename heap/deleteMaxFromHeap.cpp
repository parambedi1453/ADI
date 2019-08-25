#include<iostream>
using namespace std;
void heapify(int a[],int i,int n)
{
    int lc = 2*i+1;
    int rc = 2*i+2;
    int max=i;
    //if parent is smaller tha childs than swap value of parent with max of both the childs

    if(lc<n && a[lc]>a[i])
    max = lc;
    else
    max=i;
     if(rc<n && a[rc]>a[max])
    max = rc;
   

    if(max!=i)
    {
        // cout<<a[max]<<" "<<a[i]<<endl;
        swap(a[max],a[i]);
        heapify(a,max,n);
    }

}
void buildHeap(int a[],int n)
{
    for(int i=n/2;i>=0;i--)
    {
        heapify(a,i,n);
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<"Entered array is =\n";
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    buildHeap(a,n);
     cout<<"max heap array is =\n";
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    int max = a[0];
    cout<<max<<endl;
    a[0]=a[n-1];
    n--;
    heapify(a,0,n);// send that index due to which the array has been altered
     cout<<"Array after max deletion  is =\n";
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
}