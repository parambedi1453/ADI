#include<iostream>
using namespace std;
void heapify(int a[],int i,int n)
{
    int lc = 2*i+1;
    int rc = 2*i+2;
    int max=i;
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
    cout<<"Array before build heap = \n";
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    buildHeap(a,n);
    cout<<"Array after build heap = \n";
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;

    
}