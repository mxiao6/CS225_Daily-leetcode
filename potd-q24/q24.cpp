#include <iostream>
using namespace std;

struct node{
    int val;
    node * next;
};

void printList(node * head){
    if(head == NULL){
        cout << "Empty list" << endl;
        return;
    }
    node * temp = head;
    int count = 0;
    while(temp != NULL){
        cout << "Node " << count << ": " << temp ->val << endl;
        count++;
        temp = temp->next;
    }
}

void insertSorted(node ** head, node * insert){
	if (head == NULL) {
		head = &insert;
		return;
	}

	node* curr = *head;

	while (curr -> next != NULL && curr -> next -> val < insert -> val) {
		curr = curr -> next;
	}

	node* temp = curr -> next;
	curr -> next = insert;
	insert -> next = temp;
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

    node * insertedNode = new node();
    insertedNode -> val = 2;

    node ** bigHead = &head;

    insertSorted(bigHead, insertedNode);

    printList(head);

    return 0;
}
