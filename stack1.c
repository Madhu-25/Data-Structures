#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{
  int capacity;
  int size;
  int top;
  int arr[10];
}node;

node * initialize(int m){
  node * s=malloc(sizeof(node*));
  s->capacity=m;
  s->size=0;
  s->top=-1;
  return s;
}

void push(node *s, int elem)
{
  if(s->size==s->capacity)
  {
    printf("\nStack overflow");
    return;
  }
  s->arr[++s->top]=elem;
  s->size++;
}

int pop(node *s)
{
  if(s->size==0)
  {
    printf("\nStack is empty");
    return 0;
  }
  s->size--;
  int elem=s->arr[s->top--];
  return elem;

}

int peek(node *s)
{
  if(s->size==0)
  {
    printf("\nStack is empty");
    return 0;
  }
  int elem=s->arr[s->top];
  return elem;
}



int main(void) {
  node *s=initialize(7);
  push(s,1);
  push(s,2);
  push(s,3);
  printf("\n%d",peek(s));
  pop(s);
  printf("\n%d",peek(s));
  return 0;
}
