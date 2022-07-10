#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#define N 5
int main()
{
	int q[N],val,op,i,j,k,front=-1,rear=-1,flag=0;

	do
	{
		printf("\nCIRCULAR QUEUE OPERATION \n");
		printf("\n1-CEnqueue \n2-CDqueue \n3-DISPLAY \n4-SEARCH \n5-EXIT \n");
		printf("\nSELECT OPERATION :- ");
		scanf("%d",&op);

		switch(op)
		{

		   case 1:

			if(rear>=N-1)
			{
				rear=0;
			}
			else
			{
				rear++;
			}
			if(rear==front)
			{
				if(rear==-1)
					rear=N-1;

				else
				{
					rear--;
				}
				printf("\nQUEUE OVERFLOW");
				break;
			}
			printf("ENTER VALUE TO PERFORM PUSH OPERATION :- ");
			scanf("%d",&val);
			q[rear]=val;
			printf("VALUE INSERTED...");
			if(front==-1)
				front=0;
			break;

		  case 2:
			if(front==-1)
			{
				printf("\nQUEUE UNDERFLOW");
			}
			else
			{
				val=q[front];

				if(front==rear||front==N-1)
				{
					front=-1;
					rear=-1;
				}
				else
				{
					front++;
				}
				printf("\nPOPED ELEMENT :-%d",val);
			}
			break;

		   case 3:
			printf("front=%d   rear=%d",front,rear);
			if(front==-1)
			{
				printf("\nQUEUE IS EMPTY");
			}
			else
			{

				printf("\nNOW QUEUE IS :-\n");
				printf("\n front->");


				if(front>rear)
				{
				    for(k=front;k<=N-1;k++)
					{
						printf("%d\n",q[k]);
						printf("\t");

					}
					for(j=0;j<=rear;j++)
					{
						printf("%d\n",q[j]);
						printf("\t");
					}

				}
				else
				{
					for(i=front;i<=rear;i++)
					{
						printf("%d\n",q[i]);
						printf("\t");
					}

			   }
			   }
			break;

		   case 4:
                printf("Enter any no to search in Queue : ");
                scanf("%d",&val);
                if(front==-1)
                {
                    printf("\nQUEUE IS EMPTY");
                }
                else
                {
                    if(front>rear)
                    {
                        for(k=front;k<=N-1;k++)
                        {
                            if (q[k]==val)
                            {
                                printf("The element found\n");
                                break;
                            }
                        }
                        for(j=0;j<=rear;j++)
                        {
                            if (q[j]==val)
                            {
                                printf("The element found\n");
                                break;
                            }
                        }

                    }
                    else
                    {
                        for(i=front;i<=rear;i++)
                        {
                            if (q[i]==val)
                              {
                                printf("The element found\n");
                                break;
                            }
                        }
                    }

			   }

			break;
           case 5:
		        //exit(0);
            break;
		   default:
			printf("\nINVALID CHOICE FOR OPERATION");
			break;

		}
	}while(op!=5);

}