#include <stdio.h>
/* Include other headers as needed */

int lower_bound(int a[],int n,int x)
{
    int l=0,r=n-1,mid,ans=-1;
    while(l<=r)
    {
        mid = (l+r)/2;
        if(a[mid]>=x)
        {
            ans = mid;
            r=mid-1;
        }
        else
        l=mid+1;
    }
    return ans;
}
int main()
{
  int t,n,k;
 scanf("%d",&t);
  while(t--)
  {
    scanf("%d %d",&n,&k);
    int a[n];
    for(int i=0;i<n;i++)
     scanf("%d",&a[i]);
    int d =lower_bound(a,n,k);
    printf("%d\n",d);
  }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}