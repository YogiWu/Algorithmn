//
// Created by yogi on 2019/10/30.
//
#include <vector>
#include <unordered_map>
#include "BST_utils.h"

using namespace std;

namespace Backtrack{
    typedef BSTUtils<string>::BSTNode BSTNode;
    BSTNode *root;
    vector<int> res;
    vector<BSTNode*> cardList;
    unordered_map<string, int (*)(int, int)> opList;

    void printRes (BSTUtils<string>::BSTNode* root) {
        if (root->left == NULL && root->right == NULL) {
            cout << root->key;
        } else {
            cout << "(";
            printRes(root->left);
            cout << root->key;
            printRes(root->right);
            cout << ")";
        }
//        BSTUtils<string>::LDR(root, [](BSTNode *node) { cout << node->key; }, [](int hookType) {
//            switch (hookType) {
//                case 0:
//                    cout << "(";
//                    break;
//                case 3:
//                    cout << ")";
//                    break;
//            }
//        });
    }

    int getRes (BSTUtils<string>::BSTNode *rt) {
        if (!rt->left && !rt->right) {
            return stoi(rt->key);
        } else {
            return opList[rt -> key](getRes(rt->left), getRes(rt->right));
        }
    }

    void backtrack (vector<BSTNode*> &ls, vector<int> &res) {
        if (ls.size() == 1) {
            if (getRes(ls[0]) == 24) {
                printRes(ls[0]);
                cout << endl;
            }
        } else {
            for (int i = 0; i < ls.size(); ++i) {
                for (int j = i+1; j < ls.size(); ++j) {
                    int left, right;
                    for (auto &op:opList) {
                        if (res[i] > res[j]) {
                            left = i, right = j;
                        } else {
                            right = i, left = j;
                        }

                        int ans = op.second(res[left], res[right]);
                        if (ans != -1) {
                            auto rootNode = new BSTNode(op.first);

                            rootNode->left = ls [left];
                            rootNode->right = ls[right];

                            vector<BSTNode*> subls;
                            vector<int> subres;

                            for (int k = 0; k < ls.size(); ++k) {
                                if (k != left && k != right) {
                                    subls.push_back(ls[k]);
                                    subres.push_back(res[k]);
                                }
                            }

                            subls.push_back(rootNode);
                            subres.push_back(ans);
                            backtrack(subls, subres);
                            subls.clear();
                            subres.clear();

                            delete(rootNode);
                            rootNode = NULL;
                        }
                    }
                }
            }
        }
    }

    void findTwentyFour(vector<int> cl, unordered_map<string, int(*) (int, int)> ol) {
        const int ans = 24;

        for(auto &num:cl) {
            cardList.push_back(BSTUtils<string>::generateBSTNode(to_string(num)));
            res.push_back(num);
        }
        opList = ol;

        backtrack(cardList, res);
    }
}
