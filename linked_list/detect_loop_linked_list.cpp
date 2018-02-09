// #include <iostream>
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;



struct node {
int data;
node *next;
};

class Linked_list{
private:
	node *head;
	node *tail;
public:
	Linked_list(){
		head = NULL;
		tail= NULL;
	}
	void create_list(int value){
		node *temp = new node;
		temp->data = value;
		temp->next = NULL;

		if (head == NULL){
			head = temp;
			tail = temp;
			temp= NULL;
		}
		else{
			tail->next = temp;
			tail = temp;
		}
	}
	void display(){
		node *temp = new node;
		temp = head;
		while (temp != NULL){
			cout<<temp->data<<'\n';
			temp = temp->next;
		}
	}
	void create_loop(){
		head->next->next->next->next->next->next = head;
	}
	bool detelct_loop(){
		unordered_set<node *> s;
		node *temp;
		temp = head;

		while(temp != NULL){

			if (s.find(temp) != s.end())
				return true;
			s.insert(temp);
			temp= temp->next;
		}
		return false;
		
	}



};


int main(){
	Linked_list li;
	li.create_list(10);
	li.create_list(20);
	li.create_list(30);
	li.create_list(40);
	li.create_list(50);
	li.create_list(60);
	li.create_loop();

	// li.display();
	cout<<"---------"<<endl;
	if (li.detelct_loop()){
		cout<<"loop found";
	}
	else{
		cout<<"loop not found";
	}
	// li.display();

	return 0;
}

