//
// Created by yogi on 2019/9/22.
//
#include <iostream>
#include <vector>
#include "array_utils.h"

using namespace std;

vector<vector<int>> dp;

vector<int> matrix;

int minMatrixMulti (int n) {
    int res, tmp;

    // i is the step
    for (int i=0; i<n; i++) {
        for (int j=0; i+j<n; j++) {
            if (i == 0) {
                res = 0;
            } else {
                res = -1;
                // k attempt to split the seq from j to i+j
                for (int k=j; k < i+j; k++) {
                    tmp = dp[j][k] + dp[k+1][i+j] + matrix[j] * matrix[k+1]*matrix[i+j+1];
                    if (res == -1) {
                        res = tmp;
                    } else if (tmp < res) res = tmp;
                }
            }

            dp[j][i+j] = res;
        }
    }
    ArrayUtils::printVector(dp);

    return dp[0][n-1];
}

void printRes (int l, int r) {
    if (l == r) {
        cout <<  l;
        return;
    }
    int k = l;
    while (k < r) {
        if (dp[l][k] + dp[k+1][r] + matrix[l] * matrix[k+1] * matrix[r+1] == dp[l][r]) {
            break;
        }
        k++;
    }
    cout << "(";
    printRes(l, k);
    cout << "*";
    printRes(k+1, r);
    cout << ")";
}

int main () {
    int n = 10;

    // generate n matrix row number and column number
    matrix = ArrayUtils::genrateRandomVector(n+1, 10, 100);
    ArrayUtils::printVector(matrix);

    for(int i=0; i<n; i++) {
        dp.push_back(vector<int>(n, 0));
    }

    cout << minMatrixMulti(n) << endl;

    printRes(0, n-1);

    return 0;
}
