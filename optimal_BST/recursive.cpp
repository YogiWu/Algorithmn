//
// Created by yogi on 2019/10/14.
//
#include <iostream>
#include <cassert>
#include <limits>

namespace recursive{
    double optimal_BST (const vector<int> &keyList, const vector<double> &keyProList, int l, int r) {
        assert(l >=0 && l <= r && r < keyList.size());
        if (l == r) {
            return keyProList[2*l+1]*2+keyProList[2*l]+keyProList[2*(l+1)];
        }

        if (l == r -1) {
            double left_res = optimal_BST(keyList, keyProList, l, l);
            double right_res = optimal_BST(keyList, keyProList, r, r);

            double left_root_res = left_res + right_res + keyProList[2*(r+1)] + keyProList[2*r+1] - keyProList[2*r];
            double right_root_res = left_res + right_res + keyProList[2*l] + keyProList[2*l+1] - keyProList[2*(l+1)];

            return min(left_root_res, right_root_res);
        }

        double min = numeric_limits<double>::max();
        for(int i=l+1; i<r; i++) {
            double res = optimal_BST(keyList, keyProList, l, i-1) + optimal_BST(keyList, keyProList, i+1, r) + accumulate(keyProList.begin()+l*2, keyProList.begin()+r*2+3, 0.0);

            min = res < min ? res : min;
        }

        return min;
    }
}
