#include<iostream>
using namespace std;
int main()
{
    int r,c;
    cout<<"Enter No of rows = \n";
    cin>>r;
    cout<<"Enter no of cols =\n";
    cin>>c;
    int a[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
   /*  
   
   Method Number 1
    
   int col[c]={0};
    int row[r]={0};
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(a[i][j]==0)
            {
                row[i]=-1;
                col[j]=-1;
            }
        }
    }
    for(int i=0;i<r;i++)
    {
        if(row[i]==-1)
        {
            for(int j=0;j<c;j++)
            a[i][j]=0;
        }
    }
    for(int j=0;j<c;j++)
    {
        if(col[j]==-1)
        {
            for(int i=0;i<r;i++)
            a[i][j]=0;
        }
    }

    */


    // second method by marking -1 in the matirx where 0s is there

   /* for(int i=0;i<r;i++)
   {
       for(int j=0;j<c;j++)
       {
           if(a[i][j]==0)
           a[i][j]=-1;
       }
   }

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(a[i][j]==-1)
            {
                for(int k=0;k<c;k++)
                {
                    if(a[i][k]!=-1)
                    a[i][k]=0;
                }
                for(int k=0;k<r;k++)
                {
                    if(a[k][j]!=-1)
                    a[k][j]=0;
                }
                a[i][j]=0;
            }
        }
    }
*/


// IMPORTANT WITHOUT USING EXTRA SPACE 
  int rowf =0,colf=0,i,j,rr=0,cc=0;
    for(i=0;i<c;i++)
    {
        if(a[0][i]==0)
        {
            rr=1;
            break;
        }
    }
    for(j=0;j<r;j++)
    {
        if(a[j][0]==0)
        {
            cc=1;
            break;
        }
        
    }
    for( i=1;i<r;i++)
    {
        for( j=1;j<c;j++)
        {
            if(a[i][j]==0)
            {
                a[i][0]=0;
                a[0][j]=0;
            }
        }
    }
    if(a[0][0]==0)
    {
        rowf=1;
        colf=1;
    }
    for( i=1;i<c;i++)
    {
        if(a[0][i]==0)
        {
            rowf=1;
            for(j=1;j<r;j++)
            {
                a[j][i]=0;
            }
        }
    }
    for(j=1;j<r;j++)
    {
        if(a[j][0]==0)
        {
            colf=1;
            for(i=1;i<c;i++)
            {
                a[j][i]=0;
            }
        }
    }
      if(rowf==1&&rr==1)
    {
        for(i=0;i<c;i++)
        {
            a[0][i]=0;
        }
    }
    if(colf==1&&cc==1)
    {
        for( i=0;i<r;i++)
        {
            a[i][0]=0;
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    

}