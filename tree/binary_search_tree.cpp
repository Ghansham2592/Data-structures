// https://gist.github.com/toboqus/def6a6915e4abd66e922


#include <iostream>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
};


class Binary_tree{
public:
	Binary_tree();
	void insert(int key);
	void inorder();
	void inorder(node *leaf);

private:
	void insert(node *leaf, int key);
	node *root;

};

Binary_tree::Binary_tree(){
	root = NULL;
}

void Binary_tree::insert(node *leaf, int key){
	if (key < leaf->data){
		if(leaf->left != NULL){
			insert(leaf->left , key);
		}
		else{
			leaf->left = new node;
			leaf->left->data = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;

		}
	}
	else{
		if(leaf->right != NULL){
			insert(leaf->right,key);
		}
		else{
			leaf->right = new node;
			leaf->right->data = key;
			leaf->right->left = NULL;
			leaf->right->right = NULL;

		}

	}
}

void Binary_tree::insert(int key){
	if(root!= NULL){
		insert(root, key);
	}
	else{
		root = new node;
		root->data = key;
		root->left = NULL;
		root->right = NULL;
	}

}
void Binary_tree::inorder(){
	inorder(root);

}

void Binary_tree::inorder(node *leaf){
	if (leaf != NULL){
		cout<<leaf->data<<'\n';
		inorder(leaf->left);
		inorder(leaf->right);
	}
}


int main(){
	Binary_tree *btree = new Binary_tree();
	btree->insert(5);
	btree->insert(4);
	btree->insert(7);
	btree->insert(2);
	btree->insert(8);
	btree->insert(1);
	btree->insert(6);
	btree->insert(3);
	btree->insert(9);
	btree->inorder();
	return 0;
}