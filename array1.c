#include<stdio.h>
#include<stdlib.h>
int main()
{
    int num[100],n,i,choice,max,min,avg,add,no;
    printf("Set a limit of an array :");
    scanf("%d",&n);
    printf("Enter elements of an array :\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    do{
    printf("\nChoices are :\n");
    printf("1. Find maximum number\n");
    printf("2. Find minimum number\n");
    printf("3. Find average\n");
    printf("4. Sort list of an array\n");
    printf("5. Insert a number at first position\n");
    printf("6. Insert a number at last position\n");
    printf("7. Insert a number at specific position\n");
    printf("8. Delete a number at first position\n");
    printf("9. Delete a number at last position\n");
    printf("10. Delete a number at specific position\n");
    printf("12. Display the list\n");
    printf("13. Exit\n");
    printf("Enter your choice :\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        {
             max=num[0];
            for(i=0;i<n;i++)
                {
                   if(max<num[i])
                        max=num[i];
                }
            printf("Maximum number among given array is %d\n",max);
            break;
        }
    case 2:
        {
             min=num[0];
            for(i=0;i<n;i++)
                {
                    if(min>num[i])
                        min=num[i];
                }
            printf("Minimum number among given array is %d\n",min);
            break;
        }
    case 3:
        {
            for(i=0;i<n;i++)
            {
                add+=num[i];
                avg=add/n;
            }
            printf("Average of the given numbers is %d\n",avg);
            break;
        }
    case 4:
        {
           int j,temp;
            printf("Sorting array in ascending and descending order :\n");
              for(i=0;i<n;i++)
            {
               for(j=i+1;j<n;j++)
                 {
                    if(num[i]>num[j])
                        {
                            temp=num[i];
                            num[i]=num[j];
                            num[j]=temp;
                        }
                 }
            }
            printf("Array sorted in ascending order :\n");
            for(i=0;i<n;i++)
                printf("%d\n",num[i]);
              for(i=0;i<n;i++)
            {
               for(j=i+1;j<n;j++)
                {
                   if(num[i]<num[j])
                     {

                             temp=num[i];
                             num[i]=num[j];
                             num[j]=temp;
                     }

                }
            }
            printf("Array sorted in descending order :\n");
            for(i=0;i<n;i++)
                printf("%d\n",num[i]);

            break;
        }
    case 5:
        {
            int j;
            printf("Enter a new number at first position: \n");
            scanf("%d",&j);
            for(i=n;i>=0;i--) //2>=0
            {
                num[i+1]=num[i]; //2+1=3
            }
            num[0]=j;
            n++;
            printf("Number inserted \n");
           /* for(i=0;i<=n;i++)
            {
                printf("%d\n",num[i]);
            }*/
            break;
        }
    case 6:
        {
            int j;
            printf("Enter a new number at last position :\n");
            scanf("%d",&j);
            num[n]=j;
            n++;
            printf("Number inserted \n");
            // printf("%d\n",num[]);
           /* for(i=0;i<=n;i++)
            {
                printf("%d\n",num[i]);
            }*/
            break;
        }
    case 7:
        {   int j;
            printf("Give a position for a new number :\n");
            scanf("%d",&no);
            printf("Enter a new number:\n");
            scanf("%d",&j);
            for(i=n;i>=no-1;i--)  //i=4-1=3;3>2;3--=2
            {
                num[i+1]=num[i]; //num[4]=num[3]
            }
            num[no-1]=j;
            n++;
            printf("Number inserted \n");
           /* for(i=0;i<=n;i++)
            {
                printf("%d\n",num[i]);
            }*/
            break;
        }
    case 8:
        {
            for(i=0;i<n;i++) //1<4
            {
                num[i]=num[i+1]; //
            }
            n--;
            printf("Number deleted \n");
           /* for(i=0;i<n-1;i++)
            {
                printf("%d\n",num[i]);
            }*/
            break;
        }
    case 9:
        {
            n--;
            printf("Number is deleted \n");
           /* for(i=0;i<n-1;i++)
            {
                printf("%d\n",num[i]);
            }*/
            break;
        }
    case 10:
        {
            printf("Give a position to delete a number :\n");
            scanf("%d",&no); //4
            for(i=no-1;i<n;i++) //i=4-1=3;3<=4
            {
                num[i]=num[i+1]; //
            }
            n--;
            printf("Number deleted \n");
           /* for(i=0;i<n-1;i++)
            {
                printf("%d\n",num[i]);
            }*/
            break;
        }
    case 12:
        {
            printf("New array is :\n");
            for(i=0;i<n;i++)
                printf(" %d ",num[i]);
            break;
        }
    case 13:
        {
            exit(1);
            break;
        }
    }
    }while(choice!=13);
    return 0;
}