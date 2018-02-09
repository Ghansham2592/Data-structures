#include <iostream>
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
    // return;
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
  }
}





int main() {
  node *root = newnode(1);
  root->left = newnode(2);
  root->right = newnode(5);
  root->left->left = newnode(3);
  root->left->left->left = newnode(4);
  root->right->right = newnode(6);
  root->right->right->right = newnode(7);

  // node *root = newnode(1);
  // root->left = newnode(2);
  // root->right = newnode(3);
  // root->left->left = newnode(4);
  // root->left->right = newnode(5);
  // root->left->right->left = newnode(7);
  // // root->left->left->left = newnode(10);
  // root->right->right = newnode(6);
  inorder(root);
  return 0;
}
