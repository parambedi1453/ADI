/*

        Given a string you need to print all possible strings that can be made by placing spaces (zero or one) in between them. Output should be printed in sorted increasing order of strings.

Input:  str[] = "ABC"
Output: (A B C)(A BC)(AB C)(ABC)
Input:
First line contains the test cases T.  1<=T<=10
Each test case have one line string S of characters of length  N.  1<=N<=10

Output:
One line per test case, every string enclosed in ().(See example). Output should be printed in sorted order.

Example:
Input:
2
AB
ABC

Output:
(A B)(AB)
(A B C)(A BC)(AB C)(ABC)
 */


#include <iostream>
using namespace std;

void printperm(char in[],char out[],int i,int j)
{
    if(in[i+1]=='\0')
    {
        out[j]=in[i];
        out[j+1]='\0';
        cout<<"("<<out<<")";
        return ;
        
    }
    out[j]=in[i];
    out[j+1]=' ';
    //keep space
    printperm(in,out,i+1,j+2);
    //donot keep space
    printperm(in,out,i+1,j+1);
}
int main() {
    
    int t,n;
    cin>>t;
    while(t--)
    {
        char in[10];
        cin>>in;
        char out[20];
        printperm(in,out,0,0);
        cout<<endl;
    }
	//code
	return 0;
}