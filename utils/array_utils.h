//
// Created by yogi on 2019/9/22.
//

#ifndef ALGORITHM_ARRAY_UTILS_H
#define ALGORITHM_ARRAY_UTILS_H

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class ArrayUtils{
public:
    static vector<int> genrateRandomVector(int n, int l, int r, int change= false)
    {
        vector<int> res;

        if (change) srand(clock());
        for (int i = 0; i <n ; ++i) {
            res.push_back(rand() % (r - l) + l);
        }

        return res;
    }

    template <typename T>
    static void printVector (vector<T> &target) {
        for(auto &x:target) {
            cout << x << " ";
        }
        cout << endl;
    }
};

#endif //ALGORITHM_ARRAY_UTILS_H
