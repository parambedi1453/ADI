#include<iostream>
using namespace std;
void waveSort(int a[],int n)
{
    for(int i=0;i<n;i+=2)
    {
        if(i>0 && a[i-1]>a[i])
        swap(a[i],a[i-1]);
        if(i<n-1 && a[i+1]>a[i])
        swap(a[i+1],a[i]);
    }
}
int main()
{
    int n;
    cout<<"Enter NO of ELEMENTS = \n";
    cin>>n;
    int a[n];
    cout<<"Enter elements = \n";
    for(int i=0;i<n;i++)
    cin>>a[i];

    cout<<"Before sorting = \n";
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;

    waveSort(a,n);

    cout<<"After Sorting = \n";

    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
}