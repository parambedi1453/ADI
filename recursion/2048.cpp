#include<iostream>
#include<map>
using namespace std;

char m[][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
void printNum(int n)
{
    if(n==0)
    return;
    printNum(n/10);
    cout<<m[n%10]<<" ";
}


int main()
{
    int n;
    cin>>n;
    printNum(n);
    cout<<endl;
}