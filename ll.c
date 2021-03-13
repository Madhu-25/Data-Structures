#include <stdio.h>
#include <stdlib.h>
typedef struct linkedlist{
  int data;
  struct linkedlist *next;
}node;
void insert(node *h, int item)
{
  node *t=malloc(sizeof(node*));
  t->data=item;
  t->next=NULL;
  if(h->next==NULL)
  {
  h->next=t;
  t->next=NULL; 
  }
  else{
    node *temp = h;
    while(temp->next!=NULL)
    {
      temp=temp->next;
    }
    temp->next=t;
    h=temp;
  }
  
}

void delete1(node *head, int data)
{
  node * temp=head;
  while(temp->next!=NULL)
  {
    if(temp->next->data==data)
    {
      printf("\nRecord found and deleted");
      temp->next=temp->next->next;
      break;
    }
    temp=temp->next;
  }
  head=temp;
}

void display(node *head)
{
  node *temp = head;
  while(temp->next!=NULL)
  {
    printf("\n%d",temp->next->data);
    temp=temp->next;
  }
}

int main(void) {
  node *head;
  head=(node*)malloc(sizeof(node*));
  insert(head, 3);
  insert(head , 7);
  insert(head, 10);
  insert(head, 33);
  display(head);
  delete1(head, 7);
  display(head);

  return 0;
}
