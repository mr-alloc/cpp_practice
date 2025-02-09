//
// Created by 전태구 on 2025. 2. 8..
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdexcept>
using namespace std;

template <typename U>
struct Node {
    U data;
    Node *next;

    explicit Node(const U& data): data(data), next(nullptr) {}
};
template <typename T>
class LinkedList {
private:
    Node<T>* head;
    size_t size;
public:
    LinkedList(): head(nullptr), size(0) {}
    ~LinkedList();
    void push_back(T value);
    T pop_back();
    bool is_empty() const;
    friend ostream& operator<<(ostream& os, const LinkedList<T>& list) {
        os << "[";
        Node<T>* current = list.head;
        while (current != nullptr) {
            os << current->data;
            current = current->next;
            if (current != nullptr) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }
};

template <typename T>
LinkedList<T>::~LinkedList() {
    while (head != nullptr) {
        auto* temp = head;
        head = head->next;
        delete temp;
    }
}

template<typename T>
void LinkedList<T>::push_back(T value) {
    auto* newNode = new Node<T>(value);
    newNode->next = head;
    head = newNode;

    size ++;
}

template<typename T>
T LinkedList<T>::pop_back() {
    if (is_empty()) throw underflow_error("The linked list is empty");
    auto* current = head;
    T value = current->data;
    head = current->next;
    delete current;
    size --;
    return value;

}

template<typename T>
bool LinkedList<T>::is_empty() const {
    return size == 0;
}

#endif //LINKEDLIST_H
