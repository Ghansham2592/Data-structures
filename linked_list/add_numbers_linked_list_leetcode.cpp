// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8




// #include <iostream>
#include <bits/stdc++.h>
// #include <unordered_set>
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
	int create_list(int value){
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
		return 0;
	}
	int display(){
		node *temp = new node;
		temp = head;
		while (temp != NULL){
			cout<<temp->data<<'\n';
			temp = temp->next;
		}
		return 0;
	}
	int reverse(){
		node *prev;
		node *curr;
		node *next;
		curr = head;
		prev = NULL;
		while(curr != NULL){
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;

		}
		head = prev;
		return 0;
	}

	int number_return(){
		int value =0;
		node *temp;
		temp = head;
		int count= 1;
		while(temp!=NULL){
			value = value + temp->data * count;
			count = count * 10;
			temp = temp->next;
		}
		return value;
	}



};


int main(){
	Linked_list li_1;
	Linked_list li_2;
	Linked_list li_3;
	int result =0;
	int temp;
	li_1.create_list(2);
	li_1.create_list(4);
	li_1.create_list(3);
	li_2.create_list(5);
	li_2.create_list(6);
	li_2.create_list(4);
	li_1.display();
	li_2.display();
	li_1.reverse();
	li_2.reverse();
	li_1.display();
	li_2.display();
	result = li_1.number_return() + li_2.number_return();
	cout<<"---------"<<result<<endl;
	while(result){
		temp = result % 10;
		li_3.create_list(temp);
		result = result/10;
	}
	li_3.display();


	
	return 0;
}

