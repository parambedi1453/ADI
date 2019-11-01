#include<iostream>
using namespace std;
int main()
{
    string x, y;
    cout<<"Enter Strings =\n";
    cin>>x;
    cin>>y;
    int row = x.size()+1;
    int col = y.size()+1;
    int k[row][col];

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
    

}