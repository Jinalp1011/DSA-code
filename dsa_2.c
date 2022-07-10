#include<stdio.h>
#include<stdlib.h>
#define size 6
struct queue
{
    int f,r,arr[size];
}q;

void intialize(struct queue *q)
{
    q->f=0;
    q->r=0;
}

void enqueue(struct queue *q)
{
    if(q->r==size-1)
    {
        printf("This Queue is full!!");
    }
   int x;
   printf("Enter any number :");
   scanf("%d",&x);
   q->r++;
   q->arr[q->r]=x;

   if(q->f=0)
   {
       q->f++;
   }
        
}

int dequeue(struct queue *q)
{
    
    if(q->f==0 &&  q->r==0)
    {
        printf("This Queue is empty!!");
    }
    else
    {   
        if(q->f==q->r)
        {
            int temp;
            temp=q->arr[q->f];
            q->f=q->r=0;
            return temp;
        }
        else{
              int temp,arr[size];
              temp=arr[q->f];
              q->f++;

              return temp;
        }
            
    }
   
}

void display(struct queue *q)
{
    if(q->f==-1)
    {
        printf("Queue is underflow!!");
        return ;
    }
    printf("Item available!!");
    for(int i=q->f;i<=q->r;i++)
    {
        printf("%d\n",q->arr[i]);
    }

}

int main()
{
   int choice,m,x;
   printf("1)Enqueue\n");
   printf("2)Dequeue\n");
   printf("3)Display\n");
   printf("4)Exit\n");
   do
   {
       printf("Enter your choice : ");
       scanf("%d",&choice);
       switch(choice)
       {
           case 1:
                  enqueue(&q);
                  break;

           case 2:
                  m=dequeue(&q);
                  if(m==-1)
                  {
                      printf("Underflow!!");
                  }
                  else
                  {
                      printf("%d is deleted\n");
                  }
                  break;
            case 3:
                  display(&q);
                  break;
            case 4:
                   printf("Queue closed\n");
                   exit(1);
            default:
                   printf("Provide valid number please!!");
                   break;
       } 
   } while (choice != -1);
        return 0;
}


