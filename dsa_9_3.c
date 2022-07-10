#include<stdio.h>
#include<conio.h>

void quick_sort(int a[], int beg, int end);
int main()
{
    int a[10],N;
    int i;
    printf("Enter no of elements : ");
    scanf("%d",&N);

    for(i=0;i<N;i++)
        scanf("%d",&a[i]);

    quick_sort(a, 0, N-1);

    printf("\n=======Sorted List=========\n");

    for(i=0;i<N;i++)
        printf("\t%d\n",a[i]);
}
void quick_sort(int a[], int LB, int UB)
{
    int j,i,flag=1,key,temp,m;
    if(LB<UB)
    {
        i=LB;
        j=UB;
        key=a[LB];
        while(flag)
        {
            i=i+1;
            while(a[i]<key && i<=UB)
            {
                i=i+1;
            }
            while(a[j]>key && j>LB)
            {
                j=j-1;
            }
            if(i<j)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
            else
            {
                flag=0;
            }
        }
        temp=a[LB];
        a[LB]=a[j];
        a[j]=temp;
       /* printf("\n%d=%d=%d=%d",i,j,LB,UB);
        for(m=LB;m<=j-1;m++)
            printf("   %d",a[m]);
        printf("\t\t%d\t\t",a[j]);
        for(m=j+1;m<=UB;m++)
            printf("   %d",a[m]);
*/
        quick_sort(a, LB, j-1);
        quick_sort(a, j+1, UB);
    }
    else
    {
        return;
    }
}