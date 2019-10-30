// PROBLEM SAME AS ACTIVITY SELECTION,INTERVAL SCHDULING,


/*
        There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is start time of meeting i and F[i] is finish time of meeting i.

        What is the maximum number of meetings that can be accommodated in the meeting room?

        Input:
        The first line of input consists number of the test cases. The description of T test cases is as follows:
        The first line consists of the size of the array, second line has the array containing the starting time of all the meetings each separated by a space, i.e., S [ i ]. And the third line has the array containing the finishing time of all the meetings each separated by a space, i.e., F [ i ].

        Output:
        In each separate line print the order in which the meetings take place separated by a space.

        Constraints:
        1 ≤ T ≤ 70
        1 ≤ N ≤ 100
        1 ≤ S[ i ], F[ i ] ≤ 100000

        Example:
        Input:
        2
        6
        1 3 0 5 8 5
        2 4 6 7 9 9
        8
        75250 50074 43659 8931 11273 27545 50879 77924
        112960 114515 81825 93424 54316 35533 73383 160252  

        Output:
        1 2 4 5
        6 7 1
*/
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
        cout<<"Positions are = \n";
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
        cout<<"Total number of meetings that can take place = "<<c<<endl;
	}
	
	return 0;
}