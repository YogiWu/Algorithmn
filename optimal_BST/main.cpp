//
// Created by yogi on 2019/9/27.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "array_utils.h"

#include "recursive.cpp"
#include "dp.cpp"

using namespace std;

int main ()
{
    const int n = 10;

    vector<int> keyList = ArrayUtils::genrateRandomVector(n, 0, 100);
    sort(keyList.begin(), keyList.end());

    ArrayUtils::printVector(keyList);

    vector<int> proList = ArrayUtils::genrateRandomVector(2*n+1, 0, 100);
    double total = accumulate(proList.begin(), proList.end(), 0);

    vector<double> keyProList;
    for (auto &x:proList) {
        keyProList.push_back(x/total);
    }

    ArrayUtils::printVector(keyProList);
    cout << accumulate(keyProList.begin(), keyProList.end(), 0.0) << endl;

    cout << recursive::optimal_BST(keyList, keyProList, 0, keyList.size()-1) << endl;
    cout << dp::optimal_BST(keyList, keyProList) << endl;

    dp::print_BST();

    return 0;
}
