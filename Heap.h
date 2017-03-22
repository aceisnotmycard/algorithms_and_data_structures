//
// Created by Sergey Bogolepov on 27/02/2017.
//

#ifndef PROJECT_HEAP_H
#define PROJECT_HEAP_H


#include <vector>

template<typename T>
class Heap {
public:
    Heap() {}

    T pop() {
        auto result = _data[0];
        _data[0] = _data[_data.size() - 1];
        _data.pop_back();
        sift_down(0);
        return result;
    }

    void push(T value) {
        _data.push_back(value);
        sift_up(_data.size() - 1);
    }

    size_t size() const {
        return _data.size();
    }

private:
    std::vector<T> _data;

    inline size_t parent_pos(size_t child_pos) const {
        return child_pos / 2;
    }

    inline size_t left_child_pos(size_t parent_pos) const {
        return parent_pos * 2 + 1;
    }

    inline size_t right_child_pos(size_t parent_pos) const {
        return parent_pos * 2 + 2;
    }

    void sift_down(size_t pos) {
        size_t max_index = pos;
        size_t l = left_child_pos(pos);
        if (l < _data.size() && _data[l] > _data[max_index]) {
            max_index = l;
        }
        size_t r = right_child_pos(pos);
        if (r < _data.size() && _data[r] > _data[max_index]) {
            max_index = r;
        }
        if (max_index != pos) {
            std::swap(_data[pos], _data[max_index]);
            sift_down(max_index);
        }
    }

    void sift_up(size_t pos) {
        while (pos > 0 && _data[parent_pos(pos)] < _data[pos]) {
            std::swap(_data[parent_pos(pos)], _data[pos]);
            pos = parent_pos(pos);
        }
    }
};


#endif //PROJECT_HEAP_H
