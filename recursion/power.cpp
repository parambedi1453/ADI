#include<iostream>
using namespace std;
// int pow(int a,int b)
// {
//     if(b==0)
//     return 1;
//     int ans = a*pow(a,b-1);
//     return ans;
// }
//  in the above process b no of steps were taken

int pow(int a,int b)
{
    if(b==0)
    return 1;

    int smallAns = pow(a,b/2);
    smallAns *= smallAns;
    if(b&1)
    return a*smallAns;
    return smallAns;

}
// this works proportional to logb
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<pow(a,b)<<endl;

}
