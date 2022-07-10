   #include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main()
{
    int s[6],top=-1,choice,val,i;
    do{
        printf("STACK OPERATIONS\n");
        printf("1)PUSH\n");
        printf("2)POP\n");
        printf("3)PEEK\n");
        printf("4)CHANGE\n");
        printf("5)DISPLAY\n");
        printf("6)EXIT\n");

        printf("Enter your choice:\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: 
               if(top==5)
                   printf("Stack is overflow\n\n");
               else
               {
                   printf("Enter value:");
                   scanf("%d",&val);
                   top=top+1;
                   s[top]=val;
                   printf("%d\n",top);
                   printf("Number inserted\n");
               }
               break;
            case 2:
               if(top==-1)
                  printf("Stack is underflow\n\n");
                else
                {
                   printf("Delete the element %d\n",s[top]);
                  top--;
                }
                break;
            case 3:
                  printf("Enter the position:\n");
                  scanf("%d",&i);
                if(top-i+1<0)
                  printf("Stack is underflow\n");
                else
                  {
                      val=s[top-i+1];
                      printf("The value of the element is = %d",val);
                  }
                  break;
            case 4:
                 printf("Enter the position:\n");
                  scanf("%d",&i);
                if(top-i+1<0)
                  printf("Stack is underflow\n");
                else
                {
                    printf("Enter value:");
                    scanf("%d",&val);
                    s[top-i+1]=val;
                }
                break;
            case 5:
                if(top<0)
                   printf("Stack is underflow\n");
                else
                {
                    for(i=top;i>=0;i--)
                       printf("\t%d\n",s[i]);
                }
                printf("\n");
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid input");
                 

                 
        }
        
    }
    while(choice!=0);
    return 0;
}