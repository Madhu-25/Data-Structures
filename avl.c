#include <stdio.h>
#include<stdlib.h>
typedef struct node{
  int data;
  struct node *left,*right;
  int height;
}avl;

int max(int a, int b)
{
  if(a>b)
    return a;
  return b;
}

int height(avl *t)
{
  if(t==NULL)
    return -1;
  return t->height;
}

avl * singlerotatewithleft(avl *k2)
{
  avl* k1=k2->left;
  k2->left=k1->right;
  k1->right=k2;
  k2->height=max(height(k2->left),height(k2->right))+1;
  k1->height=max(height(k1->left),height(k1->right))+1;
  return k1;
}

avl * singlerotatewithright(avl *k2)
{
  avl *k1=k2->right;
  k2->right=k1->left;
  k1->right=k2;
  k2->height=max(height(k2->left),height(k2->right))+1;
  k1->height=max(height(k1->left),height(k1->right))+1;
  return k1;

}

avl * doublerotatewithleft(avl *k3)
{
  k3->left=singlerotatewithright(k3->left);
  return singlerotatewithleft(k3);

}

avl * doublerotatewithright(avl *k3)
{
  k3->right=singlerotatewithleft(k3->right);
  return singlerotatewithright(k3);
}

avl * insert(avl* t, int elem)
{
  if(t==NULL)
  {
    t=malloc(sizeof(struct node));
    if(t==NULL)
    {
      printf("\nerror");
      return NULL;
    }
    t->data=elem;
    t->height=0;
    t->left=t->right=NULL;
  }
  else if(elem<t->data)
  {
    t->left=insert(t->left,elem);
    if(height(t->left)-height(t->right)==2)
    {
      if(elem<t->left->data)
        t=singlerotatewithleft(t);
      else
        t=doublerotatewithleft(t);

    }
  }
  else if(elem>t->data)
  {
    t->right=insert(t->right,elem);
    if(height(t->right)-height(t->left)==2)
    {
      if(elem>t->right->data)
        t=singlerotatewithleft(t);
      else
        t=doublerotatewithright(t);
    }
  }
  t->height=max(height(t->left),height(t->right))+1;
  return t;
}

void inorder(avl *t)
{
	if(t==NULL)
		return;
	inorder(t->left);
	printf("%d\t",t->data);
	inorder(t->right);
}

void search(avl *t, int elem)
{
  if(t!=NULL)
  {
    if(elem<t->data)
      search(t->left,elem);
    else if(elem>t->data)
      search(t->right,elem);
    else{
      printf("\nElement found : %d",t->data);
    }
  }
  else{
    printf("\nError elemet not in record");
  }
}


int main(void) {
  avl *t=NULL;
  t=insert(t,5);
  t=insert(t,9);
  t=insert(t,4);
  t=insert(t,1);
  inorder(t);
  search(t,5);
  search(t,10);
  return 0;
}
