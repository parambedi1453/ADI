/*

        Given an array arr[] of N non-negative integers representing height of blocks at index i as Ai where the width of each block is 1. Compute how much water can be trapped in between blocks after raining.
Structure is like below:
|  |
|_|
We can trap 2 units of water in the middle gap.



Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. Each test case contains an integer N denoting the size of the array, followed by N space separated numbers to be stored in array.

Output:
Output the total unit of water trapped in between the blocks.

Constraints:
1 <= T <= 100
3 <= N <= 107
0 <= Ai <= 108

Example:
Input:
2
4
7 4 0 9
3
6 9 9

Output:
10
0

Explanation:
Testcase 1: Water trapped by block of height 4 is 3 units, block of height 0 is 7 units. So, total unit of water trapped is 10 units.

 */
// technique used is recomputaion of array
#include <iostream>
#include<stack>
using namespace std;

int main() {
    
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n],left[n],right[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        left[0]=a[0];
        for(int i=1;i<n;i++)
        left[i]=max(a[i],left[i-1]);
        right[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--)
        right[i]=max(a[i],right[i+1]);
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum = sum+min(left[i],right[i])-a[i];
        }
        cout<<sum<<endl;
    }
	

}