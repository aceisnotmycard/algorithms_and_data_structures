#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
    int key;
    int left;
    int right;

    Node() : key(0), left(-1), right(-1) {}

    Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool check(int node, const vector<Node> &tree, int min, int max) {
    bool left = true;
    if (tree[node].left != -1) {
        left = check(tree[node].left, tree, min, tree[node].key);
    }

    bool right = true;
    if (tree[node].right != -1) {
        right = check(tree[node].right, tree, tree[node].key, max);
    }
    return left && right && tree[node].key < max && tree[node].key > min;
}

bool IsBinarySearchTree(const vector<Node> &tree) {
    if (tree.empty()) {
        return true;
    }
    return check(0, tree, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
}

int main() {
    int nodes;
    cin >> nodes;
    vector<Node> tree;
    for (int i = 0; i < nodes; ++i) {
        int key, left, right;
        cin >> key >> left >> right;
        tree.push_back(Node(key, left, right));
    }
    if (IsBinarySearchTree(tree)) {
        cout << "CORRECT" << endl;
    } else {
        cout << "INCORRECT" << endl;
    }
    return 0;
}
