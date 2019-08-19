/*
        Given a string of characters generate all the permutatuons of given string

 */

#include<iostream>
using namespace std;
void permutations(char ch[],int i)
{
    if(ch[i]=='\0')
    {
        cout<<ch<<endl;
    }
    for(int j=i;ch[j]!='\0';j++)
    {
        swap(ch[i],ch[j]);
        permutations(ch,i+1);
        swap(ch[i],ch[j]);
    }
}
int main()
{
    char ch[100];
    cin>>ch;

    cout<<endl;

    permutations(ch,0);
}