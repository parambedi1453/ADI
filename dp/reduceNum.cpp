/* Given a number we need to reduce it to 1 in min number of stpes
    given number of operation as divide by 3,divide by 2,sub 1
    eg 21
    op 4

    eg 10
    op 3
*/
#include<iostream>
#include<cmath>
using namespace std;
const int inf = (int)1e9;

// In this function we cannot compute 1000 because overlapping recursive calls
int reduceNum(int n)
{
    if(n==1)
    return 0;

    int a1 = INT8_MAX,a2=INT8_MAX,a3=INT8_MAX;
    
    if(n%3 == 0) a1= 1 + reduceNum(n/3);
    if(n%2 == 0) a2 = 1+reduceNum(n/2);
    a3= 1+reduceNum(n-1);
    return min(a1,min(a2,a3));

}

// memoised solution to the above problem
int memo[10000];

int reduceNumMemo(int n)
{
    if(n==1)
    return 0;

    int a1 = INT8_MAX,a2=INT8_MAX,a3=INT8_MAX;
    if(memo[n]!=-1)
    return memo[n];
    if(n%3 == 0) a1= 1 + reduceNumMemo(n/3);
    if(n%2 == 0) a2 = 1+reduceNumMemo(n/2);
    a3= 1+reduceNumMemo(n-1);
    
    memo[n] =  min(a1,min(a2,a3));
    return memo[n];

}


int main()
{
    int n;
    cin>>n;
    // int ans = reduceNum(n);
    for(int i=0;i<10000;i++)
    memo[i]=-1;
    int ans = reduceNumMemo(n);
    cout<<ans<<endl;
}
