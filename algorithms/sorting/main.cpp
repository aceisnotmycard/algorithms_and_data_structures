//
// Created by Sergey Bogolepov on 27/03/2017.
//
#include <iostream>
#include <vector>
#include "merge_sort.h"

int main() {
    std::vector<int> test({ 3, 5, 8, 1 });
    auto result = merge_sort(std::begin(test), std::end(test));
    std::for_each(std::begin(result), std::end(result), [](auto elem) {std::cout << elem << " ";});
}