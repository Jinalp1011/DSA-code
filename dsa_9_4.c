//selection sort
#include<stdio.h>
#include<conio.h>

int main()
{
    int k[10],N,i,temp;
    int j,min_ind;
    printf("Enter no of elements : ");
    scanf("%d",&N);

    for(i=0;i<N;i++)
        scanf("%d",&k[i]);


    for (i = 0; i < N-1; i++)
    {
        // Find the minimum element in unsorted array
        min_ind = i;
        for (j = i+1; j < N; j++)
        {
            if (k[j] < k[min_ind])
            min_ind = j;
        }

        temp= k[min_ind];
        k[min_ind] = k[i];
        k[i]=temp;
    }

    printf("\n=======Sorted List=========\n");

    for(i=0;i<N;i++)
        printf("\t%d\n",k[i]);
}