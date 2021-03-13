#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"
queue *q;
node *s;
node * init(int m);
queue * initialize(int m);

void bfs(int arr[9][9], int src)
{
  enqueue(q,src);
  int visited[9] = {0,0,0,0,0,0,0,0,0};
  visited[src]=1;
  
  while(!isEmpty(q))
  {
    int p=dequeue(q);
    
    printf("%5d",p);
    for(int i=0;i<9;i++)
    {
      if(arr[p][i]!=0 && visited[i]==0)
      {
        enqueue(q,i);
        visited[i]=1;

      }
    }
  }
}

void dfs(int arr[9][9], int src)
{
  int p;
  push(s,src);
  int visited[9] = {0,0,0,0,0,0,0,0,0};
  visited[src]=1;
  while(s->size!=0)
  {
    p=pop(s);
    printf("%5d",p);
    for(int i=0; i<9; i++)
    {
      if(arr[p][i]!=0 && visited[i]==0)
        push(s,i), visited[i]=1;
      
    }

  }
  


}





int main(void)
{
  int graph[9][9]={ { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
  q=initialize(9);
  s=init(9);

  printf("\n\tBFS\n");
  bfs(graph,0);
  printf("\n\n\tDFS\n");
  dfs(graph,0);

  

  return 0;
}
