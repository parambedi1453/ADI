#include<iostream>
#include<vector>
#include<deque>
using namespace std;

vector<int> slidingWindow(int a[],int n,int k)
{
    deque<int> q(k);
    vector<int> res;
    int i;
    for(i=0;i<k;i++)
    {
        while(!q.empty() && a[i]>=a[q.back()])
        q.pop_back();

        q.push_back(i);
    }

    for(;i<n;i++)
    {
        res.push_back(a[q.front()]);
        // cout<<a[q.front()]<<" ";

        while(!q.empty()  && q.front() <=i-k)
        q.pop_front();

        while(!q.empty() && a[i]>=a[q.back()])
        q.pop_back();

        q.push_back(i);

    }
    res.push_back(a[q.front()]);
    return res;
}
int main()
{
    int n,k;
    cout<<"Enter number of elements =\n";
    cin>>n;
    int a[n];
    cout<<"Enter elements =\n";
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<"Enter size of window = \n";
    cin>>k;

    vector<int> res;
    res = slidingWindow(a,n,k);

    for(int i=0;i<res.size();i++)
    cout<<res[i]<<" ";
    cout<<endl;
}