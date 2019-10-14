//
// Created by yogi on 2019/10/14.
//
#include <iostream>
#include <numeric>
#include <limits>
#include <vector>
#include "array_utils.h"
#include "BST_utils.h"

using namespace std;

namespace dp{
    vector<vector<double>> dp;
    vector<int> _keyList;
    vector<double> _keyProList;
    vector<double> _keyProSumList;

    double optimal_BST (const vector<int> &keyList, const vector<double> &keyProList) {
        dp = vector<vector<double>> (keyList.size(), vector<double >(keyList.size(),0.0));

        _keyList = keyList;
        _keyProList = keyProList;

        for (int i = 0; i < keyProList.size(); ++i) {
            _keyProSumList.push_back(accumulate(keyProList.begin(), keyProList.begin()+i+1, 0.0));
        }

        for (int i = 0; i < keyList.size(); ++i) {
            dp[i][i] = keyProList[2*i] + 2*keyProList[2*i+1] + keyProList[2*(i+1)];
        }

        for (int i = 1; i < keyList.size(); ++i) {
            for (int j = 0; i+j < keyList.size(); ++j) {
                if (i == 1) {
                    double left_root = dp[j][j] + dp[j+1][j+1] - keyProList[2*(j+1)] + keyProList[2*(j+1)+1] + keyProList[2*(j+2)];
                    double right_root = dp[j][j] + dp[j+1][j+1] + keyProList[2*j] + keyProList[2*j+1] - keyProList[2*(j+1)];

                    dp[j][i+j] = min(left_root, right_root);
                } else {
                    double minRes = numeric_limits<double>::max();

                    for (int k=j+1; k < i+j; ++k) {
                        minRes = min(minRes, dp[j][k-1] + dp[k+1][i+j] + _keyProSumList[2*(i+j+1)] - _keyProSumList[2*j-1]);
                    }

                    dp[j][i+j] = minRes;
                }
            }
        }

        return dp[0][keyList.size() - 1];
    }

    BSTUtils<int>::BSTNode* generateBST (int l, int r) {
        if (l == r) {
            return BSTUtils<int>::generateBSTNode(_keyList[l]);
        }

        if (l+1 == r) {
            double left_root = dp[l][l] + dp[r][r] - _keyProList[2*r] + _keyProList[2*r+1] + _keyProList[2*(r+1)];
            double right_root = dp[l][l] + dp[r][r] + _keyProList[2*l] + _keyProList[2*l+1] - _keyProList[2*(l+1)];

            bool left = dp[l][r] - left_root < dp[l][r] - right_root;
            BSTUtils<int>::BSTNode* root;

            if (left) {
                root = BSTUtils<int>::generateBSTNode(_keyList[l]);
                root->right = BSTUtils<int>::generateBSTNode(_keyList[r]);
            } else {
                root = BSTUtils<int>::generateBSTNode(_keyList[r]);
                root->left = BSTUtils<int>::generateBSTNode(_keyList[l]);
            }

            return root;
        }

        double minRes = numeric_limits<double>::max();
        int minKey = 0;
        for (int k = l+1; k<r; k++) {
            double res = dp[l][r] - dp[l][k-1] - dp[k+1][r] - _keyProSumList[2*(r+1)] + _keyProSumList[2*l - 1];

            if (res < minRes) {
                minRes = res;
                minKey = k;
            }
        }

        auto root = BSTUtils<int>::generateBSTNode(_keyList[minKey]);
        root->left = generateBST(l, minKey-1);
        root->right = generateBST(minKey+1, r);

        return root;
    }

    void print_BST () {
        auto root = generateBST(0, _keyList.size()-1);

        BSTUtils<int>::print_BST(root);
    }
}
