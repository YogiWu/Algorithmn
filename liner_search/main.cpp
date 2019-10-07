//
// Created by yogi on 2019/9/22.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include "array_utils.h"

using namespace std;

const int GROUP_COUNT = 5;


int find_middle (vector<int> target) {
    // return the middle number in target
    if (target.size()/GROUP_COUNT <= 1) {
        sort(target.begin(), target.end());
        int middle = target.size() % 2 ? target.size() /2 + 1 : target.size() /2;
        return target[middle-1];
    }

    vector<int> child;

    for (int i = 0; i<target.size()/GROUP_COUNT;i++)
    {
        int end = (i+1)*GROUP_COUNT >= target.size()-1 ? target.size() - 1 : (i+1) * GROUP_COUNT;
        sort(target.begin()+i*GROUP_COUNT, target.begin() + end);
        child.push_back(*(target.begin()+i*GROUP_COUNT+GROUP_COUNT/2));
    }

    return find_middle(child);
}

int liner_search (vector<int> target, int k)
{
    assert(k > 0);
    int middle = find_middle(target);
    int pre=0, i=0, post = target.size() - 1;

    while(i <= post) {
        if (target[i] < middle) {
            swap(target[i], target[pre]);
            i++;
            pre++;
        } else if (target[i] == middle) {
            i++;
        } else if (target[i] > middle) {
            swap(target[i], target[post]);
            post--;
        }
    }

    // k begin from 1，and index begin from 0
    if (k-1 < pre) {
        vector<int> tmp(target.begin(), target.begin()+pre);
        return liner_search(tmp, k);
    } else if (k-1 > post) {
        vector<int> tmp(target.begin()+post+1, target.end());
        return liner_search(tmp, k-post-1);
    } else {
        return target[pre];
    }
}

int main () {
    const int LIST_LENGTH = 200;

    const int k = LIST_LENGTH /2;

    vector<int> test_list = ArrayUtils::genrateRandomVector(LIST_LENGTH, 0, LIST_LENGTH);

    ArrayUtils::printVector(test_list);

    cout << liner_search(test_list, k) << endl;

    sort(test_list.begin(), test_list.end());
    ArrayUtils::printVector(test_list);
    cout << test_list[k-1];

    return 0;
}
