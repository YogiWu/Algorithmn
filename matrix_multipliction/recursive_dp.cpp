//
// Created by yogi on 2019/10/11.
//
#include <iostream>
#include <vector>
#include "array_utils.h"

using namespace std;

vector<int> dp;

void minMatrixMulti (int l, int r) {

}

int main () {
    int n = 5;

    // generate n matrix row number and column number
    vector<int> matrix = ArrayUtils::genrateRandomVector(n+1, 10, 100);
    ArrayUtils::printVector(matrix);

    for (int i=0; i<n; i++) {
        dp.push_back(0);
    }


    return 0;
}