#include<iostream>
using namespace std;
void subsequence(char *in,char *out,int i,int j)
{
    if(in[i]=='\0')
    {
        out[j]='\0';
        cout<<out<<endl;
        return;
    }

    //Recursive case 
    out[j]=in[i];
    // 1. Include the curr character
    subsequence(in,out,i+1,j+1);
    // 2. Exclude the curr character
    subsequence(in,out,i+1,j);
}
int main()
{
    char in[100];
    cin>>in;
    char out[100];

    subsequence(in,out,0,0);
}