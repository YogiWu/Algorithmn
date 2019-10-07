### HOMEWORK REPORT

---

#### 个人信息

 姓名 | 学号 
 :---: | :---:
 吴宇杰 | 19215028
 
#### 题目内容
 
    给定一个数组和k，线性时间内找出第k大的数
    
#### 解题思路

    通过一个粗略估算中位数的算法将原数组分割为两半
    通过k与中位数做比较直接在其中一半进行搜索,实现分治
    
#### 实现代码

```c++
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
```

#### 测试样例

    输入:
    array: 183 86 177 115 193 135 186 92 49 21 162 27 90 59 163 126 140 26 172 136 11 168 167 29 182 130 62 123 67 135 129 2 22 58 69 167 193 56 11 42 29 173 21 119 184 137 198 124 115 170 13 126 91 180 156 73 62 170 196 81 105 125 84 127 136 105 46 129 113 57 124 95 182 145 14 167 34 164 43 150 87 8 76 178 188 184 3 51 154 199 132 60 76 168 139 12 26 186 94 139 195 170 34 178 67 1 97 102 117 92 52 156 101 80 86 41 65 89 44 19 40 129 31 117 97 171 81 75 109 127 167 56 97 153 186 165 106 83 19 24 128 71 132 29 103 19 70 168 108 115 140 149 196 123 18 45 46 51 121 155 179 88 164 28 41 150 193 100 34 164 124 114 187 56 143 91 27 165 59 136 32 151 37 28 75 7 74 121 58 195 29 37 35 193 18 28 143 11 128 129  
    k: 100
    输出:
    105

#### 总结

    