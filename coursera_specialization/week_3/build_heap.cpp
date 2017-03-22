#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
private:
    vector<int> data_;
    vector<pair<int, int> > swaps_;

    void WriteResponse() const {
        cout << swaps_.size() << "\n";
        for (int i = 0; i < swaps_.size(); ++i) {
            cout << swaps_[i].first << " " << swaps_[i].second << "\n";
        }
    }

    void ReadData() {
        int n;
        cin >> n;
        data_.resize(n);
        for (int i = 0; i < n; ++i) cin >> data_[i];
    }

    void GenerateSwaps() {
        swaps_.clear();
        for (int i = data_.size() / 2; i >= 0; i--) {
            siftDown(i);
        }
    }

    void siftDown(int i) {
        auto max_index = i;
        auto l = leftChild(i);
        auto r = rightChild(i);
        if (l < data_.size() && data_[l] < data_[max_index]) {
            max_index = l;
        }
        if (r < data_.size() && data_[r] < data_[max_index]) {
            max_index = r;
        }
        if (max_index == i) {
            return;
        }
        std::swap(data_[i], data_[max_index]);
        swaps_.push_back(make_pair(i, max_index));
        siftDown(max_index);
    }

    inline int leftChild(int i) {
        return i * 2 + 1;
    }

    inline int rightChild(int i) {
        return i * 2 + 2;
    }

    inline int parent(int pos) {
        return pos / 2;
    }

public:
    void Solve() {
        ReadData();
        GenerateSwaps();
        WriteResponse();
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    HeapBuilder heap_builder;
    heap_builder.Solve();
    return 0;
}
