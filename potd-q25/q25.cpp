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
    // if (head == NULL) {
    //     head = &insert;
    //     (*head) -> next = NULL;
    //     return;
    // }
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

void sortList(node ** head) {
    // if (head == NULL || *head == NULL)
    //     return;
    // cout << "line 56" << endl;
    node * newhead = NULL;
    node * curr = *head;
    node * insert;
    // cout << "line 59" << endl;
    while(curr != NULL) {
        insert = curr;
        curr = curr -> next;
        insert -> next = NULL;
        insertSorted(&newhead, insert);
    }

    // cout << "line 70" << endl;
    *head = newhead;
    newhead = NULL;
}

// Write a sortlist method here.

int main(){
    node * head = new node();
    node * curr = head;
    node * prev = head;
    for (int i = 3; i > 0; i--) {
        prev = curr;
        curr -> val = i;
        curr -> next = new node();
        curr = curr -> next;
    }
    delete curr;
    prev -> next = NULL;

    printList(head);

    node ** bigHead = &head;

    sortList(bigHead);

    cout << "line 96" << endl;

    printList(*bigHead);

    return 0;
}
