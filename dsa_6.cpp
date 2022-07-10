#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *head;

void beginsert ();
void lastinsert ();
void randominsert();
void begin_delete();
void last_delete();
void random_delete();
void insert_loc();
void display();
void search();
void reverse();
void sort();
int main ()
{
    int choice =999;
    while(choice != 0)
    {
        cout<<"\n\n****Main Menu****\n";
        cout<<"\nChoose one option from the following list ...\n";
        cout<<"\n===============================================\n";
        cout<<"\n1.Insert in beginning\n2.Insert at last\n3.Insert at after node having value KEY \n4.Delete from Beginning\n5.Delete from last\n6.Delete node having value KEY \n7.Search for an element\n8. Insert at location\n9.Reverse\n10.Sort\n11.Display /Traverse\n0.Exit\n";
        cout<<"\nEnter your choice = ";
        cin>>choice;

        switch(choice)
        {
            case 1:
            beginsert();
            break;
            case 2:
            lastinsert();
            break;
            case 3:
            randominsert();
            break;
            case 4:
            begin_delete();
            break;
            case 5:
            last_delete();
            break;
            case 6:
            random_delete();
            break;
            case 7:
            search();
            break;
            case 8:
            insert_loc();
            break;
            case 9:
            reverse();
            break;
            case 10:
            sort();
            break;
            case 11:
            display();
            break;
            case 0:
            exit(0);
            break;
            default:
            cout<<"Please enter valid choice..";
        }
    }
}
void beginsert()
{
    struct node *ptr;
    int item;
//    ptr = (struct node *) malloc(sizeof(struct node ));
    ptr =new struct node;

    if(ptr == NULL)
    {
        cout<<"\nOVERFLOW";
    }
    else
    {
        cout<<"\nEnter value = ";
        cin>>item;
        ptr->data = item;
        ptr->next = head;
        head = ptr;
        cout<<"\nNode inserted";
    }

}
void lastinsert()
{
    struct node *ptr,*temp;
    int item;
    //ptr = (struct node*)malloc(sizeof(struct node));
    ptr = new struct node;
    if(ptr == NULL)
    {
        cout<<"\nOVERFLOW";
    }
    else
    {
        cout<<"\nEnter value = ";
        cin>>item;
        ptr->data = item;
        if(head == NULL)
        {
            ptr -> next = NULL;
            head = ptr;
            cout<<"\nNode inserted";
        }
        else
        {
            temp = head;
            while (temp -> next != NULL)
            {
                temp = temp -> next;
            }
            temp->next = ptr;
            ptr->next = NULL;
            cout<<"\nNode inserted";

        }
    }
}
void randominsert()
{
    int i,key,item,loc;
    struct node *ptr, *temp,*old;
    ptr = (struct node *) malloc (sizeof(struct node));
    cout<<"\nEnter the KEY after which you want to insert = ";
    cin>>key;
    if(ptr == NULL)
    {
        cout<<"\nOVERFLOW";
    }
    else
    {
        temp = head;
        while(temp->data!= key && temp->next!=NULL)
        {
            temp=temp->next;
        }
        if(temp->next==NULL)
            cout<<"Key not found\n";
        else
        {
                cout<<"\nEnter element value = ";
                cin>>item;
                ptr->data = item;
                ptr->next=temp->next;
                temp->next=ptr;
        }
    }
}
void insert_loc()
{
    int i,item,loc;
    struct node *ptr, *temp,*old;
    //ptr = (struct node *) malloc (sizeof(struct node));
    ptr= new node();
    cout<<"\nEnter the location where you want to insert = ";
    cin>>loc;
    cout<<"\nEnter element value = ";
    cin>>item;
    ptr->data = item;
    ptr->next=NULL;
    if(ptr == NULL)
    {
        cout<<"\nOVERFLOW";
    }
    else if (loc==1)
    {
        ptr->next=head;
        head=ptr;
    }
    else
    {
        temp = head;
        while((--loc)>1)
        {
            temp=temp->next;
        }
        if(temp==NULL)
            cout<<"Key not found\n";
        else
        {

                ptr->next=temp->next;
                temp->next=ptr;
        }

    }
}
void begin_delete()
{
    struct node *ptr;
    if(head == NULL)
    {
        cout<<"\nList is empty\n";
    }
    else
    {
        ptr = head;
        head = ptr->next;
        free(ptr);
        cout<<"\nNode deleted from the begining ...\n";
    }
}
void last_delete()
{
    struct node *ptr,*temp;
    if(head == NULL)
    {
        cout<<"\nlist is empty";
    }
    else if(head -> next == NULL)
    {
        head = NULL;
        free(head);
        cout<<"\nOnly node of the list deleted ...\n";
    }
    else
    {
        ptr = head;
        temp=ptr->next;
        while(ptr->next->next != NULL)
        {
                temp=ptr->next;
                ptr = ptr ->next;
        }
        ptr->next = NULL;
        temp=temp->next;
        free(temp);
        cout<<"\nDeleted Node from the last ...\n";
    }
}
void random_delete()
{
    struct node *ptr,*ptr1;
    int loc,i,key;

    cout<<"Enter Key which you want to delete : ";
    cin>>key;
    ptr=ptr1=head;
    if (head->data==key)
        head=head->next;
    else
    {
        while(ptr->data!=key && ptr->next!=NULL)
        {
            ptr1=ptr;
            ptr=ptr->next;
        }
        if(ptr==NULL)
            cout<<"\nKey not found.\n";

        else
        {
            ptr1->next=ptr->next;
            free(ptr);
        }
    }

    /*printf("\n Enter the location of the node after which you want to perform deletion \n");
    scanf("%d",&loc);
    ptr=head;
    for(i=0;i<loc;i++)
    {
        ptr1 = ptr;
        ptr = ptr->next;

        if(ptr == NULL)
        {
            printf("\nCan't delete");
            return;
        }
    }
    ptr1 ->next = ptr ->next;
    free(ptr);
    printf("\nDeleted node %d ",loc+1);
    */
}
void search()
{
    struct node *ptr;
    int key,i=0,flag;
    ptr = head;
    if(ptr == NULL)
    {
        cout<<"\nEmpty List\n";
    }
    else
    {
        cout<<"\nEnter item which you want to search?\n";
        cin>>key;
        while(ptr->data!=key  && ptr!=NULL)
        {
            i++;
            ptr=ptr->next;
        }
        if(ptr == NULL)
            cout<<"Item not found\n";
        else
            cout<<"\nKEY found at location :"<<i+1;
    }

}
void reverse()
{
    struct node *prev, *curr, *next;
    curr=head;
    prev=next=NULL;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head=prev;
}
void sort()
{
    struct node *ptr,*lptr=NULL;
    int swapped=0;
     do
        {
            swapped = 0;
            ptr = head;

            while (ptr->next != lptr)
            {
                if (ptr->data > ptr->next->data)
                {
                    int temp = ptr->data;
                    ptr->data = ptr->next->data;
                    ptr->next->data = temp;
                    swapped = 1;
                }
                ptr = ptr->next;
            }
            lptr = ptr;
        }
        while (swapped);
}
void display()
{
    struct node *ptr;
    ptr = head;
    if(ptr == NULL)
    {
        cout<<"No data found\n\n";
    }
    else
    {
        cout<<"\nprinting values . . . . .\n";
        while (ptr!=NULL)
        {
            cout<<ptr->data<<"\t";
            ptr = ptr -> next;
        }
    }
}