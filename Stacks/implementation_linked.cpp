#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Stack {
    Node* top;
public:
    Stack() {
        top = nullptr;
    }
    
    bool isEmpty() {
        return top == nullptr;
    }
    
    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
        cout << x << " pushed to stack\n";
    }
    
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        Node* temp = top;
        top = top->next;
        int x = temp->data;
        delete temp;
        return x;
    }
    
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return top->data;
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack;
    
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    cout << stack.pop() << " popped from stack\n";
    
    stack.display();
    
    cout << "Top element is " << stack.peek() << endl;
    
    return 0;
}
