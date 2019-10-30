#include<iostream>
#include<cstring>
using namespace std;
void patternMatching(string str,string ptr)
{
    for(int i=0;i<=str.size()-ptr.size();i++)
    {
        int j=0;
        for(j=0;j<ptr.size();j++)
        {
            if(str[i+j]!=ptr[j])
            break;
        }
        if(j==ptr.size())
        {
            cout<<"Patern found at index "<<i<<endl;
        }
    }
}
int main()
{
    string str,ptrn;
    cin>>str;
    cin>>ptrn;

    patternMatching(str,ptrn);

}