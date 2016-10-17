#include <iostream>
using namespace std;

class Stack{
    private:
        struct node{
            int val;
            node * next;
            node() {val = 0; next = NULL;}
            node(int newVal) {val = newVal; next = NULL;}
        };
        node * head;
        int size;
    public:
        Stack();
        ~Stack();
        int getSize();
        bool isEmpty();
        void push(int value);
        int pop();
        void print();
};


/*

The Problem

Create a class Stack. The stack should be implemented with a dynamically 
allocated linked list (you may want to make a listnode struct/class within Stack).

Implement the following member functions of the stack class 
- int size() - returns the number of elements in the stack (0 if empty) 
- bool isEmpty() - returns if the list has no elements, else false 
- void push(int val) - pushes an item to the stack in O(1) time 
- int pop() - removes an item off the stack and returns the value in O(1) time 
- You should also implement the constructor which accepts no arguments and 
creates an empty stack, and a destructor for the class.

*/
 

Stack::Stack(){
    head = new node();
    size = 0;
}

Stack::~Stack(){
    node * current = head;
    node * currentNext = current -> next;
    while (currentNext) {
        delete current;
        current = currentNext;
        currentNext = current -> next;
    }
    delete current;
}

int Stack::getSize() {
    return size;
}

bool Stack::isEmpty() {
    return size == 0;
}

void Stack::push(int value) {
    node * newNode = new node(value);
    newNode -> next = head -> next;
    head -> next = newNode;

    size++;
}

int Stack::pop() {
    if (!isEmpty()) {
        node * temp = head -> next -> next;
        int value = head -> next -> val;

        head -> next -> next = NULL;
        delete head -> next;

        head -> next = temp;
        size--;

        return value;
    }

    return -1;
}

void Stack::print() {
    if (isEmpty()) {
        cout << "Empty!" << endl;
        return;
    }

    node * current = head -> next;

    while (current) {
        cout << current -> val << " ";
        current = current -> next;
    }

    cout << endl;
}



int main(){
    Stack a;
    a.print();
    cout << "is empty: " << a.isEmpty() << endl;
    a.push(1);
    a.push(2);
    a.push(3);
    cout << "popped: " << a.pop() << endl;
    cout << "size: " << a.getSize() << endl;
    cout << "is empty: " << a.isEmpty() << endl;
    a.print();
    
    return 0;
}
