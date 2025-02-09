//
// Created by 전태구 on 2025. 2. 8..
//

#ifndef LINKEDLISTSTACK_H
#define LINKEDLISTSTACK_H
#include "Stack.h"
#include <iostream>
using namespace std;


template <typename T>
class LinkedListStack : public Stack<T> {
private:

    //연결 리스트를 위한 Node 구조체
    struct Node {
        T data;
        Node* next;

        explicit Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* top;
    int cap;

public:
    explicit LinkedListStack(int capacity) : cap(capacity), top(nullptr) {}
    ~LinkedListStack() override {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
    void push(const T &item) override {
        Node* newNode = new Node(item);
        newNode->next = top;
        top = newNode;
        cap++;
    }

    T pop() override {
        if (is_empty()) {
            throw underflow_error("Stack is empty");;
        }
        Node* temp = top;
        T popped = temp->data;
        top = top->next;
        delete temp;
        cap--;

        return popped;
    }

    T peek() override {
        if (is_empty()) {
            throw underflow_error("Stack is empty");;
        }
        return top->data;
    }

    bool is_empty() override {
        return top == nullptr;
    }

    int size() override {
        return top == nullptr ? 0 : cap;
    }

    friend ostream& operator<<(ostream& os, const LinkedListStack<T>& stack) {
        os << "Stack: [";
        Node* current = stack.top;
        while (current != nullptr) {
            os << current->data;
            if (current->next != nullptr) {
                os << ", ";
            }
            current = current->next;
        }
        os << "]";
        return os;
    }
};



#endif //LINKEDLISTSTACK_H
