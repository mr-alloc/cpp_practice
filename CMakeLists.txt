cmake_minimum_required(VERSION 3.30)
project(cpp_practice)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp_practice main.cpp
        grammer/basic_syntax.cpp
        grammer/basic_syntax.h
        data_structure/stack/Stack.cpp
        data_structure/stack/Stack.h
        data_structure/stack/ArrayStack.h
        data_structure/stack/LinkedListStack.h
        data_structure/list/DoublyLinkedList.h
        data_structure/list/DoublyNode.h
        data_structure/list/LinkedList.h
)
