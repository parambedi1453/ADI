#include<iostream>
using namespace std;

void insertionSort(int a[],int n)
{
    int num,j;
    for(int i=0;i<n;i++)
    {
        num = a[i];
        for(j=i-1;j>=0 && a[j]>num; j--)
        {
            a[j+1] = a[j];
        }
        a[j+1]=num;
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

    insertionSort(a,n);

    cout<<"After Sorting = \n";

    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;

}