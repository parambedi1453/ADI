/*
    Given a set of N jobs where each job i has a deadline and profit associated to it. Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit if and only if the job is completed by its deadline. The task is to find the maximum profit and the number of jobs done.

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case consist of an integer N in first line denoting the number of jobs and the next line consist of Job id, Deadline and the Profit associated to that Job.

Output:
Output the number of jobs done and the maximum profit.

Constraints:
1 <= T <= 100
1 <= N <= 100
1 <= Deadline <= 100
1 <= Profit <= 500

Example:
Input:
2
4
1 4 20 2 1 10 3 1 40 4 1 30
5
1 2 100 2 1 19 3 2 27 4 1 25 5 1 15

Output:
2 60
2 127

Explanation:
Testcase 1: 2 jobs can be done with maximum profit of 60.
*/
#include <iostream>
#include<algorithm>
using namespace std;

class Job
{
    public:
    int id;
    int dead;
    int pro;
};
bool comp(Job ob1,Job ob2)
{
    
    return ob1.pro>ob2.pro;
}
int main() {
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        Job a[n];
        int maxdeadline=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i].id;
            cin>>a[i].dead;
            cin>>a[i].pro;
            maxdeadline=max(maxdeadline,a[i].dead);
        }
        sort(a,a+n,comp);
        
        int b[maxdeadline]={0};
        int c=0,ans=0;
        for(int i=0;i<n;i++)
        {
            int dline = a[i].dead-1;
            for(int j=dline;j>=0;j--)
            {
                if(b[j]==0)
                {
                    b[j]=-1;
                    c++;
                    ans+=a[i].pro;
                    break;
                }
            }
        }
        cout<<c<<" "<<ans<<endl;
    }
	//code
	return 0;
}

