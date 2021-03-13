#include <stdio.h>
#include<limits.h>
#define INF 99999
int min_dist(int dist[9], int spt[9])
{
  int min=INT_MAX;
  int min_index;
  for(int i=0; i<9; i++)
  {
    if(spt[i]==0 && dist[i]<min)
      min=dist[i], min_index=i;
  }
  return min_index;
}
void dijkstra(int graph[9][9], int src)
{
  int dist[9];
  int spt[9];
  for(int i=0; i<9; i++)
  {
    dist[i]=INT_MAX;
    spt[i]=0;
  }
  dist[src]=0;
  for(int count=0; count<8; count++)
  {
    int u=min_dist(dist,spt);
    spt[u]=1;
    for(int v=0; v<9; v++)
    {
      if(spt[v]==0 && graph[u][v]!=0 && dist[u]!=INT_MAX && dist[u]+graph[u][v] < dist[v])
      {
        dist[v]=dist[u]+graph[u][v];

      }
    }
    
  }
  printf("\nvertex\tDist from src\n");
  for(int i=0 ;i<9;i++)
  {
    printf("%d\t%d\n",i,dist[i]);
  }

}

void floyd(int graph[9][9])
{
  int dist[9][9];
  for(int i=0; i<9 ;i++)
  {
    for(int j=0; j<9; j++)
    {
      if(graph[i][j]==0)
        dist[i][j]=INF;
      else 
        dist[i][j]=graph[i][j];
      
    }
  }

  for(int k=0;k<9;k++)
  {
    for(int i=0; i<9;i++)
    {
      for(int j=0;j<9;j++)
      {
        if(dist[i][k]+dist[k][j]<dist[i][j])
          dist[i][j]=dist[i][k]+dist[k][j];

      }
    }
  }
  
  for(int i=0 ;i<9;i++)
  {
    for(int j=0; j<9; j++)
    {
      if(dist[i][j]==INT_MAX)
        printf("%7s   ","inf");
      else
        printf("%7d   ",dist[i][j]);
    }
    printf("\n");
  }
}

int main(void) {
  int graph[9][9]={ { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

  printf("\tDijkstra's Algorithm");
  dijkstra(graph,0);
  printf("\n\n\tFloyd-Warshall-Algorithm: \n");
  floyd(graph);

  return 0;
}
