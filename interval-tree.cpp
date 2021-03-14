#include <iostream>
#include<cstdlib>
using namespace std;
struct Interval{
  int l;
  int h;
};

struct Node{
  Interval * i;
  int max;
  Node *right,*left;

};

Node* newNode(Interval * I)
{
  Node * n=(Node*)malloc(sizeof(struct Node));
  n->i= I;
  n->max=I->h;
  n->right=n->left=NULL;
  return n;

}

Node * insert(Node *root, Interval* I)
{
  if(root==NULL)
    return newNode(I);
  int val=root->i->l;
  if(I->l<val)
  {
    root->left=insert(root->left, I);
  }
  else
    root->right=insert(root->right, I);
  if(root->max<I->h)
    root->max=I->h;
  return root;
}


int overlap(Interval *I1, Interval *I2)
{
  return (I1->l<=I2->h && I2->l<=I1->h);
}

Interval * find(Node * root, Interval *I)
{
  if(root==NULL)
    return NULL;
  else if(overlap(root->i, I))
    return root->i;
  else if(root->left !=NULL && root->left->max>=I->l)
    return find(root->left, I);
  else
    return find(root->right,I);
}

void inorder(Node * root)
{
  if(root!=NULL)
  {
    inorder(root->left);
    cout << "[" << root->i->l<< ", " << root->i->h << "]" << " max = "<< root->max << endl;
    inorder(root->right);
  }
}


int main() {
  Node *root=NULL;
  cout <<"Enter interval values l and h (without ,)" <<endl;
  for(int j=0; j<7; j++)
  {
    Interval *i=(Interval*)malloc(sizeof(struct Interval));
   
    cin >> i->l >> i->h ;
    root=insert(root, i);

  }
  inorder(root);
  Interval *i=(Interval*)malloc(sizeof(struct Interval));
  i->l=16;
  i->h=17;
  Interval *result=find(root,i);
  if(result)
  {
    cout <<" Intersecting interval : [ " << result->l <<", "<<result->h<<" ]"<<endl;
  }
  return 0;
}
