#include <stdio.h>
#include<stdlib.h>
#define key 10


int hash_func(int x)
{
  return (x%key);
}

typedef struct hash{
  int data;
  struct hash *next;
}record;

int find(record * table[] , int x);

void insert(int id, record *table[])
{
  int h;
  record *temp;
  if(find(table,id)!=-1)
  {
    printf("\nDuplicate key");
    return;
  }
  h=hash_func(id);
  temp=malloc(sizeof(record*));
  temp->data=id;
  temp->next=table[h];
  table[h]=temp;

}

int find(record * table[] , int x)
{
  int h;
  record *ptr;
  h=hash_func(x);
  ptr=table[h];
  while(ptr!=NULL)
  {
    if(ptr->data==x)
    {
      return h;
    }
    ptr=ptr->next;
  }
  return -1;
}

void deleteKey(record *table[], int x)
{
  int h;
  h=hash_func(x);
  record *temp;
  if(table[h]==NULL)
  {
    printf("\nKey not found");
    return;
  }
  if(table[h]->data==x)
  {
    temp=table[h];
    table[h]=table[h]->next;
    free(temp);
    return;
  }
  record *ptr;
  ptr=table[h];
  while(ptr->next!=NULL)
  {
    if(ptr->next->data==x)
    {
      temp=ptr->next;
      ptr->next=temp->next;
      free(temp);
      return;
    }
    ptr=ptr->next;

  }
  printf("\nKey not found");
}

void print(record *table[])
{
  printf("\nKEY\t\tELEMENTS");
  for(int i=0; i<key; i++)
  {
    if(table[i]!=NULL)
    {
      printf("\n%d\t",i);
      record *ptr=table[i];
      while(ptr!=NULL)
      {
        printf("%5d",ptr->data);
        ptr=ptr->next;
      }
    }
    
  }
}
int main(void) {
  record *table[key];
  for(int i=0;i<key;i++)
  {
    table[i]=NULL;
  }
  insert(1,table);
  insert(2,table);
  insert(14,table);
  insert(21,table);
  print(table);
  deleteKey(table, 21);
  print(table);
  insert(14, table);
  return 0;
}
