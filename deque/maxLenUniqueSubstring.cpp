#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    string a;
    cin>>a;

    int n = a.size();
    int curr_len = 1;
    int max_len = 1;

    int visited[256] ;

    for(int i=0;i<256;i++)
    visited[i]=-1;

    visited[a[0]]=0;

    for(int i=1;i<n;i++)
    {
        int last_occur = visited[a[i]];
        if(last_occur==-1 || i-curr_len > last_occur)
        {
            curr_len+=1;
            max_len = max(curr_len,max_len);
        }
        else
        {
            max_len=max(max_len,curr_len);
            curr_len = i - last_occur;
        }
        visited[a[i]] = i;
        max_len=max(max_len,curr_len);
    }

    cout<<"Max len unique character substring is "<<max_len<<endl;
}