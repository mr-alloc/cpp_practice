//
// Created by 전태구 on 2025. 2. 8..
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#import <iostream>
#include <stdexcept>

#include "DoublyNode.h"
using namespace std;



template <typename T>
class DoublyLinkedList {
private:
    DoublyNode<T>* head;
    DoublyNode<T>* tail;
    size_t size;
public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    };
    ~DoublyLinkedList();

    void insert_front(T data);
    T remove_front();
    void insert_back(T data);
    T remove_back();
    bool is_empty() const;
    friend ostream& operator<<(ostream& os, const DoublyLinkedList<T>& list) {
        DoublyNode<T>* current = list.head;
        os << "[";
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

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    while (head != nullptr) {
        DoublyNode<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template<typename T>
void DoublyLinkedList<T>::insert_front(T data) {
    DoublyNode<T>* node = new DoublyNode<T>(data);
    size++;
    if (head == nullptr) {
        head = node;
        tail = node;
        return;
    }

    node->next = head;
    head->pre = node;
    head = node;
}
template<typename T>
void DoublyLinkedList<T>::insert_back(T data) {
    DoublyNode<T>* node = new DoublyNode<T>(data);
    size++;
    if (tail == nullptr) {
        tail = node;
        head = node;
        return;
    }

    tail->next = node;
    node->pre = tail;
    tail = node;
}

template<typename T>
T DoublyLinkedList<T>::remove_front() {
    if (is_empty()) throw std::underflow_error("Empty list");

    DoublyNode<T>* temp = head;
    if (head == nullptr) {
        tail = nullptr;
    } else {
        tail->pre = nullptr;
    }
    head = temp->next;

    T data = temp->data;
    delete temp;
    return data;
}

template<typename T>
T DoublyLinkedList<T>::remove_back() {
    if (is_empty()) throw std::underflow_error("Empty list");

    DoublyNode<T>* temp = tail;
    tail = temp->pre;
    if (tail == nullptr) {
        head = nullptr;
    }

    T data = temp->data;
    delete temp;
    return data;
}


template<typename T>
bool DoublyLinkedList<T>::is_empty() const {
    return size == 0;
}


// 외부 구현 (헤더 파일에 추가)
template <typename T>
std::ostream& operator<<(std::ostream& os, const DoublyLinkedList<T>& list) {
    DoublyNode<T>* current = list.head;
    os << "[";
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

#endif //LINKEDLIST_H
