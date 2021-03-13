#include <stdio.h>
#include <stdlib.h>
typedef struct dll{
  int data;
  struct dll *next;
  struct dll *prev;
}node;

void addbeg(node *head, int elem)
{
  node *t=malloc(sizeof(node*));
  t->data=elem;
  if(head->next==NULL)
  {
    head->next=t;
    t->next=NULL;
    t->prev=head;
    head->prev=NULL;
    return;
  }
  head->next->prev=t;
  t->next=head->next;
  head->next=t;
  t->prev=head;
}

void add(node *head, int elem, int pos)
{
  node *ptr=head;
  for(int i=1; i<pos; i++)
  {
    ptr=ptr->next;
  }
  node *t=malloc(sizeof(node*));
  t->data=elem;
  ptr->next->prev=t;
  t->next=ptr->next;
  ptr->next=t;
  t->prev=ptr;

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
  addbeg(head,8);
  addbeg(head,9);
  addbeg(head, 10);
  addbeg(head, 4);
  add(head,90,2);
  delete1(head,9);
  display(head);
  return 0;
}
