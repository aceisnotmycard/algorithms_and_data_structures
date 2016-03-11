#include <iostream>
#include "Array.h"
#include "filters.h"

int main() {
    Array<int> ints(11);

    for (int i = 0; i < ints.length(); ++i) {
        ints[i] = i;
    }

    auto even_elements = ints | filters::even<int> | filters::greater_than(5);

    even_elements.for_each([] (int el) {
        std::cout << el << " ";
    });
}