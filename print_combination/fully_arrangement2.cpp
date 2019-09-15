//
// Created by yogi on 2019/9/15.
//

#include <iostream>
#include <vector>
using namespace std;

void print_arrage(vector<int> nums, int n, int length)
{
    if (n == length) {
        for (auto &x: nums) {
            cout << x << " ";
        }
        cout << endl;
        return;
    }
    for(int i = n;i <= length;i++)
    {
//        cout << nums[i] << " ";
        swap(nums[i], nums[n]);
        print_arrage(nums, n+1, length);
        swap(nums[n], nums[i]);
    }
}

int main ()
{
    int rangeNum;
    cin >> rangeNum;
    vector<int> nums;

    for (int i =1; i<= rangeNum; i++) {
        nums.push_back(i);
    }
    print_arrage(nums,0, rangeNum-1);
}