#include <stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *next;
}*top=NULL;

void push( int elem)
{
  struct node *s=malloc(sizeof(struct node*));
  s->data=elem;
  if(top==NULL)
  {
    s->next=NULL;
  }
  else{
    s->next=top;
  }
  top=s;
}

int pop()
{
  if(top==NULL)
  {
    printf("\nStack is empty");
    return -1;
  }
  int elem=top->data;
  top=top->next;
  return elem;
}

int peek()
{
  if(top==NULL)
  {
    printf("\nStack is empty");
    return -1;
  }
  int elem=top->data;
  return elem;
}

int main(void) {
  push(5);
  push(4);
  push(3);
  printf("\n%d",peek());
  pop();
  printf("\n%d",peek());
  return 0;
}
