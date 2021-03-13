#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
  char *name;
  struct node *left,*right;
}bst;

bst * empty(bst *t)
{
  if(t!=NULL)
  {
    empty(t->left);
    empty(t->right);
    free(t);
  }
  return NULL;
}

bst * find(bst *t, char str[])
{
  if(t==NULL){
    return NULL;
  }
  if(strcmp(str,t->name)<0)
  {
    return find(t->left,str);
  }
  else if(strcmp(str,t->name)>0)
  {
    return find(t->right,str);
  }
  else{
    return t;
  }
}

bst * findmin(bst *t)
{
  if(t==NULL)
  {
    return NULL;
  }
  else if(t->left==NULL)
  {
    return t;
  }
  else 
    return findmin(t->left);
}

bst * findmax(bst *t)
{
  if(t==NULL)
    return NULL;
  else if(t->right==NULL)
    return t;
  else
    return findmax(t->right);
}

bst * insert(bst *t, char str[30])
{
  if(t==NULL)
  {
  
    t=malloc(sizeof(bst*));
    if(t==NULL)
    {
      printf("\nError");
      return NULL;
    }
    
    t->name=(char*)malloc(sizeof(char)*20);
    strcpy(t->name,str);
   
    t->right=NULL;
    t->left=NULL;

  }
  else if(strcmp(str,t->name)<0)
  {
    
    t->left=insert(t->left,str);
  }
  else if(strcmp(str, t->name)>0)
  {
    
    t->right=insert(t->right, str);
  }
  return t;
}

bst * delete1(bst * t, char str[])
{
  bst * temp;
  if(t==NULL)
  {
    printf("\nError");
    return NULL;
  }
  else if(strcmp(str,t->name)<0)
    t->left= delete1(t->left, str);
  else if(strcmp(str,t->name)>0)
    t->right= delete1(t->right, str);
  else if(t->left && t->right)
  {
    temp=findmin(t->right);
    strcpy(t->name,temp->name);
    t->right=delete1(t->right,temp->name);
  }
  else{
    temp=t;
    if(t->left==NULL)
      t=t->right;
    else if(t->right==NULL)
      t=t->left;
    free(temp);

  }
  return t;
}

void display(bst *t)
{
  if(t==NULL)
    return;
  display(t->left);
  printf("\n%s",t->name);
  display(t->right);

}

int main()
{
  bst *t=NULL;
  t=insert(t,"john");
  t=insert(t,"emily");
  t=insert(t,"sandra");
  t=insert(t,"keanu");

  display(t);

  

}
