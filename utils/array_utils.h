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
    static vector<int> genrateRandomVector(int n, int l, int r, bool change= false)
    {
        vector<int> res;

        if (change) srand(clock());
        for (int i = 0; i <n ; ++i) {
            res.push_back(rand() % (r - l) + l);
        }

        return res;
    }

    static string genrateRandomString (int n, bool lower_only= true, bool change = false)
    {
        string s;

        if (change) srand(clock());
        for (int i = 0; i < n; ++i) {
            char temp = 'a' + rand() % 26;

            if (!lower_only & rand() % 2) {
                temp = toupper(temp);
            }

            s += temp;
        }

        return s;
    }

    template <typename T>
    static T randomSwap (T &target, int ratio) {
        T newTarget = target;

        int total = newTarget.size();
        int n = total * ratio / 100;

        for (int i = 0; i < n; ++i) {
            swap(newTarget[rand() % total], newTarget[rand() % total]);
        }

        return newTarget;
    }

    template <typename T>
    static void printVector (vector<T> &target) {
        for(auto &x:target) {
            cout << x << " ";
        }
        cout << endl;
    }

    template <typename T>
    static void printVector (vector<vector<T>> &target) {
        for(auto &x:target) {
            printVector(x);
        }
    }
};

#endif //ALGORITHM_ARRAY_UTILS_H
