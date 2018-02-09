#include <iostream>
// #include <math.h>
using namespace std;

// To execute C++, please define "int main()"

struct node{
  int data;
  node *left, *right;

};

struct node* newnode(int val){
  
  node *temp = new node;
  temp->data = val;
  temp->left = NULL;
  temp->right = NULL;
  return temp;

};


void inorder(node *root){
  if(root != NULL){
    inorder(root->left);
    cout<<root->data<<'\n';
    inorder(root->right);
  }
}

int bbt(node *leaf){
  if(leaf == NULL)
    return 0;
  int hl = bbt(leaf->left);
  if(hl == -1)
    return -1;
  int hr = bbt(leaf->right);
  if(hr == -1)
    return -1;
  
  if(abs(hr-hl) > 1)
    return -1;
  else 
    return (1+ max(hr,hl));

}



int main() {
  node *root = newnode(1);
  root->left = newnode(2);
  root->right = newnode(3);
  root->left->left = newnode(4);
  root->left->right = newnode(5);
  root->left->right->left = newnode(7);
  // root->left->left->left = newnode(10);
  root->right->right = newnode(6);
  // inorder(root);
  cout<<bbt(root);
  return 0;
}
