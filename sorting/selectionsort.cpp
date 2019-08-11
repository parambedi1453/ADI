// logic is to assume the ith element as minimum and find the min int i+1 part if found than swap with the ith index


#include<iostream>
using namespace std;
void selectionSort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        // for every i assume ith element is minmunn
        int minIndex = i;
        //find if there is min in the remaining array if yes take that to minindex and swap it with tje ith index
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[minIndex])
            minIndex = j;
        }
        swap(a[i],a[minIndex]);
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

    selectionSort(a,n);

    cout<<"After Sorting = \n";

    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
}