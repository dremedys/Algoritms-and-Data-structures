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
    void back() {
        if (top != NULL) 
            cout << top->data << endl;
        else 
            cout << "error" << endl;
    }
    void push(int data) {
        Node *new_node = new Node(data);
        new_node->next = top;
        top = new_node;
        sz++;
    }
    void pop() {
        if (top != NULL) {
            cout << top->data << endl;
            top = top->next;
            sz--;
        }
        else 
            cout << "error" << endl;
    }
    int size() {
        return sz;
    } 
    void clear() {
        while(sz != NULL) {
           top = top->next;
            sz--; 
        }
    }
    bool empty() {
        return (top == NULL);
    }  
};
int main() {
    Stack *st = new Stack();
    string str;
    int n;
    while(true){
        cin >> str;
        if(str == "push") {
            cin >> n;
            st->push(n); 
            cout << "ok" << endl;
        }
        else if(str == "pop") {
            st->pop();
        }
        else if(str == "back") {
            st->back();
        } 
        else if(str == "exit") { 
            cout << "bye"<<endl;
            break;
        }
        else if (str == "size") {
            cout <<st->size()<<endl;
        }
        else {
            st->clear();
            cout<<"ok"<<endl;
        }
    }
}