#include<iostream>
#include<algorithm>
using namespace std;
void printLcs(int k[100][100],int i,int j,string x,string y,string str)
{
    if(i==0||j==0)
    {
       string k = str;
       reverse(k.begin(),k.end());
       cout<<k<<endl;
       return ;
    }
    // if same then add char to string and call for previous diagnal
    if(x[i-1]==y[j-1])
    {
        str=str+x[i-1];
        printLcs(k,i-1,j-1,x,y,str);
    }
    // if not then check from where the max came from if came and accordingly call for that matrix index
    else
    {
        if(k[i-1][j]>k[i][j-1])
        printLcs(k,i-1,j,x,y,str);
        else
        printLcs(k,i,j-1,x,y,str);
    }
    
}
int main()
{
    string x, y;
    cout<<"Enter Strings =\n";
    cin>>x;
    cin>>y;
    int row = x.size()+1;
    int col = y.size()+1;
    int k[100][100];

    for(int i=0;i<row;i++)
    k[0][i]=0;
    for(int j=0;j<row;j++)
    k[j][0]=0;
    
    for(int i=1;i<row;i++)
    {
        for(int j=1;j<col;j++)
        {
            if(x[i-1]==y[j-1])
            k[i][j]=1+k[i-1][j-1];
            else
            {
                k[i][j] = max(k[i-1][j],k[i][j-1]);
            }   
        }
    }
    cout<<k[row-1][col-1]<<endl;
    
    string ans="";


    // printing of the longest commom susequence
    printLcs(k,row-1,col-1,x,y,ans);

}