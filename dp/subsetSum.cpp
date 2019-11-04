#include<iostream>
using namespace std;
int main()
{
    int n,sum;
    cout<<"Enter Elements = \n";
    cin>>n;
    int a[n];
    cout<<"Enter sum to be found = \n";
    cin>>sum;
    cout<<"Enetr array elements = \n";
    for(int i=0;i<n;i++)
    cin>>a[i];

    int row = n+1;
    int col = sum+1;

    int k[row][col];
    k[0][0]=1;
    for(int i=1;i<col;i++)
    k[0][i] =0;
    for(int j=1;j<row;j++)
    k[j][0] = 1;

    for(int i=1;i<row;i++)
    {
        for(int j=1;j<col;j++)
        {
            if(a[i-1]>j)
            k[i][j]=k[i-1][j];
            else
            {
                k[i][j] = k[i-1][j-a[i-1]] || k[i-1][j];
            }
        }
    }

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<k[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<k[row-1][col-1]<<endl;


    
}