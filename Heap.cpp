//
// Created by Sergey Bogolepov on 27/02/2017.
//

#include <iostream>
#include "Heap.h"

int main() {
    Heap heap;

    heap.push(1);
    heap.push(2);
    heap.push(4);
    heap.push(3);

    while (heap.size() > 0) {
        std::cout << heap.pop() << std::endl;
    }
}