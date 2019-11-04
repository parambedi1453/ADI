/*
    Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1′ into ‘str2′.

Insert
Remove
Replace
All of the above operations are of cost=1.
Both the strings are of lowercase.

Input:
The First line of the input contains an integer T denoting the number of test cases. Then T test cases follow. Each tese case consists of two lines. The first line of each test case consists of two space separated integers P and Q denoting the length of the strings str1 and str2 respectively. The second line of each test case coantains two space separated strings str1 and str2 in order.

Output:
Corresponding to each test case, pirnt in a new line, the minimum number of operations required.

Constraints:
1 <= T <= 50
1 <= P <= 100
1 <= Q <= 100

Example:
Input:
1
4 5
geek gesek

Output:
1

Explanation:
Testcase 1: One operation is required to make 2 strings same i.e. removing 's' from str2.
*/
#include <iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int getMinCost(string s1,string s2)
{
    int row = s2.size()+1;
    int col = s1.size()+1;
    
    int k[row][col];
    k[0][0]=0;
    for(int i=1;i<col;i++)
    k[0][i]=i;
    for(int j=1;j<row;j++)
    k[j][0]=j;
    
    for(int i=1;i<row;i++)
    {
        for(int j=1;j<col;j++)
        {
            if(s2[i-1]==s1[j-1])//same then no operation to be performed hence get previous result
            {
                k[i][j] = k[i-1][j-1];
            }
            else
            {
                // if not same then the evaluating all the threee opationa snd getting which operation would give the min
                int replace  = 1+k[i-1][j-1];
                int del = 1+k[i-1][j];
                int insert = 1+k[i][j-1];
                
                k[i][j]=min(replace,min(del,insert));
            }
        }
    }
    return k[row-1][col-1];
}
int main() {
	//code
	int t,l1,l2;
	cin>>t;
	while(t--)
	{
	    cin>>l1;
	    cin>>l2;
	    
	    string s1,s2;
	    cin>>s1;
	    cin>>s2;
	    
	    int ans = getMinCost(s1,s2);
	    cout<<ans<<endl;
	}
	return 0;
}