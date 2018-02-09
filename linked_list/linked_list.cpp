#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node{
	int value;
	node *next;
};

class LinkedList{
	private:
		node *head;
		node *tail;
	public:
		LinkedList(){
			head = NULL;
			tail = NULL;
		}
		void create_node(int value){
			node *temp = new node;
			temp->value = value;
			temp->next = NULL;
			if (head == NULL){
				head = temp;
				tail = temp;
				temp = NULL;
			}
			else{
				tail->next = temp;
				tail = temp;
			}
		}

		void display_list(){
			node *temp = new node;
			temp = head;	
			while (temp !=NULL){
				cout<<temp->value<<'\n';
				temp = temp->next;
			}
			delete temp;
		}
		void delete_at_start(){
			node *temp = new node;
			temp = head->next ;
			head = temp;
			// delete temp;
		}
		void delete_at_end(){
			tail = NULL;
		}

		void insert_at_start(int value){
			node *temp = new node;
			temp->value = value;
			temp->next = head;
			head = temp;
			// delete temp;

		}
		void insert_at_end(int value){
			node *temp = new node;
			temp->value = value;
			temp->next= NULL;
			tail->next = temp;
			tail = temp;
			// delete temp;
		}
		void insert_at_pos(int pos,int value){
			
			node *temp =new node;
			node *pre =new node;
			node *curr = new node;
			curr = head;
			for(int i = 0; i<pos;i++){
				pre = curr;
				curr = curr->next;
			}
			temp->value = value;
			pre->next = temp;
			temp->next= curr;	
		}

};


int main(){
	LinkedList l_list;
	l_list.create_node(20);
	l_list.create_node(30);
	l_list.create_node(40);
	l_list.create_node(50);
	l_list.create_node(60);
	l_list.display_list();
	cout<<"----------"<<endl;
	// l_list.display_list();

	l_list.delete_at_start();
	l_list.display_list();
	cout<<"----------"<<endl;
	l_list.delete_at_end();
	l_list.display_list();
	cout<<"----------"<<endl;
	l_list.insert_at_start(78);
	l_list.display_list();
	cout<<"----------"<<endl;
	l_list.insert_at_pos(2,98);
	l_list.display_list();
	cout<<"----------"<<endl;
	return 0;
}