/*
    we are given a length n we need to generate binary string all possible of lenght n
    for eg l = 2;
    00
    01
    10
    11
 */

#include<iostream>
using namespace std;
void printBinaryString(int a[],int n,int i)
{
    if(i==n)
    {
        for(int j=0;j<n;j++)
        cout<<a[j];
        cout<<endl;
        return;
    }
    a[i]=0;
    printBinaryString(a,n,i+1);
    a[i]=1;
    printBinaryString(a,n,i+1);
}
int main()
{
    int n;
    cout<<"Enter Length = \n";
    cin>>n;
    int a[n];
    
    printBinaryString(a,n,0);

}