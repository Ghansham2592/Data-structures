#include <iostream>
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

	node* get_head(){
		return head;
	}

	void create_list(int data){
		node *temp = new node;
		temp->value = data;
		temp->next = NULL;
		if(head == NULL){
			head = temp;
			tail = temp;
		}
		else{
			tail->next = temp;
			tail = temp;
		}
	}

	void dislplay(){
		node *temp;
		temp = head;
		// cout<<temp<<'\n';
		// cout<<head<<'\n';
		//cout<<*temp<<'\n';
		while(temp != NULL){
			cout<<temp->value<<'\n';
			temp = temp->next;
			// cout<<temp<<'\n';
		}
		cout<<"==================="<<'\n';
	}

	void n_th_elemet(int n){
		node *temp , *fast;
		temp = head;
		fast = head;
		for(int i =0; i<=n;i++){
			fast = fast->next;
		}
		while(fast != NULL){
			temp = temp->next;
			fast = fast->next;
		}
		temp->next = temp->next->next;

	}

	void swap_nodes(){
		node *temp, *list;
		temp = list =head;
		node *first;
		node *prev;
		int count = 1;
		while(temp != NULL){
			if(count%2 ==0)
			{	
				list = temp ;
				first =list->next;
				list->next = prev;
				prev->next = first;

				temp =first;
				

			}
			else
			{
				prev = temp;
				temp = temp->next;
				// count++;
			}
			count++;
		}
	}
};



int main(){
	LinkedList l1;
	l1.create_list(10);
	l1.create_list(20);
	l1.create_list(30);
	l1.create_list(49);
	l1.create_list(89);
	l1.create_list(34);
	l1.dislplay();
	l1.swap_nodes();
	l1.dislplay();


	return 0;
}