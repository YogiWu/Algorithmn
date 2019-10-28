//
// Created by yogi on 2019/10/22.
//
#include <iostream>
#include <vector>
#include "array_utils.h"

using namespace std;

namespace Backtrack{
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

    void backtrack (int t) {
        const int N = res.size();

        if (t == N) {
            print_res();
        } else {
            for (int i = 1; i <= N; ++i) {
                res[t] = i;
                if (constraint(t+1)) {
                    backtrack(t+1);
                }
            }
        }
    }

    void queenProblem (int n) {
        res = vector<int>(n, 0);

        backtrack(0);
    }
}
