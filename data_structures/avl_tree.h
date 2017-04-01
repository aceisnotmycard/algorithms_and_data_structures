//
// Created by Sergey Bogolepov on 31/03/2017.
//

#ifndef ALGORITHMS_AND_DATA_STRUCTURES_AVL_TREE_H
#define ALGORITHMS_AND_DATA_STRUCTURES_AVL_TREE_H

class AvlTree {
public:
    struct Node {
        int key;
        unsigned char height = 1;
        Node* left = nullptr;
        Node* right = nullptr;

        Node(int k) : key(k) {}
    };

    unsigned char height(const Node* node) {
        return node == nullptr ? 0 : node->height;
    }

    int balance_factor(const Node& node) {
        return height(node->right) - height(node->left);
    }

    void fix_height(const Node& node) {
        auto left_height = height(node.left);
        auto right_height = height(node.right);
        node.height = std::max(left_height, right_height) + 1;
    }

    Node* rotate_right(const Node& p) {
        Node* q = p.left;
        p.left = q->right;
        q->right = p;
        fix_height(q);
        fix_height(p);
        return q;
    }

    Node* rotate_left(const Node& p) {

    }
};

#endif //ALGORITHMS_AND_DATA_STRUCTURES_AVL_TREE_H
