/*
    we are given a length n we need to generate binary string all possible of lenght n given that second bit is 1
    for eg l = 2;
    10
    11

    Case of backtracking 
    backtracking is use to solve the problrms using efficientt recursion (thats the thin difference between recursion and backtracking)
 */

#include<iostream>
using namespace std;
void printBinaryString(int a[],int n,int i,int bit)
{
    if(i==n)
    {
        for(int j=0;j<n;j++)
        cout<<a[j];
        cout<<endl;
        return;
    }
    if(i!=bit-1)
    {
        a[i]=0;
        printBinaryString(a,n,i+1,bit);
    }
    a[i]=1;
    printBinaryString(a,n,i+1,bit);
}
int main()
{
    int n;
    cout<<"Enter Length = \n";
    cin>>n;
    int a[n];
    
    printBinaryString(a,n,0,2);

}