/*
    A frog jumps either 1, 2 or 3 steps to go to top. In how many ways can it reach the top.

Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. Each testcase contains one line of input N denoting the total number of steps.

Output:
For each testcase, in a new line, print the number of ways to reach the top.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 50

Example:
Input:
2
1
5
Output:
1
13

*/

#include <iostream>
using namespace std;
int getWays(int n)
{
    int k[n+1];
    k[1]=1;
    k[2]=2;
    k[3]=4;
    for(int i=4;i<n+1;i++)
    {
        k[i]=k[i-1]+k[i-2]+k[i-3];
    }
    return k[n];
}
int main() {
	//code
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int ans = getWays(n);
	    cout<<ans<<endl;
	}
	return 0;
}