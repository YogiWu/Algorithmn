//
// Created by yogi on 2019/10/13.
//
#include <iostream>
#include <vector>

using namespace std;

namespace dp{
    vector<vector<int>> dp;

    int LCS (string s1, string s2) {
        dp.clear();

        for (int i = 0; i < s1.size(); ++i) {
            if (i == 0) {
                dp.push_back(vector<int>(s2.size(), s1[0] == s2[0]));
            } else {
                dp.push_back(vector<int>(s2.size(), dp[i-1][0] | s1[i] == s2[0]));
            }
        }

        for (int j = 1; j < s2.size(); ++j) {
            dp[0][j] = dp[0][j-1] | s1[0] == s2[j];
        }

        for (int i = 1; i < s1.size(); ++i) {
            for (int j = 1; j < s2.size(); ++j) {
                dp[i][j] = s1[i] == s2[j] ? dp[i-1][j-1] + 1 : max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[s1.size()-1][s2.size()-1];
    }
}
