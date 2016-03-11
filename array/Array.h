//
// Created by Sergey Bogolepov on 11/03/16.
//

#ifndef ARRAY_ARRAY_H
#define ARRAY_ARRAY_H


#include <stddef.h>
#include <stdlib.h>
#include <math.h>


// naive array implementation, nothing special
template <typename Type>
class Array {
public:
    Array(size_t length);
    ~Array();

    // not safe, but fast
    Type & operator[](size_t index);

    void for_each(std::function<void(Type& el)> fn);

    void extend(size_t to_add);
    void shrink(size_t to_remove);

    Array<Type>& operator|(std::function<bool(const Type&)> filter);

    size_t length() const;

private:
    Type * array;
    size_t size; // size of allocated memory

    size_t nearest_pow(size_t length);

    constexpr static size_t MIN_SIZE = 4;
    constexpr static size_t FACTOR = 2;
};


template <typename Type>
Array<Type>::Array(size_t length): size(length) {
    array = new Type[size];
}

template <typename Type>
Array<Type>::~Array() {
    delete[] array;
}

template <typename Type>
size_t Array<Type>::length() const {
    return size;
}

template <typename Type>
Type & Array<Type>::operator[](size_t index) {
    return array[index];
}

template <typename Type>
size_t Array<Type>::nearest_pow(size_t length) {
    return static_cast<size_t>(pow(2, ceil(log(length)/log(2))));
}

template <typename Type>
void Array<Type>::for_each(std::function<void(Type &)> fn) {
    for(size_t i = 0; i < size; i++) {
        fn(array[i]);
    }
}

template <typename Type>
void Array<Type>::extend(size_t to_add) {
    auto new_array = new Type[size+to_add];
    std::copy_n(array, size, new_array);
    delete[] array;
    array = new_array;
    size += to_add;
}

template <typename Type>
void Array<Type>::shrink(size_t to_remove) {
    if (to_remove >= size) {
        delete[] array;
        size = 0;
    }
    auto new_array = new Type[size-to_remove];
    std::copy_n(array, size-to_remove, new_array);
    delete[] array;
    array = new_array;
    size -= to_remove;
}

template <typename Type>
Array<Type>& Array<Type>::operator|(std::function<bool(const Type&)> filter) {
    auto  elements = new Array<Type>(size);
    int new_size = 0;
    for (size_t i = 0; i < size; i++) {
        if (filter(array[i])) {
            (*elements)[new_size++] = array[i];
        }
    }
    elements->shrink(size-new_size);
    return *elements;
}


#endif //ARRAY_ARRAY_H

