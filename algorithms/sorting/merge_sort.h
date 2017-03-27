//
// Created by Sergey Bogolepov on 27/03/2017.
//

#ifndef ALGORITHMS_AND_DATA_STRUCTURES_MERGE_SORT_H
#define ALGORITHMS_AND_DATA_STRUCTURES_MERGE_SORT_H

#include <vector>
#include <algorithm>

typedef const std::vector<int>::iterator const_it;

std::vector<int> _merge(const_it start_a, const_it end_a, const_it start_b, const_it end_b) {
    auto cur_it = start_a;
    auto another_it = start_b;
    auto cur_end = end_a;
    auto another_end = end_b;
    std::vector<int> result(std::distance(start_a, end_a) + std::distance(start_b, end_b));
    auto result_it = std::begin(result);
    while (cur_it != cur_end) {
        if (*cur_it >= *another_it) {
            std::swap(cur_it, another_it);
            std::swap(cur_end, another_end);
        }
        *result_it = *cur_it;
        result_it++;
        cur_it++;
    }
    if (another_it != another_end) {
        std::copy(another_it, another_end, result_it);
    }

    return result;
}


// const_it is RandomAccessIterator so std::distance's complexity is constant
std::vector<int> merge_sort(const_it begin, const_it end) {
    auto distance = std::distance(begin, end);
    if (distance >= 1) {
        const_it mid = begin + distance / 2;
        auto a = merge_sort(begin, mid);
        auto b = merge_sort(mid, end);
        return _merge(std::begin(a), std::end(a), std::begin(b), std::end(b));
    } else if (distance < 1) {
        return {};
    } else {
        return { *begin };
    }
}


#endif //ALGORITHMS_AND_DATA_STRUCTURES_MERGE_SORT_H
