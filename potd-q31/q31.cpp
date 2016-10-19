#include <iostream>
using namespace std;

class Queue{
private:
    struct node{
        int val;
        node * next;
        node() {val = 0; next = NULL;}
        node(int newVal) {val = newVal; next = NULL;}
    };
    node * exit; // front
    node * entry; // tail
    int size;
public:
    Queue();
    ~Queue();
    void push(int value);
    int pop();
    int getSize();
    bool isEmpty();
    void print();
};

Queue::Queue() {
    exit = NULL;
    entry = NULL;
    size = 0;
}

Queue::~Queue() {
    node * current = exit;
    if (exit) {
        node * currentNext = current -> next;
        while (currentNext) {
            delete current;
            current = currentNext;
            currentNext = current -> next;
        }
        delete current;
    }
}

int Queue::getSize() {
    return size;
}

bool Queue::isEmpty() {
    return size == 0;
}

void Queue::push(int value) {
    node * newNode = new node(value);
    if (entry == NULL) {
        entry = newNode;
        exit = newNode;
        size = 1;
    } else {
        entry -> next = newNode;
        entry = newNode;
        size++;
    }
}

int Queue::pop() {
    if (!isEmpty()) {
        node * temp = exit;
        int value = exit -> val;

        exit = exit -> next;
        temp -> next = NULL;
        delete temp;
        size--;

        return value;
    }

    return -1;
}

void Queue::print() {
    if (isEmpty()) {
        cout << "Empty!" << endl;
        return;
    }

    node * current = exit;
    while (current) {
        cout << current -> val << " ";
        current = current -> next;
    } 
    cout << endl;
}


int main(){
    Queue a;
    a.print();
    cout << "is empty " << a.isEmpty() << endl;
    a.push(1);
    a.push(2);
    a.push(3);
    a.print();
    cout << "popped " << a.pop() << endl;
    cout << "size: " << a.getSize() << endl;
    cout << "popped " << a.pop() << endl;
    cout << "size: " << a.getSize() << endl;
    cout << "popped " << a.pop() << endl;
    cout << "size: " << a.getSize() << endl;
    cout << "is empty " << a.isEmpty() << endl;
    a.print();
    
    return 0;
}
