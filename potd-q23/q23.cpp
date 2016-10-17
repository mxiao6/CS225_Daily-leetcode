#include <iostream>
using namespace std;

struct node{
    int val;
    node * next;
};

void printList(node * head){
	for (int i = 0; head != NULL; i++) {
		cout << "Node " << i << ": " << head -> val << endl;
		head = head -> next;
	}
}

int main(){
    node * head = new node();
    // enter code here to make a list...
    node * curr = head;
    node * prev = head;
    for (int i = 1; i <= 3; i++) {
    	// cout << "line21" << endl;
    	prev = curr;
    	curr -> val = i;
    	curr -> next = new node();
    	curr = curr -> next;
    }
    delete curr;
    prev -> next = NULL;
    printList(head);
    return 0;
}
