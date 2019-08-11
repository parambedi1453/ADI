#include<iostream>
using namespace std;
void printN(int n)
{
    if(n==0)
    return;
    printN(n-1);
    cout<<n<<" ";
}
void printD(int n)
{
    if(n==0)
    return;

    cout<<n<<" ";
    printD(n-1);
    return ;
}
int main()
{
    int n;
    cin>>n;
    printN(n);
    cout<<endl;
    printD(n);
    cout<<endl;
}
