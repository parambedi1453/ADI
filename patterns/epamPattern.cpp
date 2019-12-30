#include<iostream>
using namespace std;
int main()
{
    int row;
    cin>>row;

    int al = 65;

    for(int i=0;i<row;i++)
    {
        int c = 0;
        for(int j=0;j<row-i;j++)
        {
            cout<<(char)(al+j);
            c++;
        }
        for(int k=1;k<=i;k++)
        cout<<" ";

        int w;
        if(i==0)
        w=c-2;
        else
        w=c-1;
        for(;w>=0;w--)
        {
            // if(i!=0)
            cout<<(char)(al+w);
        }
        cout<<endl;
    }
}