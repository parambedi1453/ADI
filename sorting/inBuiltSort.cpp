#include<iostream>
#include<algorithm>
using namespace std;
// sort(a,a+n)
// sort(s,e);  s is included and e is excluded
bool myCompare(int a,int b)
{
    return a>b;
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

    // countingSort(a,n);
    sort(a,a+n,myCompare);

    cout<<"After Sorting = \n";

    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;

}
