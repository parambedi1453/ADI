#include<iostream>
#include<string.h>
using namespace std;
void hex(int n,char *s)
{
    int k=0;
    while(n)
    {
        int r = n%16;
        if(r==10)
        s[k++]='A';
        else if(r==11)
        s[k++]='B';
         else if(r==12)
        s[k++]='C';
         else if(r==13)
        s[k++]='D';
         else if(r==14)
        s[k++]='E';
         else if(r==15)
        s[k++]='F';

        else 
        s[k++]=r+'0';

        n=n/16;

    }

    int i=0,j=strlen(s)-1;
    while(i<=j)
    {
        char t = s[i];
        s[i]=s[j];
        s[j]=t;
        i++;
        j--;
    }
    
}

int main()
{
    int n;
    cin>>n;
    char *s = (char*)malloc(sizeof(char)*100);
    hex(n,s);
    cout<<s<<endl;
}