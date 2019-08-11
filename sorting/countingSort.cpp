// Counting Sort is same as hashing
#include<iostream>
using namespace std;
void countingSort(int a[],int n)
{
    int max = a[0];
    for(int i=1;i<n;i++)
    max = max>a[i]?max:a[i];

    int freq[max]={0};
    for(int i=0;i<n;i++)
    freq[a[i]]++;

    int k = 0,i=0;
   while(k<n)
   {
       while(freq[i])
       {
           a[k++]=i;
           freq[i]--;
       }
       i++;
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

    countingSort(a,n);

    cout<<"After Sorting = \n";

    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;

}