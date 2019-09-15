//
// Created by yogi on 2019/9/15.
//
#include <iostream>
#include <vector>
using namespace std;

void combination(vector<int> &nums, int u, int state) {
    int n = nums.size();
    if (u == n) {
        for(int i = 0; i< n; i++) {
            if (state >> i & 1) {
                cout << nums[i];
            }
        }
        cout << endl;
        return;
    }
    combination(nums, u+1, state);
    combination(nums, u+1, state | 1 << u);
}

int main()
{
    int rangeNum;
    cin >> rangeNum;
    vector<int> nums;
    for (int i =1; i<= rangeNum; i++) {
        nums.push_back(i);
    }

    combination(nums, 0, 0);
    return 0;
};
