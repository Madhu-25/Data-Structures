#include <stdio.h>
#include <stdlib.h>
typedef struct node{
  int front,rear,size,capacity, *arr;
}queue;

queue * initialize(int max)
{
  queue *q=malloc(sizeof(queue*));
  q->capacity=max;
  q->front=0;
  q->rear=max-1;
  q->size=0;
  q->arr=(int*)malloc(sizeof(int)*max);
  return q;
}

int isFull(queue *q)
{
  if(q->size==q->capacity)
  {
    return 1;
  }
  return 0;
}

int isEmpty(queue *q)
{
  if(q->size==0)
  {
    return 1;
  }
  return 0;
}
void enqueue(queue *q, int elem)
{
  if(isFull(q))
  {
    printf("\nQueue full");
    return;
  }
  q->size++;
  q->rear=(q->rear+1)%q->capacity;
  q->arr[q->rear]=elem;

}

int dequeue(queue *q)
{
  if(isEmpty(q))
  {
    printf("\nQueue empty");
    return -1;
  }
  q->size--;
  int elem=q->arr[q->front];
  q->front=(q->front+1)%q->capacity;
  return elem;
}