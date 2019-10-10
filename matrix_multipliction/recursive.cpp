//
// Created by yogi on 2019/9/22.
//
#include <iostream>
#include <vector>
#include "array_utils.h"

using namespace std;

int minMatrixMulti (vector<int> &matrix) {
    int min = -1;

    if (matrix.size() == 3) {
        return matrix[0] * matrix[1] * matrix[2];
    }

    int n = matrix.size() -1;
    for (int i=0;i < n-1;i++) {
        vector<int> tmp(matrix);
        tmp.erase(tmp.begin()+i+1);

        int res = minMatrixMulti(tmp) + matrix[i]* matrix[i+1] * matrix[i+2];
        if (min == -1) {
            min = res;
        } else {
            if (res < min) {
                min = res;
            }
        }
    }
    return min;
}


int main () {
    int n = 5;

    // generate n matrix row number and column number
    vector<int> matrix = ArrayUtils::genrateRandomVector(n+1, 10, 100);
    ArrayUtils::printVector(matrix);

    cout << minMatrixMulti(matrix) << endl;


    return 0;
}
