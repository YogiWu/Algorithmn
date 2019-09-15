//
// Created by yogi on 2019/9/14.
//

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> print_arrage(vector<int> &nums, int n)
{
    vector<vector<int>> res;
    if (n == 0) {
        res.push_back({nums[0]});
        return res;
    }
    auto sub_res = print_arrage(nums, n-1);
    for(auto &x:sub_res) {
       for(int i=0;i<x.size()+1;i++){
           vector<int> tmp(x);
           tmp.insert(tmp.begin()+i, nums[n]);
           res.push_back(tmp);
       }
    }
    return res;
}

int main ()
{
    int rangeNum;
    cin >> rangeNum;
    vector<int> nums;
//    cout << nums[rangeNum-1];
    for (int i =1; i<= rangeNum; i++) {
        nums.push_back(i);
    }
    auto res = print_arrage(nums, rangeNum-1);
    for (auto &item:res) {
        for (auto &x:item) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}