//
// Created by yogi on 2019/9/15.
//
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> res;

void num_split(int n, int u, vector<int> cur_list)
{
    if (n == 1) {
        cur_list.push_back(1);
        res.push_back(cur_list);
        return;
    }
    if (u == 1) {
        for (int i=0;i<n;i++){
            cur_list.push_back(1);
        }
        res.push_back(cur_list);
        return;
    }
    if (u > n) {
        num_split(n, n, cur_list);
        return;
    };
    if (n == u) {
        vector<int> next_list(cur_list);
        cur_list.push_back(n);
        res.push_back(cur_list);
        num_split(n, n-1, next_list);
        return;
    }
    num_split(n, u-1, cur_list);
    cur_list.push_back(u);
    num_split(n-u, u, cur_list);
}

int main() {
    int rangeNum;
    cin >> rangeNum;

    num_split(rangeNum, rangeNum, {});

    for(auto &list:res) {
        for(auto &x:list) {
            &x != &(*list.rbegin()) ?
                cout << x << "+" : cout << x;
        }
        cout << endl;
    }
}