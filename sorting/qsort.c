#include<stdio.h>
#include<stdlib.h>
int comp(const void *a,const void *b)
{
    int *x = (int*)a;
    int *y = (int*)b;
    
    if(*x>*y)
    return 1;
    return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    int i=0;
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    for(i=0;i<n;i++)
    printf("%d ",a[i]);
    qsort(a,n,sizeof(int),comp);
    printf("\n");
    for(i=0;i<n;i++)
    printf("%d ",a[i]);

}