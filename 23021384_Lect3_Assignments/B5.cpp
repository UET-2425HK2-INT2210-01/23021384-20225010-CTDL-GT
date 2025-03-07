#include <iostream>
using namespace std;
class Stack {
private:
    int* array;   
    int top;      
    int capacity; 
public:
    Stack(int size) {
        capacity = size;
        array = new int[capacity];
        top = -1; 
    }
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == capacity - 1;
    }
    void push(int value) {
        if (isFull()) {
            cout << "Stack is full! Cannot push " << value << "." << endl;
            return;
        }
        array[++top] = value;
        cout << "Pushed: " << value << endl;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot pop." << endl;
            return;
        }
        cout << "Popped: " << array[top--] << endl;
    }
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return array[top];
    }
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    ~Stack() {
        delete[] array;
    }
};
int main() {
    Stack s(5); 
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.display(); 
    s.pop();
    s.pop();
    cout << "Top element: " << s.peek() << endl;
    s.display();
    return 0;
}