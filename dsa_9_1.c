//bubble sort
#include<stdio.h>
#include<conio.h>

int main()
{
    int k[10],N,i,temp;
    int LAST, EXCHS=1;

    printf("Enter no of elements : ");
    scanf("%d",&N);

    for(i=0;i<N;i++)
        scanf("%d",&k[i]);

    LAST=N-1;
    while(EXCHS)
    {
        EXCHS=0;
        for(i=0;i<=LAST-1;i++)
        {
            if(k[i]>k[i+1])
            {
                temp=k[i];
                k[i]=k[i+1];
                k[i+1]=temp;
                EXCHS++;
               
            }

        }
        if (EXCHS==0)
        {
            printf("Array already sorted....\n");
            break;
        }
        else
            LAST--;
    }

    printf("\n=======Sorted List=========\n");

    for(i=0;i<N;i++)
        printf("\t%d\n",k[i]);
}