#include<iostream>
#include<algorithm>
using namespace std;
class object
{
    public:
    int profit;
    int weight;
};
bool comp(object ob1,object ob2)
{
    double v1 = (double)ob1.profit/ob1.weight;
    double v2 = (double)ob2.profit/ob2.weight;
    return v1>v2;
}
int main()
{
    int m,n;
    cin>>m>>n;
    object a[n];
    int x,y;
    for(int i=0;i<n;i++)
    {
       cin>>a[i].profit;
       cin>>a[i].weight;
    }

    // double ratio[7];
    // for(int i=0;i<7;i++)
    // {
    //     ratio[i] = (double)a[i].profit/(double)a[i].weight;
    // }

    sort(a,a+n,comp);

    int cw = 0;  
    double finalvalue = 0.0; 
  
    
    for (int i = 0; i < n; i++) 
    { 
        
        if (cw + a[i].weight <= m) 
        { 
            cw += a[i].weight; 
            finalvalue += a[i].profit; 
        } 
  
        else
        { 
            int remain = m - cw; 
            finalvalue += a[i].profit * ((double) remain / a[i].weight); 
            break; 
        } 
    } 
  
     
    cout<<finalvalue<<endl; 
   
}
