//
// Created by yogi on 2019/10/14.
//

#ifndef ALGORITHM_BST_UTILS_H
#define ALGORITHM_BST_UTILS_H

#include <iostream>

using namespace std;

template <typename T>
class BSTUtils{
public:
    static class BSTNode{
    public:
        T key;
        BSTNode* left;
        BSTNode* right;

        BSTNode (T key) {
            key = key;
            left = NULL;
            right = NULL;
        }
    };

    static BSTNode* generateBSTNode(T key) {
        return BSTNode(key);
    }

    static void LDR(BSTNode* rootNode, void fn(BSTNode*)) {
        if (rootNode == NULL) return;
        LDR(rootNode->left, fn);
        fn(rootNode);
        LDR(rootNode->right, fn);
    }
};

#endif //ALGORITHM_BST_UTILS_H
