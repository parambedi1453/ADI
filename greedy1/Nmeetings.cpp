// PROBLEM SAME AS ACTIVITY SELECTION,INTERVAL SCHDULING,
#include<iostream>
#include<algorithm>
using namespace std;
class Interval
{
    public :
    int s;//denoting the start time
    int f;//denoting the end time
    int pos;
};
bool comp(Interval ob1,Interval ob2)
{
    return ob1.f<ob2.f;
}
int main() {
	//code
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    Interval a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i].s;
	        a[i].pos=i+1;
	    }
	    for(int i=0;i<n;i++)
	    cin>>a[i].f;
	    
	    sort(a,a+n,comp);
	    
	    int c = 1,prev=0;
	    cout<<a[prev].pos<<" ";
	    for(int i=1;i<n;i++)
	    {
	        if(a[i].s>=a[prev].f)
	        {
	            cout<<a[i].pos<<" ";
	            c++;
	            prev=i;
	        }
	    }
	    cout<<endl;
	}
	
	return 0;
}