//
// Created by yogi on 2019/9/27.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include "array_utils.h"

using namespace std;

int getDiamond1 (vector<int>& diamond) {
//    return diamond[0];
    const int k = diamond.size() / exp(1);

    vector<int> ref;

    for (int i=0; i<diamond.size()/k; i++) {
        ref.push_back(diamond[i]);
    }

    sort(ref.begin(), ref.end());

    for (auto &x:diamond) {
        if (x > *(ref.rbegin())) {
            return x;
        }
    }

    return *(diamond.rbegin());
}

int diamondResult () {
    vector<int> diamond = ArrayUtils::genrateRandomVector(100, 0, 200, true);

    int res = getDiamond1(diamond);

    ArrayUtils::printVector(diamond);

    sort(diamond.begin(), diamond.end());

    return find(diamond.begin(), diamond.end(), res) - diamond.begin();
}

int main ()
{
    const int group = 1000;

    vector<int> res;
    for (int i=0; i< group; i++) {
        res.push_back(diamondResult());
    }

    double mean = accumulate(res.begin(), res.end(), 0) / res.size();
    cout << mean << endl;

    double accum = 0;
    for_each(res.begin(), res.end(), [&accum, &mean](double n) {
        accum += pow(n - mean, 2);
    });
    double bias = sqrt(accum) / res.size();
    cout << bias << endl;

    return 0;
}
