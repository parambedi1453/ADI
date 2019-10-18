#include<iostream>
#include<cstring>
using namespace std;
string findmatch(string a1,string a2)
{
    int l1 = a1.length();
    int l2 = a2.length();
    int n = l1<l2?l1:l2;
    string ans="";
    for(int i=0;i<n;i++)
    {
        if(a1[i]!=a2[i])
        return ans;
        else
        ans = ans+a1[i];
    }
}
int main()
{
    string str;
    // getline(cin,str);for multiline string
    cout<<"Input the character String = \n";
    cin>>str;
    cout<<str<<endl;

    int  l = str.length();
    char *p[l];
    for(int i=0;i<l;i++)
    {
        p[i] = &str[i];
    }

    for(int i=0;i<l;i++)
    {
        for(int j=i+1;j<l;j++)
        {
            if(strcmp(p[i],p[j])>0)
            {
                char *temp = p[i];
                p[i]=p[j];
                p[j] = temp;
            }
        }
    }

    // for(int i=0;i<l;i++)
    // {
    //     cout<<p[i]<<endl;
    // }

    string ans = "";
    string prev="";
    for(int i=0;i<l-1;i++)
    {
        prev=ans;
        ans = findmatch(p[i],p[i+1]);
        if(prev.length()>ans.length())
        {
            ans=prev;
        }
    }
    if(ans=="")
    {
        cout<<"No Substring is Found=\n";
    }
    else
    {
        cout<<ans<<endl;
    }
    
}