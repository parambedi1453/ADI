#include<iostream>
using namespace std;
int main()
{
    int len,n;
    cout<<"Eneter len of rod"\n;
    cin>>len;

    cout<<"Enter len array size =\n";
    cin>>n;

    int l[n],p[n];
    cout<<"Enter len cut = \n";
    for(int i=0;i<n;i++)
    cin>>l[i];
    cout<<"Enter profit=\n";
    for(int i=0;i<n;i++)
    cin>>p[i];

    int col = len+1;
    int row = n+1;

    int k[row][col];
    for(int i=0;i<col;i++)
    k[0][i] = 0;
    for(int j=0;j<row;j++)
    k[j][0]=0;

    for(int i=1;i<row;i++)
    {
        for(int j=1;j<col;j++)
        {
            if(j>=l[i-1])
            {
                k[i][j] = max(p[i-1] + k[i][j-l[i-1]] , k[i-1][j]);
            }
            else
            {
                k[i][j] = k[i-1][j];
            }
            
        }
    }

    cout<<k[row-1][col-1]<<endl;
}
