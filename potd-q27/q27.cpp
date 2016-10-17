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
    while(curHead != NULL){
        insert = curHead;
        curHead = curHead->next;
        insert->next = NULL;
        insertSorted(&newHead, insert);
    }
    *head = newHead;
}

node * shuffle(node * a, node * b){
    if(a == NULL) return b;
    if(b == NULL) return a;
    node * aptr = a;
    node * bptr = b;
    while(aptr->next != NULL && bptr->next != NULL){
        node * tempa = aptr;
        aptr = aptr->next;
        node * tempb = bptr;
        bptr = bptr->next;
        tempa->next = tempb;
        tempb->next = aptr;
    }
    if(aptr->next == NULL){ // tack on rest of b
        aptr->next = bptr;
    }
    else{   // bptr->next == NULL
        // add last b node to a list
        node * tempa = aptr;
        aptr = aptr->next;
        tempa->next = bptr;
        bptr->next = aptr;
    }
    return a;
}

node * intersection(node * a, node * b) {
    sortList(&a);
    sortList(&b);

    printList(a);
    cout << endl;
    printList(b);
    cout << endl;

    node * result = new node();
    node * currNew = result;
    node * curr1 = a;
    node * curr2 = b;
    node * prev = result;

    while (curr1 != NULL) {
        if (curr1 -> val > curr2 -> val) {
            curr2 = curr2 -> next;
            continue;
        } else if (curr1 -> val == curr2 -> val) {
            if (curr1 -> val != prev -> val) {
                currNew -> val = curr1 -> val;
                prev = currNew;
                currNew -> next = new node();
                currNew = currNew -> next;
                curr1 = curr1 -> next;
                curr2 = curr2 -> next;
            }
        } else {
            curr1 = curr1 -> next;
        }
    }
    delete currNew;
    currNew = NULL;
    prev -> next = NULL;
    return result;
}

int main(){
    node * head1 = new node();
    node * curr = head1;
    node * prev = head1;
    for (int i = 6; i >= 1; i = i-1) {
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
    for (int i = 10; i >= 1; i = i-2) {
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

    node * newHead = intersection(head1, head2);

    printList(newHead);

    return 0;
}
