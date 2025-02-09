//
// Created by 전태구 on 2025. 2. 8..
//

#ifndef NODE_H
#define NODE_H

template <typename T>
struct DoublyNode {
    T data;
    DoublyNode* pre;
    DoublyNode* next;

    explicit DoublyNode(T data) : data(data), pre(nullptr), next(nullptr) {}
};
#endif //NODE_H
