//
// Created by yogi on 2019/10/13.
//
#include <iostream>
#include <vector>

using namespace std;

namespace dp2{
    vector<vector<int>> dp;

    int LCS (string s1, string s2) {
        dp.clear();

        // make sure using less space
        if(s1.size() > s2.size()) { swap(s1, s2); }

        dp.push_back(vector<int>(s1.size(), 0));
        dp.push_back(vector<int>(s1.size(), 0));

        for (int i = 0; i < s1.size(); ++i) {
            if (i == 0) {
                dp[0][i] = s1[0] == s2[0];
            } else {
                dp[0][i] = dp[0][i-1] | s1[i] == s2[0];
            }
        }


        for (int i = 1; i < s2.size(); ++i) {
            dp[i % 2][0] = dp[(i+1) % 2][0] | s2[i] == s1[0];
            for (int j = 1; j < s1.size(); ++j) {
                dp[i % 2][j] = s1[j] == s2[i] ? dp[(i+1) % 2][j-1] + 1 : max(dp[(i+1) % 2][j], dp[i % 2][j - 1]);
            }
        }


        return dp[(s1.size()+1)%2][s1.size()-1];
    }
}
