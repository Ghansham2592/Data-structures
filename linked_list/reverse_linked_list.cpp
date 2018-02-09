#include <iostream>
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
	void reverse(){
		node *next;
		node *prev;
		node *curr;
		prev = NULL;
		curr = head;
		while(curr != NULL){
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		} 
		head = prev;
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
	li.display();
	cout<<"---------"<<endl;
	li.reverse();
	li.display();

	return 0;
}

