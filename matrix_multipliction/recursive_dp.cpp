//
// Created by yogi on 2019/9/22.
//

// can't use dp because the optimal solution of the sub problem can't use in the original problem
#include <iostream>
#include <vector>
#include "array_utils.h"

using namespace std;

vector<int> matrix;

int minMatrixMulti (int state) {
    int min = -1;

    if (matrix.size() == 3) {
        return matrix[0] * matrix[1] * matrix[2];
    }

//    int n = matrix.size() -1;
//    for (int i=0;i < n-1;i++) {
//        vector<int> tmp(matrix);
//        tmp.erase(tmp.begin()+i+1);
//
//        int res = minMatrixMulti(tmp) + matrix[i]* matrix[i+1] * matrix[i+2];
//        if (min == -1) {
//            min = res;
//        } else {
//            if (res < min) {
//                min = res;
//            }
//        }
//    }
    return min;
}

int noUse (int n, int direction, int state) {
    int res = 1 << n;

    res = res << direction;

    int times = 0;
    while (res >0 && res < state) {
        if (res | state == 0) {
            return n + times*direction -1;
        }
        res >> direction;
        times++;
    }

    return -1;
}

int main () {
    int n = 10;

    // generate n matrix row number and column number
    matrix = ArrayUtils::genrateRandomVector(n+1, 10, 100);
    ArrayUtils::printVector(matrix);

    cout << minMatrixMulti(0) << endl;

    cout << noUse(2, 1, 34);

    return 0;
}
