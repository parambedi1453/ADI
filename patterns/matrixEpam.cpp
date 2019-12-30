#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter size of matrix"<<endl;
    cin>>n;
    int a[n][n];
    cout<<"Enter matrix elements"<<endl;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];

    cout<<"Matrix is =\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    // Printing in the downward direction first
    //  k<r
    for(int k=0;k<n;k++)
    {
        cout<<a[k][0];
        int i=k-1;
        int j=1;

        while(1)
        {
            if(i<0 || i>=n || j<0 || j>=n)
            break;

            cout<<a[i][j];
            i--;
            j++;
        }
        cout<<endl;
    }

    // Printing the remainig part
    // k<c
    for(int k=1;k<n;k++)
    {
        cout<<a[n-1][k];
        int i= n-2;
        int j = k+1;

        while(1)
        {
            if(i<0 || i>=n || j<0 || j>=n)
            break;

            cout<<a[i][j];
            i--;
            j++;
        }
        cout<<endl;
    }
    
}
