#include <iostream>
#include<stack>
using namespace std;

int main() {
    
    int n;
    
        cin>>n;
        int a[n],left[n],right[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        int lmax=0,rmax=0,l=0,r=n-1,sum=0;
        while(l<=r)
        {
            if(a[l]<a[r])
            {
                if(a[l]>lmax)// means a[l] ki side wali diwar choti hai toh pani nhi aa skta
                lmax = a[l];
                else
                sum+=lmax-a[l];
                l++;
            }
            else
            {
                if(a[r]>rmax)
                rmax = a[r];
                else
                sum+=rmax-a[r];
                r--;
            }
            
        }
        cout<<sum<<endl;
    
	

}