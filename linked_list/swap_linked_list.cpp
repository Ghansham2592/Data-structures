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
	
		void swap(int x, int y){
			node *temp =new node;
			node *prex =new node;
			node *prey =new node;
			temp = head;
			while(temp!=NULL){
				if(temp->value == x){
					prex = temp;
				}
				else if(temp->value== y){
					prey = temp;

				}
				temp = temp->next;

			}
			int temp_value = prex->value;
			prex->value = prey->value;
			prey->value = temp_value;
			// delete temp;


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
	l_list.swap(30,60);
	l_list.display_list();
	cout<<"----------"<<endl;
	return 0;
}