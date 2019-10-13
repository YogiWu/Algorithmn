//
// Created by yogi on 2019/9/22.
//
#include <iostream>
#include <vector>

using namespace std;

namespace recursive{
    int LCS (string s1, string s2) {
        if (s1.size() == 1) {
            return s2.find_first_of(s1) != -1;
        }
        if (s2.size() == 1) {
            return s1.find_first_of(s2) != -1;
        }

        if (s1[0] == s2[0]) {
            return LCS(s1.substr(1), s2.substr(1)) + 1;
        } else {
            return max(LCS(s1.substr(1), s2), LCS(s1, s2.substr(1)));
        }
    }
}
