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
    cout<<"Enter String =\n";
    cin>>str;
    cout<<"Enter Pattern to be matched =\n";
    cin>>ptrn;

    patternMatching(str,ptrn);

}