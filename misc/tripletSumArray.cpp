/*

    Given an array A[] of N numbers and another number x, determine whether or not there exist three elements in A[] whose sum is exactly x.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains n and x. Next line contains array elements.

Output:
Print 1 if there exist three elements in A whose sum is exactly x, else 0.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 103
1 ≤ A[i] ≤ 105

Example:
Input:
2
6 13
1 4 45 6 10 8
5 10
1 2 4 3 6

Output:
1
1

Explanation:
Testcase 1: There is one triplet with sum 13 in the array. Triplet elements are 1, 4, 8, whose sum is 13.
 

*/

#include <iostream>
#include<algorithm>
using namespace std;
int checkThreeSum(int a[],int n,int target)
{
        int sum;
        sort(a,a+n);
	    for(int i=0;i<n-2;i++)
	    {
	        sum=target-a[i];
	        int j = i+1;
	        int k = n-1;
	        while(j<k)
	        {
	            if(a[j]+a[k]==sum)
	            return 1;
	            else if(a[j]+a[k]<sum)
	            j=j+1;
	            else
	            k=k-1;
	        }
	    }
	    return 0;
}
int main() {
	
	int t,n,target;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    cin>>target;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    
	    cout<<checkThreeSum(a,n,target)<<endl;
	    
	}
	return 0;
}