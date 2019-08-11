#include<iostream>
using namespace std;
void sort(int a[],int n)
{
    //outer loop tellls us the no of iterations 
    for(int i=0;i<n-1;i++)
    {
        //n-i-1 because last i elemnts are already in sorted place
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            swap(a[j],a[j+1]);
        }
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

    sort(a,n);

    cout<<"After Sorting = \n";

    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;

}