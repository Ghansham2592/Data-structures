#include <iostream>
using namespace std;

struct node{
	int data;
	node *next;
};

class Linked_list{
	private:
		node *head;
		node *tail;
	public:
		Linked_list(){
			head= NULL;
			tail=NULL;
		}
	void create_list(int value){
		node *temp = new node;
		temp->data = value;
		temp->next =  NULL;

		if(head == NULL){
			head = temp;
			tail = temp;
			temp=NULL;
		}
		else{
			tail->next= temp;
			tail= temp;
		}
	}
	void display(){
		node *temp = new node;
		temp = head;
		while(temp != NULL){
			cout<<temp->data<<'\n';
			temp = temp->next;
		}
	}

	void middle_elemet(){
		node *temp_head = new node;
		node *temp_fast = new node;
		temp_fast = temp_head =head;
		while(temp_fast != NULL){
			temp_head = temp_head->next;
			temp_fast = temp_fast->next->next;
		}

		cout<<"middle_elemet:"<<temp_head->data;
	}

};

int main(){
	Linked_list list;
	list.create_list(10);
	list.create_list(20);
	list.create_list(30);
	list.create_list(40);
	list.create_list(50);
	list.create_list(60);
	list.display();
	list.middle_elemet();
	return 0;
}