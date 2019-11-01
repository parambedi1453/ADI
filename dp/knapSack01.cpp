#include<iostream>
using namespace std;
class Bag
{
    public :
    int profit;
    int weight;
};
int main()
{
    int n,c;
    cout<<"Enter no of items = \n";
    cin>>n;
    cout<<"Enter capacity = \n";
    cin>>c;

    Bag a[n];
    cout<<"Enter pro and w =\n";

    for(int i=0;i<n;i++)
    {
        cin>>a[i].profit;
        cin>>a[i].weight;
    }

    int row = n+1,col =c+1;
    int k[row][col];
    for(int i=0;i<col;i++)
    k[0][i]=0;
    for(int j=0;j<row;j++)
    k[j][0] = 0;

    for(int i=1;i<row;i++)
    {
        for(int j=1;j<col;j++)
        {
            if(j>=a[i-1].weight)
            {
                k[i][j] = max(k[i-1][j-a[i-1].weight]+a[i-1].profit , k[i-1][j]);
            }
            else
            {
                k[i][j] = k[i-1][j];
            }
        }
    }
    cout<<k[row-1][col-1]<<endl;


}