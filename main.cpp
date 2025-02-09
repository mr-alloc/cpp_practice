#include <iostream>

#include "data_structure/list/LinkedList.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the
    // <b>lang</b> variable name to see how CLion can help you rename it.
    // auto는 c++ 11부터 컴파일러가 타입을 자동추
    auto lang = "C++";

    LinkedList<int> list;

    list.push_back(2);
    cout << "add new " << 2 << ": " << list << endl;

    list.push_back(7);
    cout << "add new " << 7 << ": " << list << endl;

    list.push_back(5);
    cout << "add new " << 5 << ": " << list << endl;

    int removed = list.pop_back();
    cout << "remove " << removed << ": " << list << endl;
    list.push_back(4);
    cout << "add " << 4 << ": " << list << endl;

    cout << list << endl;




    return 0;
}


// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.