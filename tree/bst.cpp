#include <iostream>
using namespace std;

struct node{
	int data;
	node *left, *right;
};

class Tree{
	private:
		node *root;
		void insert(node *leaf, int value);
		void inorder(node *leaf);

	public:
		Tree(){
			root = NULL;
		}
		void insert(int value);
		void inorder();

};
void Tree:: insert(node *leaf, int value){
	if(leaf->data > value){
		if(leaf->left != NULL){
			insert(leaf->left, value);
		}
		else{
			leaf->left = new node;
			leaf->left->data = value;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}
	else{
		if(leaf->right != NULL){
			insert(leaf->right, value);
		}
		else{
			leaf->right = new node;
			leaf->right->data = value;
			leaf->right->left = NULL;
			leaf->right->right = NULL;
		}
	}

	

}

void Tree :: insert(int value){
	if (root != NULL){
		insert(root ,value);
	}
	else{
		root = new node;
		root->data = value;
		root->left = NULL;
		root->right = NULL;
	}

} 
void Tree:: inorder(){
	inorder(root);
}

void Tree:: inorder(node *leaf){
	if (leaf != NULL){
		inorder(leaf->left);
		cout<<leaf->data<<'\n';
		inorder(leaf->right);
	}

}

int main(){
	Tree *bst = new Tree();
	bst->insert(8);
	bst->insert(4);
	bst->insert(5);
	bst->insert(89);
	bst->insert(9);
	bst->inorder();
	return 0;
}