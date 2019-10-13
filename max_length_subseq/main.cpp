//
// Created by yogi on 2019/9/22.
//
#include <iostream>
#include "dp.cpp"
#include "dp2.cpp"
#include "array_utils.h"

using namespace std;

int main () {
    int n = 20;

    string s1 = ArrayUtils::genrateRandomString(n);
    string s2 = ArrayUtils::genrateRandomString(n);
    string s3 = ArrayUtils::randomSwap(s1, 20);

    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;

    cout << dp::LCS(s1, s2) << endl;
    cout << dp::LCS(s1, s3) << endl;

    cout << dp2::LCS(s1, s2) << endl;
    cout << dp2::LCS(s1, s3) << endl;

    return 0;
}
