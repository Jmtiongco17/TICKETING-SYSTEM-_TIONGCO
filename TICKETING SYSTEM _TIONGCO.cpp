#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int value) {
        Node* temp = new Node();
        temp->data = value;
        temp->next = nullptr;
        if (isEmpty()) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        } else {
            int value = front->data;
            Node* temp = front;
            front = front->next;
            if (front == nullptr) {
                rear = nullptr;
            }
            delete temp;
            return value;
        }
    }

    bool isEmpty() {
        return front == nullptr;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        } else {
            return front->data;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            Node* temp = front;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Queue q;

    // Simulate customers arriving and being served
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();

    cout << "Serving ticket number: " << q.peek() << endl;
    q.dequeue();
    q.display();

    cout << "Serving ticket number: " << q.peek() << endl;
    q.dequeue();
    q.display();

    cout << "Serving ticket number: " << q.peek() << endl;
    q.dequeue();
    q.display();

    return 0;
}
