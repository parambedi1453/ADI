/*

output the max sal person and if sal is same then output the one whose name is lexigraphicaly small
    4
bob 99 
alia 58
suzi 58
ali 102


ali 102
bob 99
alia 58
suzi 58

 */


#include<iostream>
#include<algorithm>
using namespace std;
bool myCompare(pair<string,int> p1, pair<string,int> p2)
{
    if(p1.second == p2.second)
    {
        return p1.first<p2.first;
    }

    return p1.second>p2.second;
}
int main()
{

    int n,minSal;
    pair<string,int> e[100005];

    cout<<"Enter Minimum Salary = \n";
    cin>>minSal;
    
    cout<<"Enter No. of workers=\n";
    cin>>n;

    string name;
    int salary;

    for(int i=0;i<n;i++)
    {
        cin>>name>>salary;
        e[i].first = name;
        e[i].second = salary;
    }

    sort(e,e+n,myCompare);

    for(int i=0;i<n;i++)
    {
        cout<<e[i].first<<" "<<e[i].second<<endl;
    }
}