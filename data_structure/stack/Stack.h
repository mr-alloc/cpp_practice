//
// Created by 전태구 on 2025. 2. 7..
//

#ifndef STACK_H
#define STACK_H


//템플릿 클래스는 실제사용된 클래스에 대해 템플릿 인스턴스화를 진행한다. Stack<int> -> (Stack_int)
template <typename T>
class Stack {
    public:
        // 가상 소멸자
        virtual ~Stack() = default;
        virtual void push(const T& item) = 0;
        virtual T pop() = 0;
        virtual T peek() = 0;
        virtual bool is_empty() = 0;
        virtual int size() = 0;
};



#endif //STACK_H
