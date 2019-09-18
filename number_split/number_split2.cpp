//
// Created by yogi on 2019/9/16.
//
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<vector<int>> res;

void split(vector<int> pre, int num, int max)
{
    if (num <= max) {
        pre.push_back(num);
        res.push_back(pre);
        pre.pop_back();
        for (int i=num - 1; i > 0; i--) {
            pre.push_back(i);
            split(pre, num -i, i);
            pre.pop_back();
        }
    } else {
        for(int i=max; i>0; i--) {
            pre.push_back(i);
            split(pre, num -i , i);
            pre.pop_back();
        }
    }
}

void split(int n)
{
    split({}, n, n);
}

int main()
{
    int rangeNum;
    cin >> rangeNum;

    split(rangeNum);

    for(auto &list:res) {
        for(auto &x:list) {
            &x != &(*list.rbegin()) ?
            cout << x << "+" : cout << x;
        }
        cout << endl;
    }
}
