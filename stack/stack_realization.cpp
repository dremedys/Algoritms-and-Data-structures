#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Stack {
    public:
    Node *top;
    int sz;

    Stack() {
        top = NULL;
        sz = 0;
    }

    void push(int data) {
        Node *new_node = new Node(data);
        new_node->next = top;
        top = new_node;
        sz++;
    }

    void pop() {
        if (top != NULL) {
            top = top->next;
            sz--;
        }
    }

    bool empty() {

        return (top == NULL);
    }

    int size() {
        return sz;
    } 
};

int main() {
    Stack *st = new Stack();
    st->push(10);
    st->push(20);
    st->push(30);
    st->push(40);
    cout << st->top->data << endl;
    cout << st->size() << endl;
    cout << st->empty() << endl;
    st->pop();
    st->pop();
    cout << st->top->data;

    return 0;
}