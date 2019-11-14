/*

        Given an array of integers where each element represents the max number of steps that can be made forward from that element. The task is to find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then cannot move through that element.

Input: 
The first line contains an integer T, depicting total number of test cases.  Then following T lines contains a number n denoting the size of the array. Next line contains the sequence of integers a1, a2, ..., an.

Output:
For each testcase, in a new line, print the minimum number of jumps. If answer is not possible print "-1"(without quotes).

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107
0 <= ai <= 107

Example:
Input:
2
11
1 3 5 8 9 2 6 7 6 8 9
6
1 4 3 2 6 7
Output:
3
2

Explanation:
Testcase 1: First jump from 1st element, and we jump to 2nd element with value 3. Now, from here we jump to 5h element with value 9. and from here we will jump to last.

*/


#include <iostream>
#include<climits>
using namespace std;
int minJump(int a[],int n)
{
    int b[n];
    int min;
    b[n-1] = 0;
    for(int i=n-2;i>=0;i--)
    {
        if(a[i]==0)
        b[i]=INT_MAX;
        
        else if(a[i]>=n-i-1)
        b[i]=1;
        
        else
        {
            min = INT_MAX;
            for(int j=i+1;j<=i+a[i];j++)
            {
                if(b[j]<min)
                min=b[j];
            }
            if(min!=INT_MAX)
            b[i]=min+1;
            else
            b[i]=min;
            // check case 2 1 0 3imp
        }
       
    }
    return b[0];
}
int main() {
	//code
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    int ans;
	   
	    ans = minJump(a,n);
	    if(ans==INT_MAX)
	    ans=-1;
	    
	    cout<<ans<<endl;
	}
	return 0;
}

// int this b[i] indicates the minimum number of jumps needed to reach a[n-1] from arr[i]. Finally, we return arr[0].
// if 0 then we cannnot reach to end from there hence INT_MAX for not reaching there