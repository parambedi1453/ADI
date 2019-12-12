#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    int j,t;
    for(int i=0;i<n;i++){
        if(i!=0 &&a[i]<0)
        {
            j = i-1;
            t = i;
            while(j>=0 &&a[j]>0)
            {
                swap(a[j],a[t]);
                t=j;
                j--;
            }
        }
    }
     for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}