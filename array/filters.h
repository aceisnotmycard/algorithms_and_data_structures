//
// Created by Sergey Bogolepov on 11/03/16.
//

#ifndef ARRAY_FILTERS_H
#define ARRAY_FILTERS_H

#include <functional>

namespace filters {
    template <typename T>
    std::function<bool(T)> greater_than(const T& val) {
        return [&](T el) { return el > val; };
    };

    template <typename T>
    auto even = [](T el) { return el % 2 == 0; };
};

#endif //ARRAY_FILTERS_H
