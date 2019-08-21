/*

    Consider a rat placed at (0, 0) in a square matrix m[][] of order n and has to reach the destination at (n-1, n-1). Your task is to complete the function printPath() which returns a sorted array of strings denoting all the possible directions which the rat can take to reach the destination at (n-1, n-1). The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right).

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line contains an integer n denoting the size of the square matrix. The next line contains n*n space separated values of the matrix m where 0's represents blocked paths and 1 represent valid paths.

Output:
For each test case output will be space separated sorted strings denoting all directions, which the rat could take to reach the destination.

User Task:
Since this is functional problem you don't have to worry about input, you just have to complete the function printPath()

Constraints:
1 <= T <= 10
2 <= n <= 10
0 <= m[][] <= 1

Example
Input:
2
4
1 0 0 0 1 1 0 1 0 1 0 0 0 1 1 1
4
1 0 0 0 1 1 0 1 1 1 0 0 0 1 1 1

Output:
DRDDRR
DDRDRR DRDDRR

Explanation:
Testcase 2: The given input is in the form
1 0 0 0
1 1 0 1
1 1 0 0
0 1 1 1
For the above matrix the rat can reach the destination at (3, 3) from (0, 0) by two paths ie DRDDRR and DDRDRR when printed in sorted order we get DDRDRR DRDDRR.
 */

//GEEKS FOR GEEKS

You are required to complete the below method. */
vector<string> v;
int maze(int m[MAX][MAX],int i,int j,int n,int k,char *ch)
{
    if(i<0||j<0||i>=n||j>=n)
    return 0;
    else if(i==n-1 && j==n-1 &&m[i][j]==1)
    {
        ch[k]='\0';
        string s(ch);
        v.push_back(s);
        return 1;
    }
    else if(m[i][j]==0||m[i][j]==-1)
    return 0;
    
    m[i][j]=-1;
    ch[k]='R';
    maze(m,i,j+1,n,k+1,ch);
     ch[k]='D';
    maze(m,i+1,j,n,k+1,ch);
    ch[k]='U';
    maze(m,i-1,j,n,k+1,ch);
    ch[k]='L';
    maze(m,i,j-1,n,k+1,ch);
    
    m[i][j]=1;
   
    
}
vector<string> printPath(int m[MAX][MAX], int n)
{
    
    v.clear();
    char *s = new char[n+n];
    int k = maze(m,0,0,n,0,s);
    sort(v.begin(),v.end());
   
    return v;
    //Your code here	
}