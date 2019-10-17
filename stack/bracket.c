#include<math.h>
int minReversal(char* exp)
{
  char a[1000];
  int top=-1;
  for(int i=0;exp[i];i++)
  {
     if(exp[i]=='[')
     {
       top++;
       a[top]='[';
     }
    else if(exp[i]==']')
    {
        if(top!=-1&&a[top]=='[')
          top-=1;
        else
        {
          top++;
          a[top]=']';
        }
    }
  }
  if((top+1)%2==1)
    return -1;
  int c1=0,c2=0,k=top+1;
  while(top!=-1 && a[top]=='[')
  {
    c2++;
    top--;
  }
 
  if(c1==0 && c2==0)
    return 0;
  return k/2+(c2%2);
}