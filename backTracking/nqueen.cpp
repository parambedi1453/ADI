/*

    The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other. Given an integer n, print all distinct solutions to the n-queens puzzle. Each solution contains distinct board configurations of the n-queens’ placement, where the solutions are a permutation of [1,2,3..n] in increasing order, here the number in the ith place denotes that the ith-column queen is placed in the row with that number. For eg below figure represents a chessboard [3 1 4 2].


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer n denoting the size of the chessboard.

Output:
For each test case, output your solutions on one line where each solution is enclosed in square brackets '[', ']' separated by a space . The solutions are permutations of {1, 2, 3 …, n} in increasing order where the number in the ith place denotes the ith-column queen is placed in the row with that number, if no solution exists print -1.

Constraints:
1 <= T <= 10
1 <= n <= 10

Example:
Input
2
1
4
Output:
[1 ]
[2 4 1 3 ] [3 1 4 2 ]

 */

// GEEKS FOR GEEKS


int flag=0;
bool checkPay(int i,int j,int r[],int c[],int len)
{
    
    for(int l=0;l<len;l++)
    {
        if(i==r[l]||j==c[l]||(abs(i-r[l])==abs(j-c[l])))
        return false;
    }
    return true;
}
void nqueen(int i,int n,int r[],int c[],int k)
{
    if(i==n)
    {
        flag=1;
        cout<<"[";
        for(int m=0;m<k;m++)
        cout<<c[m]+1<<" ";
        cout<<"] ";
        return ;
    }
    for(int j=0;j<n;j++)
    {
        r[k]=i;
        c[k]=j;
        if(checkPay(i,j,r,c,k))
         nqueen(i+1,n,r,c,k+1);
           
    }
    return ;
}
int main() {
	//code
	int t,n;
	cin>>t;
	while(t--)
	{
	    flag=0;
	    cin>>n;
	   // int a[n][n]={0};
	    int r[n],c[n];
	    nqueen(0,n,r,c,0);
	    if(flag==0)
	    cout<<"-1";
	    cout<<endl;
	}
	return 0;
}