//
// Created by 전태구 on 2025. 2. 7..
//

#include "basic_syntax.h"
#include <iostream> //iostream 표준 라이브러리 사용
using namespace std; //std 네임스페이스 사용

// c/c++은 헤더파일에 선언하고, c/cpp 파일에 구현한다.

void type_modifier() {
    int num = 10;
    //int* 는 int 포인터 변수)의 선언을 의미한다.
    //&num 은 num 변수에대한 주소를 반하며, 변수명 앞에 &는 주소 연산자를 의미한다.
    int* ptr = &num;

    //역참조 연산자
    int num2 = *ptr;
    *ptr += 20;

    cout << "num2: " << num2 << endl;
    cout << "*ptr: " << *ptr << endl;

    //TODO 이동 시멘틱
}

void print_array_address() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int arr[5] = {1, 2, 3, 4, 5};
    //const: 런타임에 초가화, constexpr: 컴파일 타임에 초기화
    constexpr int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "array: " << arr << std::endl;

    for (int i = 0; i < size; i++) {
        std::cout << &arr[i] << "::[" << i << "] = " << arr[i] << std::endl;
    }
}

