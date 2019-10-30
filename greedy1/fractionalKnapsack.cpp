#include <iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
class Bag
{
  public :
  int price;
  int weight;
};
bool comparator(Bag ob1,Bag ob2)
{
    double profit1 = (double)(ob1.price/ob1.weight);
      double profit2 = (double)(ob2.price/ob2.weight);
      return profit1>profit2;
}
int main() { 
    int t,n,w;
    cin>>t;
    while(t--)
    {
        // Enter no of entries;
        cin>>n;
        // Eneter weight of the sack
        cin>>w;
        Bag a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i].price;
            cin>>a[i].weight;
        }
        sort(a,a+n,comparator);
        
        double ans = 0.00;
        for(int i=0;i<n;i++)
        {
            if(a[i].weight<=w)
            {
                ans+= a[i].price;
                w=w-a[i].weight;
            }
            else
            {
                // cout<<w<<endl;
                ans+= w * (double)a[i].price/a[i].weight;
                break;
            }
        }
     
      cout << std::setprecision(2) <<std::fixed<<ans<<endl;
    
    }
	//code
	return 0;
}