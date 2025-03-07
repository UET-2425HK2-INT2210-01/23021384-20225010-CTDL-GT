#include <iostream>
using namespace std;
struct Node {
    int data;    
    Node* next;  
};
class Stack {
private:
    Node* top; 
public:
    Stack() {
        top = nullptr;
    }
    bool isEmpty() {
        return top == nullptr;
    }
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode; 
        cout << "Pushed: " << value << endl;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot pop." << endl;
            return;
        }
        Node* temp = top;
        cout << "Popped: " << temp->data << endl;
        top = top->next;
        delete temp;
    }
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return top->data;
    }
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* temp = top;
        cout << "Stack elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.display(); 
    s.pop();
    s.pop();
    cout << "Top element: " << s.peek() << endl;
    s.display();
    return 0;
}