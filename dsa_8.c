#include<stdio.h>
#include<stdlib.h>
#define MAX 10

void main()
{
    int a[MAX],i=10,ele,f=0;
    printf("\n Enter the search list (10 element):");
    for(i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
        printf("\n Enter element to be searched:");
        for(i=0;i<10;i++)
        {
            if(a[i]==ele)
            {
                f=1;
                break;
            }
        }
        if(f==0)
        printf("\n Element %d is not present",ele);
        else
        {
         printf("\n Element %d found at position %d",a[i],i);
        }
    }
}