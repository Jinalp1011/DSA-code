#include<stdio.h>
#include<conio.h>
void Mergesort(int a[], int LB, int UB);
void simpleMerge(int a[],int LB,int UB, int MID);

int main()
{
    int N,temp[10];
    int a[10];
    int i,j,k,MID,LB,UB;
    printf("Enter no of elements : ");
    scanf("%d",&N);

    for(i=0;i<N;i++)
        scanf("%d",&a[i]);

    LB=0;
    UB=N-1;
    Mergesort(a,LB,UB);
    printf("\n=======Sorted List=========\n");
    for(i=0;i<N;i++)
        printf("%d\n",a[i]);
}

void Mergesort(int a[], int LB, int UB)
{
    int MID;
    MID=(LB+UB)/2;
    if(LB>=UB)
        return;

    Mergesort(a,LB,MID);
    Mergesort(a,MID+1,UB);
    simpleMerge(a,LB,UB,MID);

}
void simpleMerge(int a[],int LB,int UB, int MID)
{
    //printf("hi");
    int i,j,k;
    i=LB;
    j=MID+1;
    k=LB;
    int temp[10];
    while(i<=MID && j<=UB)
    {
        if(a[i] <= a[j])
        {
            temp[k]=a[i];
            i++;
        }
        else
        {
            temp[k]= a[j];
            j++;
        }
        k++;
    }
    if(i>MID)
    {
        while(j<=UB)
        {
            temp[k]= a[j];
            j++; k++;
        }
    }
    else
    {
        while(i<=MID)
        {
            temp[k]= a[i];
            i++; k++;
        }
    }
    for(i=LB;i<=UB;i++)
        a[i]=temp[i];
        for(i=LB;i<=UB;i++)
        printf("\t%d ",a[i]);
        printf("\n__");
}