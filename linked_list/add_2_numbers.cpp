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

	node* get_head(){
		return head;
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


	static node* list_print(node *l1, node *l2){
		node *temp_l1, *temp_l2, *prev;
        temp_l1 = l1;
        temp_l2 =l2;
        int len_l1= 0;
        int len_l2= 0;
        while(temp_l1 != NULL){
            len_l1++;
            temp_l1 = temp_l1->next; 
        }
        while(temp_l2 != NULL){
            len_l2++;
            temp_l2 = temp_l2->next;
        }
        temp_l1 = l1;
        temp_l2 =l2;
        int diff =0;
        if(len_l1 > len_l2){
            diff = len_l1 - len_l2;
            while(diff){
                temp_l1 = temp_l1->next; 
                --diff;
            }
        }
        if(len_l1 < len_l2){
            diff = len_l2 - len_l2;
            while(diff){
                temp_l2 = temp_l2->next; 
                --diff;
            } 
        }
        int head = 0;
        int carry;
        int count = 0;
        prev = NULL;
        while(temp_l1 != NULL && temp_l2 != NULL){
        	carry =0;
            temp_l1->data = temp_l1->data + temp_l2->data;
            if (temp_l1->data >9){
                if(head == 0 && count ==0){
                    head = temp_l1->data/10;
                }
                else{
                    carry = temp_l1->data/10;
                }
                // cout<<"test1"<<temp_l1->data<<'\n';
                temp_l1->data = temp_l1->data % 10;
                // cout<<"test2"<<temp_l1->data<<'\n';
            }
            if (prev!= NULL && carry >0){
                prev->data = prev->data + carry; 
            }
            count++;
            prev = temp_l1;
            temp_l1= temp_l1->next;
            temp_l2= temp_l2->next;
            
        }
        return l1;
	}

};

int main(){
	Linked_list li_1;
	Linked_list li_2;
	int result =0;
	int temp;
	li_1.create_list(7);
	li_1.create_list(2);
	li_1.create_list(4);
	li_1.create_list(3);
	li_2.create_list(5);
	li_2.create_list(6);
	li_2.create_list(4);
	Linked_list::list_print(li_1.get_head(), li_2.get_head());
	li_1.display();
	// li_2.display();
	// li_1.reverse();
	// li_2.reverse();
	// li_1.display();	
	// li_2.display();
	// result = li_1.number_return() + li_2.number_return();
	// cout<<"---------"<<result<<endl;
	// while(result){
	// 	temp = result % 10;
	// 	li_3.create_list(temp);
	// 	result = result/10;
	// }
	// li_3.display();


	
	return 0;
}

