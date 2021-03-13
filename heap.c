#include <stdio.h>
#include<stdlib.h>
#define min 0
typedef struct priorityQ
{
  int size,capacity;
  int arr[20];

}heap;

heap * initialize(int max)
{
  heap *h=malloc(sizeof(struct priorityQ));
  h->capacity=max;
  h->size=0;
  h->arr[0]=min;
  return h;
}

int isFull(heap* h)
{
  return h->capacity==h->size;
}

int isEmpty(heap *h)
{
  return h->size==0;
}

void insert(heap *h , int elem)
{
  if(isFull(h))
  {
    printf("\nHeap full");
    return;
  }
  int i;
  for(i=++h->size; h->arr[i/2]>elem;i=i/2)
  {
    h->arr[i]=h->arr[i/2];

  }
  h->arr[i]=elem;
}

int dequeue(heap *h)
{
  if(isEmpty(h))
  {
    printf("\nHeap is empty");
    return -1;
  }
  int child,i;
  int x=h->arr[1];
  int last=h->arr[h->size--];
  for(i=1; (i*2)<=h->size; i=child)
  {
    child=i*2;
    if(child!=h->size && h->arr[child+1]<h->arr[child])
    {
      child+=1;
    }
    if(last>h->arr[child])
    {
      h->arr[i]=h->arr[child];
    }
    else
      break;
  }
  h->arr[i]=last;
  return x;
}

void print(heap *h)
{
  for(int i=1; i<=h->size;i++)
    printf("%d\t",h->arr[i]);
}

int main(void) {
  heap *h=initialize(10);
  insert(h, 5);
  insert(h,3);
  insert(h, 8);
  insert(h,2);
  insert(h ,10);
  print(h);
  printf("\n%d\n",dequeue(h));
  print(h);
  return 0;
}
