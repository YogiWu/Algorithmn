//
// Created by yogi on 2019/10/11.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include "array_utils.h"

using namespace std;

vector<int> matrix;
vector<int> dp;

int findNum (int n, int direction) {
    n += direction;
    while (n >= 0 && n <= matrix.size()-1) {
        if (matrix[n] != 0) {
            return matrix[n];
        }
        n += direction;
    }
}

int minMatrixMulti () {
    int n = matrix.size() -1;

    for (int i=1;i<n;i++) {
        dp.push_back(i);
    }

    sort(dp.begin(), dp.end(), [](int l, int r) { return matrix[l] > matrix[r]; });

    int res = 0;
    for (auto &x:dp) {
        res += findNum(x, -1) * matrix[x] * findNum(x, 1);
        matrix[x] = 0;
    }

    return res;
}

void printRes () {
    int n = matrix.size() -1;

    vector<string> res(n+2, "");

    for (auto &x:dp) {
        res[x-1] += "(";
        res[x+1] += ")";
    }
}

int main () {
    int n = 5;

    // generate n matrix row number and column number
    matrix = ArrayUtils::genrateRandomVector(n+1, 10, 100);
    ArrayUtils::printVector(matrix);

    cout << minMatrixMulti() << endl;

    printRes();

    return 0;
}