//
// Created by yogi on 2019/10/22.
//
#include <iostream>
#include <vector>
#include "array_utils.h"

using namespace std;

namespace IterativeBacktrack{
    vector<int> res;

    void print_res () {
        ArrayUtils::printVector(res);
    }

    bool constraint (int n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (res[i] == res[j]) {
                    return false;
                }

                if (abs((res[i] - res[j])) ==  i - j) {
                    return false;
                }
            }
        }

        return true;
    }

    void queenProblem (int n) {
        int t = 0;

        const int initVal = 0;
        res = vector<int>(n, initVal);

        while (t >= 0) {
            while (++res[t] <= n) {
                if (constraint(t+1)) {
//                    print_res();
                    if (t==n-1) print_res();
                    else {
                        t++;
                    }
                }
            }
            res[t] = initVal;
            t--;
        }
    }
}
