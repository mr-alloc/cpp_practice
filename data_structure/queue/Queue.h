//
// Created by 전태구 on 2025. 2. 9..
//

#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node *next;
        explicit Node(const T &data): data(data), next(nullptr) {}
    };
    Node *front;
    Node *rear;
    size_t size;

public:
    Queue(): front(nullptr), rear(nullptr), size(0) {}
    ~Queue() {
        while (!is_empty()) {
            dequeue();
        }
    }
    bool is_empty() const {
        return size == 0;
    }
    void enqueue(T data) {
        Node *newNode = new Node(data);
        if (is_empty()) {
            front = newNode;
        } else {
            rear->next = newNode;
        }
        rear = newNode;
        size++;
    }
    T dequeue() {
        if (is_empty()) throw underflow_error("Queue is empty!");
        Node* temp = front;
        front = front->next;
        T data = temp->data;
        delete temp;

        if (front == nullptr) rear = nullptr;

        size--;
        return data;
    }
    T peek() const {
        if (is_empty()) throw underflow_error("Queue is empty!");
        return front->data;
    }
    friend ostream& operator<<(ostream& os, const Queue& q) {
        os << "[";
        Node* temp = q.front;
        while (temp != nullptr) {
            os << temp->data;
            if (temp->next != nullptr) os << ", ";
            temp = temp->next;
        }

        os << "]";
        return os;
    }
};
#endif //QUEUE_H
