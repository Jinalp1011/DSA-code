#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev,*next;
};
struct node *head;

void beginsert();
void lastinsert();
void display();
void insertAt();
void deleteAt();

void main()
{
    int choice =999;
    head=NULL;
    while(choice != 0)
    {
        printf("\n\n****Main Menu****\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.Insert in beginning\n2.Insert at last\n3.Insert after specific KEY\n4.Delete a specific KEY \n5.Display /Traverse\n0.Exit\n");
        printf("\nEnter your choice = ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                beginsert();
            break;
            case 2:
                lastinsert();
            break;
            case 3:
                insertAt();
            break;
            case 4:
                deleteAt();
            break;
            case 5:
                display();
            break;
            case 0:
                exit(0);
            break;
            default:
            printf("Please enter valid choice..");
        }
    }
}
void beginsert()
{
    struct node *ptr;
    int item;
    ptr = (struct node *) malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter value = ");
        scanf("%d",&item);
        ptr->data = item;
        if(head!=NULL)
               head->prev=ptr;
               ptr->data=item;
               ptr->prev=NULL;
               ptr->next = head;
               head=ptr;
    }

}

void lastinsert()
{
    struct node *ptr,*temp;
    int item;
    ptr = (struct node *) malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter value = ");
        scanf("%d",&item);
        ptr->data = item;
        ptr->prev=ptr->next=NULL;
        if(head == NULL)
        {
            head = ptr;
            printf("\nNode inserted");
        }
        else
        {
                temp = head;
                while (temp -> next != NULL)
                {
                    temp = temp -> next;
                }
                temp->next = ptr;
                ptr->prev=temp;
                ptr->next = NULL;
                printf("\nNode inserted");
        }
    }
}
void insertAt()
{
    struct node *ptr,*temp;
    int item,key;
    ptr = (struct node *) malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter Key value=");
        scanf("%d",&key);

        ptr->data = item;
        ptr->prev=ptr->next=NULL;
        temp = head;
        while(temp->data!= key && temp!=NULL)
        {
        //    printf("%d\n",temp->data);
            temp = temp->next;
        }
        if(temp==NULL && temp->data!= key)
            printf("Key not found\n");
        else
        {
                printf("\nEnter element value = ");
                scanf("%d",&item);
                ptr->data = item;
                ptr->prev=temp;
                ptr->next=temp->next;
                temp->next=ptr;
                printf("\nNode inserted");
        }
    }
}
void deleteAt()
{
    struct node *ptr, *temp,*temp1;
    int val;
    printf("Enter the KEY value = ");
    scanf("%d",&val);
    temp = head;
    if(head -> data == val) //First node
    {
        head=temp->next;
        temp1=temp->next;
        temp1->prev=NULL;
        free(temp);
        printf("\nNode deleted....\n");
    }
    else
    {
        while(temp -> data != val && temp!=NULL)
            temp = temp -> next;
        if(temp -> data != val && temp==NULL)
                printf("\nKey not found...");
        else
        {
                if(temp->next != NULL)
                {
                    ptr = temp -> prev;
                    temp -> next->prev = ptr;
                    ptr -> next = temp->next;
                }
                else
                {
                    ptr = temp -> prev;
                    ptr -> next = NULL;
                }
                free(temp);
                printf("\nNode Deleted\n");
                }
    }
}
void display()
{
    struct node *ptr;
    if (head==NULL)
        printf("\nList is Empty.\n");
    else
    {
        ptr=head;
        while (ptr!=NULL)
        {
            printf("\t%d\n",ptr->data);
            ptr=ptr->next;
        }
    }
}