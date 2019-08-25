#include<iostream>
using namespace std;
// void subsequence(char *in,char *out,int i,int j)
// {
//     if(in[i]=='\0')
//     {
//         out[j]='\0';
//         cout<<out<<" ";
//         cout<<j<<endl;
//         return;
//     }

//     //Recursive case 
//     out[j]=in[i];


      
//     // 1. Include the curr character
//     subsequence(in,out,i+1,j+1);
//       // 2. Exclude the curr character
//     subsequence(in,out,i+1,j);
   
   
  
// }
// int main()
// {
//     char *in = new char[100];
//     cin>>in;
//     char *out=new char[100];

//     subsequence(in,out,0,0);
// }
int c=0;
// void print(int a[],int out[],int i,int j,int n)
// {
//     // static int c=0;
//     c++;
//     if(i==n)
//     {
//         for(int k=0;k<j;k++)
//         cout<<out[k];
//         cout<<endl;

//         return ;
//     }
//     out[j]=a[i];
//     print(a,out,i+1,j+1,n);

//     print(a,out,i+1,j,n);
// }
void print(int a[],int out[],int i,int j,int n)
{
    c++;
        for(int k=0;k<j;k++)
        cout<<out[k];
        cout<<endl;
        // out[j]=a[i];
        for(int k=i;k<n;k++)
        {
            out[j] = a[k];
            print(a,out,k+1,j+1,n);
        }
}
// int main()
// {
//     int n;
//     cin>>n;
//     int a[n];
//     for(int i=0;i<n;i++)
//     cin>>a[i];

//     int out[n];
//     print(a,out,0,0,n);
// }
int main()
{
    int n;
    cin>>n;
    int a[10];
    for(int i=0;i<n;i++)
    cin>>a[i];

    int out[10];
    print(a,out,0,0,n);
    cout<<c;
}
