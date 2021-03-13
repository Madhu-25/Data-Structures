#include <stdio.h>
#include <stdlib.h>
struct node{
  int data;
  struct node *next;
}*front=NULL,*rear=NULL;

void enqueue(int elem)
{
  struct node *ptr=malloc(sizeof(struct node*));
  ptr->data=elem;
  ptr->next=NULL;
  if(front==NULL)
  {
    rear=front=ptr;

  }
  else{
    rear->next=ptr;
    rear=ptr;
  }
}

int dequeue()
{
  if(front==NULL)
  {
    printf("\nEmpty queue");
    return -1;
  }
  int elem=front->data;
  front=front->next;
  return elem;
}

int main(void) {
  enqueue(1);
  enqueue(2);
  printf("\n%d",dequeue());
  enqueue(3);
  printf("\n%d",dequeue());
  //printf("\n%d %d",front->data,rear->data);
  dequeue();
  dequeue();
  return 0;
}
