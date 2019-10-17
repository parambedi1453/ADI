#include <bits/stdc++.h>
using namespace std;
struct Job
{
    int id,deadline,profit;
};

typedef Job Job;

bool comparator(Job j1,Job j2)
{
    return j1.profit>j2.profit;
}

int main() {
	//code
	int t,i,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        Job jobs[n];
        int max_deadline = 0;
        for(i=0;i<n;i++)
        {
            cin>>jobs[i].id;
            cin>>jobs[i].deadline;
            cin>>jobs[i].profit;
            max_deadline = max(max_deadline,jobs[i].deadline);    
        }
        int intervals[max_deadline];
        for(i=0;i<max_deadline;i++)
        {
            intervals[i] = 0;
        }
        sort(jobs,jobs+n,comparator);
        int sel_jobs = 0;
        int profit = 0;
        i=0;
        int j;
        while(i<n)
        {
            for(j = jobs[i].deadline-1;j>=0;j--)
            {
                if(intervals[j] == 0)
                {
                    sel_jobs++;
                    profit += jobs[i].profit;
                    intervals[j] = 1;
                    break;
                }
            }
            i++;
        }
        cout<<sel_jobs<<" "<<profit<<endl;
    }
	return 0;
}