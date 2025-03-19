#include<stdio.h>

#include<stdlib.h>

//Node Structure
struct Node{
  int data;
  struct Node* next;
};

//Function to insert a new node at the end
void insertEnd(struct Node** head,int data)
{
  struct Node*new_node=(struct Node*)malloc(sizeof(struct Node));
  new_node->data=data;
  new_node->next=NULL;

  if(*head==NULL)
  {
   *head=new_node;
  }
  else
  {
  struct Node*temp=*head;
  while(temp->next !=NULL)
  {
  temp=temp->next;
  }
  temp->next=new_node;
  }
  printf("Element %d inserted at the end.\n",data);
}


// Function to insert at the beginning
void insertBeginning(struct Node** head,int data)
{
  struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
  new_node->data=data;
  new_node->next=*head;
  *head=new_node;
  printf("Element %d inserted ath the beginning.\n",data);
}

//Function to insert at a specific position
void insertAtPosition(struct Node**head,int data,int position,int i)
{
  struct Node*new_node=(struct Node*)malloc(sizeof(struct Node));
  new_node->data=data;

  if (position == 1)
  {
    new_node->next=*head;
    *head=new_node;
    printf("Element %d inserted at position %d.\n",data,position);
    return;
  }

  struct Node* temp=*head;
  for(int i=1;temp!=NULL&&i<position-1;i++)
  {
   temp=temp->next;
  }

if(temp==NULL)
 {
 printf("Position out of range.Inserting element %d at the end.\n",data);
 insertEnd(head,data);
 }
 else
 {
 new_node->next= temp->next;
 temp->next= new_node;
 printf("Element %d inserted at position %d.\n",data,position);
 }
}

 //Function to display the linked list
void display(struct Node* head)
{
  if (head==NULL)
  {
  printf("List is empty. \n");
  return;
  }
  struct Node*temp=head;
  while(temp!=NULL)
  {
  printf("%d->",temp->data);
  temp=temp->next;
  }
 printf("NULL \n");
}

void main()
{
  struct Node*head=NULL;
  int choice,value,pos,i;
  clrscr();

  while(choice<=3)
  {
  printf("menu:\n");
  printf("1.Insert at the end\n");
  printf("2.Insert ath the beginning \n");
  printf("3.Display list \n");
  printf("Exit.\n");
  printf("Enter your choice");
  scanf("%d",&choice);
  switch(choice)
  {
  case 1:
  printf("Enter an element to insert at the end:");
  scanf("%d",&value);
  insertEnd(&head,value);
  break;

  case 2:
    printf("Enter an element to insert at the beginning:");
    scanf("%d",&value);
    insertBeginning(&head,value);
    break;

  case 3:
    printf("Enter an element to insert at a specific position:");
    scanf("%d",&value);
    printf("Enter the position:");
    scanf("%d",&pos_);
    insertAt Position(&head,value,pos);


  case 7:
    printf("Linkd List:");
    display(head);
    break;

  case 8:
    printf("Exiting the program.\n");
    break;
    default:
    printf("Invalid choice!Please try again.\n");
    }
    }
 while(choice!=8);

 return 0;
}