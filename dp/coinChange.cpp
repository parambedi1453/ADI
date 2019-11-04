/*
        Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins. The order of coins doesn’t matter. For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, the first line contains an integer 'M' denoting the size of array. The second line contains M space-separated integers A1, A2, ..., AN denoting the elements of the array. The third line contains an integer 'N' denoting the cents.

Output:
Print number of possible ways to make change for N cents.

Constraints:
1 ≤ T ≤ 50
1 ≤ N ≤ 300
1 ≤ A[i] ≤ 300

Example:
Input:
2
3
1 2 3
4
4
2 5 3 6
10

Output:
4
5

Explanation:
Testcase 1: The possiblities are as such: {1, 1, 1, 1}, {1, 1, 2}, {1, 3}, {2, 2}.

*/

#include <iostream>
using namespace std;
int cntCoins(int a[],int n,int coins)
{
    int row = n+1;
    int col = coins+1;
    
    int k[row][col];
    k[0][0]=1;
    
    for(int i=1;i<col;i++)
    k[0][i]=0;
    for(int j=1;j<row;j++)
    k[j][0]=1;
    
    for(int i=1;i<row;i++)
    {
        for(int j=1;j<col;j++)
        {
            if(j<a[i-1])
            k[i][j] = k[i-1][j];
            else
            k[i][j] = k[i][j-a[i-1]] + k[i-1][j];
        }
    }
    
    return k[row-1][col-1];
}
int main() {
	//code
	int t,n,coins;
    // Eneter Test Case
	cin>>t;
	while(t--)
	{
        // Enter size of array
	    cin>>n;
	    int a[n];
        // Enter Array
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    
        // Enter coins;
	    cin>>coins;
	    
	    int ans  = cntCoins(a,n,coins);
	    
	    cout<<ans<<endl;
	}
	return 0;
}