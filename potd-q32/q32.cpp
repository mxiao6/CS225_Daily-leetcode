#include <iostream>
using namespace std;

struct node{
    int val;
    node * next;
};

void printList(node * head){
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
}

node *createList(int arr[], int size){
    node * ret = new node;
    ret->val = arr[0];
    node * temp = ret;
    for(int i = 1; i < size; i ++){
        temp->next = new node;
        temp = temp->next;
        temp->val = arr[i];
    }
    temp->next = NULL;
    return ret;
}

int getSize(node* head) {
    int size = 0;
    node * current = head;

    while (current) {
        size++;
        current = current -> next;
    }

    return size;
}

void requeue(node** head, int times) {
    int size = getSize(*head);
    int num = times % size;

    node * current = *head;
    node * newHead = NULL;
    node * tail = NULL;

    for (int i = 1; i < num; i++) {
        current = current -> next;
    }

    newHead = current -> next;
    current -> next = NULL;

    tail = newHead;

    for (int i = 1; i < size - num; i++) {
        tail = tail -> next;
    }

    tail -> next = *head;
    *head = newHead;
}


int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    node * n = createList(arr, 5);
    const int times = 6;
    printList(n);
    cout << " , times: " << times << endl;
    // cout << getSize(n) << endl;
    requeue(&n, times);
    printList(n);
    cout << endl;
    return 0;
}
