/*
    Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to bread the item.

Input:
First line consists of an integer T denoting the number of test cases. First line consists of two integers N and W, denoting number of items and weight respectively. Second line of every test case consists of 2*N spaced integers denoting Values and weight respectively. (Value1 Weight1 Value2 Weight2.... ValueN WeightN)

Output:
Print the maximum value possible to put items in a knapsack, upto 2 decimal place.

Constraints:
1 <= T <= 100
1 <= N <= 100
1 <= W <= 100

Example:
Input:
2
3 50
60 10 100 20 120 30
2 50
60 10 100 20

Output:
240.00
160.00

Explanation:
Testcase 1: Total maximum value of item we can have is 240.00 from the given capacity of sack.
*/
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