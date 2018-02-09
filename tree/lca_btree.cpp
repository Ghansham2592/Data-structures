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
    inorder(root->left);
    cout<<root->data<<'\n';
    inorder(root->right);


  }
}

node*  lca(node *leaf , node *a, node *b){
  if(leaf == NULL)
    return NULL;

  if (leaf == a || leaf == b){
    return leaf;
  }
  
  node *left = lca(leaf->left, a, b);
  node *right = lca(leaf->right, a, b);
  
  if(left != NULL && right != NULL)
    return leaf;
  
  if (left == NULL)
    return right;
  else
    return left;

}



int main() {
  node *root = newnode(46);
  root->left = newnode(3);
  root->right = newnode(4);
  root->left->left = newnode(9);
  root->left->left->left = newnode(10);
  root->left->right = newnode(8);
  // inorder(root);
  // cout<<bbt(root);
  node *temp1 = lca(root,root->left->left->left, root->left->left );
  cout<<temp1->data;
  return 0;
}
