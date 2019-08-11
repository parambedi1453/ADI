#include<iostream>
using namespace std;
bool isSorted(int *a,int n)
{
    if(n==1)
    return true;
    if(a[0]<a[1] && isSorted(a+1,n-1))
    return true;
    else
    return false;
}

int main()
{
    int a[]={1,2,3,44,5};
    int n=5;
    if(isSorted(a,n)){
        cout<<"Sorted"<<endl;
    }
    else
    cout<<"Not Sorted"<<endl;
}
