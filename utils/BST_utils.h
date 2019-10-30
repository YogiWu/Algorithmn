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
    class BSTNode{
    public:
        T key;
        BSTNode* left;
        BSTNode* right;

        BSTNode (T key) {
            this -> key = key;
            left = NULL;
            right = NULL;
        }
    };

    static void clearBST(BSTNode* root) {
        if (root) {
            clearBST(root->left);
            clearBST(root->right);

            delete(root);
            root = NULL;
        }
    }

    static BSTNode* generateBSTNode(T key) {
        return new BSTNode(key);
    }

    static void LDR(BSTNode* rootNode, void fn(BSTNode*)) {
        if (rootNode == NULL) return;
        LDR(rootNode->left, fn);
        fn(rootNode);
        LDR(rootNode->right, fn);
    }

    static void LDR(BSTNode* rootNode, void nodeFn(BSTNode*), void hookFn(int)) {
        if (rootNode == NULL) return;
        hookFn(0);
        LDR(rootNode->left, nodeFn, hookFn);
        hookFn(1);
        nodeFn(rootNode);
        hookFn(2);
        LDR(rootNode->right, nodeFn, hookFn);
        hookFn(3);
    }

    static void print_BST (BSTNode* root) {
//        LDR(root, [](BSTNode *node) { cout << node->key; }, [](int hookType) {
//            switch (hookType) {
//                case 0:
//                    cout << "(";
//                    break;
//                case 1:
//                    cout << ")";
//                    break;
//                case 2:
//                    cout << "(";
//                    break;
//                case 3:
//                    cout << ")";
//                    break;
//            }
//        });
        if (root == NULL) return;
        cout << "(";
        print_BST(root->left);
        cout << ")";

        cout << "(" << root->key << ")";

        cout << "(";
        print_BST(root->right);
        cout << ")";
    }
};

#endif //ALGORITHM_BST_UTILS_H
