#include <bits/stdc++.h>
using namespace std;
class Queue {
private:
    int *array;    
    int front;      
    int rear;      
    int capacity;  
    int count;    
public:
    Queue(int size) {
        capacity = size;
        array = new int[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }
    ~Queue() {
        delete[] array;
    }
    bool isEmpty() {
        return (count == 0);
    }
    bool isFull() {
        return (count == capacity);
    }
    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue " << item << endl;
            return;
        }
        rear = (rear + 1) % capacity; 
        array[rear] = item;
        count++;
        cout << "Enqueued: " << item << endl;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return;
        }
        cout << "Dequeued: " << array[front] << endl;
        front = (front + 1) % capacity; 
        count--;
    }
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return array[front];
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < count; i++) {
            int index = (front + i) % capacity;
            cout << array[index] << " ";
        }
        cout << endl;
    }
};
int main() {
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); 
    q.display();
    q.dequeue();
    q.dequeue();
    cout << "Front element: " << q.getFront() << endl;
    q.enqueue(60);
    q.enqueue(70);
    q.display();
    return 0;
}
