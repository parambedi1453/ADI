/*
        You are given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs whereas the other two number occur exactly once and are distinct. You need to find the other two numbers and print them in ascending order.
 

Input :
The first line contains a value T, which denotes the number of test cases. Then T test cases follow .The first line of each test case contains a value N. The next line contains 2*N+2 space separated integers.

Output :
Print in a new line the two numbers in ascending order.

Constraints :
1<=T<=100
1<=N<=10^6
1<=A[i]<=5*10^8

Example:
Input :
2
2
1 2 3 2 1 4
1
2 1 3 2

Output :
3 4
1 3

 */

#include <iostream>
using namespace std;

int main() {
	
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    n=n*2+2;//given case
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    int res=0;
	    for(int i=0;i<n;i++)
	    res = res^a[i];
	    
	   // cout<<res<<" ";
	    int setbit;
	    for(int i=0;i<31;i++)
	    {
	        if((1<<i)&res)
	        {
	            setbit = i;// find the first bit due to which differnce is being created
	            break;
	        }
	    }
	    
	   // cout<<setbit<<" ";
	    int res2 = 0;//all the numbers due to which differnce  is created due to first set bit will be xored and the one of the two unique will be gathered here
	    for(int i=0;i<n;i++)
	    {
	        if((1<<setbit)&a[i])
	        {
	            res2=res2^a[i];
	        }
	    }
	   // cout<<res2<<endl;
	    res = res^res2;
	    if(res<res2)
	    cout<<res<<" "<<res2<<endl;
	    else
	    cout<<res2<<" "<<res<<endl;
	    
	}
	
	
	return 0;
}