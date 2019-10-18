int rotationCount(int a[], int size)
{
 	int l=0,r=size-1,mid,next,prev;
  if(a[l]<=a[r])
      return -1;
  while(l<=r)
  {
    mid = (l+r)/2;
    next = (mid+1)%size;
    prev = (mid-1)%size;
    if(a[mid]<=a[next]&&a[mid]<=a[prev])
      return mid;
    else if(a[mid]<=a[r])
      r=mid-1;
    else if(a[mid]>=a[l])
      l=mid+1;
  }

}