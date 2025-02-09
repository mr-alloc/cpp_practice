#include <iostream>

#include "data_structure/list/LinkedList.h"
#include "data_structure/queue/Queue.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the
    // <b>lang</b> variable name to see how CLion can help you rename it.
    // auto는 c++ 11부터 컴파일러가 타입을 자동추
    Queue<int> queue;

    queue.enqueue(19);
    cout << "enqueue " << 19 << " and queue: " << queue << endl;
    queue.enqueue(25);
    cout << "enqueue " << 25 << " and queue: " << queue << endl;
    int dequeued = queue.dequeue();
    cout << "dequeue " << dequeued << " and queue: " << queue << endl;

    queue.enqueue(49);
    cout << "enqueue " << 49 << " and queue: " << queue << endl;
    queue.enqueue(184);
    cout << "enqueue " << 184 << " and queue: " << queue << endl;
    queue.enqueue(232);
    cout << "enqueue " << 232 << " and queue: " << queue << endl;

    queue.dequeue();
    cout << "dequeue " << queue << endl;


    return 0;
}


// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.