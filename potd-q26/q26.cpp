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
    node * temp = *head;
    if(temp == NULL){
        *head = insert;
        insert->next = NULL;
        return;
    }
    if(temp->val >= insert->val){   // this node becomes the new head
        insert->next = temp;
        *head = insert;
    }
    else{
        node * prev = *head;
        temp = temp->next;
        while(temp != NULL){
            if(temp->val >= insert->val){
                insert->next = temp;
                prev->next = insert;
                return;
            }
            temp = temp->next;
            prev = prev->next;
        }
        // we reached the end of list, this node must go at the end
        // prev points to last node, temp points to NULL
        prev->next = insert;
        insert->next = NULL;
    }
}

void sortList(node ** head){
    node * newHead = NULL;
    node * curHead = *head;
    node * insert;
    while(curHead != NULL) {
        insert = curHead;
        curHead = curHead->next;
        insert->next = NULL;
        insertSorted(&newHead, insert);
    }
    *head = newHead;
}

node * shuffle(node * a, node * b){
	node * curr = b;
	node * insert;
	while(curr != NULL) {
		insert = curr;
		curr = curr -> next;
		insert -> next = NULL;
		insertSorted(&a, insert);
	}
	return a;
}

int main(){
	node * head1 = new node();
    node * curr = head1;
    node * prev = head1;
    for (int i = 0; i <= 6; i = i+2) {
        prev = curr;
        curr -> val = i;
        curr -> next = new node();
        curr = curr -> next;
    }
    delete curr;
    prev -> next = NULL;

    node * head2 = new node();
    curr = head2;
    prev = head2;
    for (int i = 1; i <= 7; i = i+2) {
        prev = curr;
        curr -> val = i;
        curr -> next = new node();
        curr = curr -> next;
    }
    delete curr;
    prev -> next = NULL;

    printList(head1);
    cout << endl;
    printList(head2);
    cout << endl;

    node * newHead = shuffle(head1, head2);

    printList(newHead);

    return 0;
}
