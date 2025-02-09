//
// Created by 전태구 on 2025. 2. 7..
//

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#include <iostream>
#include "Stack.h"
using namespace std;


template <typename T>
class ArrayStack final : public Stack<T> {
private:
    T* arr; //포인터로 동적 할당
    int top;
    int cap;
public:
    //c++은 생성자 매개변수 전달시 암시적 변환으로 객체가 생성될 수 있으므로 explicit 키워드를 붙여야함
    explicit ArrayStack(const int cap): top(-1), cap(cap) {
        arr = new T[cap];
    }

    ~ArrayStack() override {
        delete[] arr;
        //top과 cap은 스택 메모리(콜스택) 변수라서 자동으로 해제
    }

    void push(const T& item) override {
        if (top == cap -1) {
            throw overflow_error("Stack is full");
        }
        arr[++top] = item;
    }

    T pop() override {
        if (is_empty()) {
            throw underflow_error("Stack is empty");
        }

        return arr[top--];
    }

    T peek() override {
        if (is_empty()) {
            throw underflow_error("Stack is empty");
        }

        return arr[top];
    }

    bool is_empty() override {
        return top == -1;
    }

    int size() override {
        return top + 1;
    }

    friend ostream& operator<<(ostream& os, const ArrayStack<T>& stack) {
        os << "Stack: [";
        for (int i = stack.top; i >= 0; i--) {
            os << stack.arr[i];
            if (0 < i) os << ",";
        }
        os << "]";
        return os;
    }
};



#endif //ARRAYSTACK_H
