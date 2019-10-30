### HOMEWORK REPORT

---

#### 个人信息

 姓名 | 学号 
 :---: | :---:
 吴宇杰 | 19215028
 
#### 题目内容
 
    输出n皇后问题的合法解
    
#### 解题思路

    通过回溯法, 在合法值中遍历,尝试每个值在子问题中找到合法解,然后回溯到上层完成遍历
    
#### 实现代码

```c++
// main.cpp
#include "iterative_backtrack.cpp"
#include "backtrack.cpp"

int main ()
{
    const int N = 8;

    IterativeBacktrack::queenProblem(N);
//    Backtrack::queenProblem(N);
    
    return 0;
}

// backtrack.cpp
#include <iostream>
#include <vector>
#include "array_utils.h"

using namespace std;

namespace IterativeBacktrack{
    vector<int> res;

    void print_res () {
        ArrayUtils::printVector(res);
    }

    bool constraint (int n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (res[i] == res[j]) {
                    return false;
                }

                if (abs((res[i] - res[j])) ==  i - j) {
                    return false;
                }
            }
        }

        return true;
    }

    void queenProblem (int n) {
        int t = 0;

        const int initVal = 0;
        res = vector<int>(n, initVal);

        while (t >= 0) {
            while (++res[t] <= n) {
                if (constraint(t+1)) {
//                    print_res();
                    if (t==n-1) print_res();
                    else {
                        t++;
                    }
                }
            }
            res[t] = initVal;
            t--;
        }
    }
}
```

#### 测试样例

    输入： 8
    
    输出：
    1 5 8 6 3 7 2 4 
    1 6 8 3 7 4 2 5 
    1 7 4 6 8 2 5 3 
    1 7 5 8 2 4 6 3 
    2 4 6 8 3 1 7 5 
    2 5 7 1 3 8 6 4 
    2 5 7 4 1 8 6 3 
    2 6 1 7 4 8 3 5 
    2 6 8 3 1 4 7 5 
    2 7 3 6 8 5 1 4 
    2 7 5 8 1 4 6 3 
    2 8 6 1 3 5 7 4 
    3 1 7 5 8 2 4 6 
    3 5 2 8 1 7 4 6 
    3 5 2 8 6 4 7 1 
    3 5 7 1 4 2 8 6 
    3 5 8 4 1 7 2 6 
    3 6 2 5 8 1 7 4 
    3 6 2 7 1 4 8 5 
    3 6 2 7 5 1 8 4 
    3 6 4 1 8 5 7 2 
    3 6 4 2 8 5 7 1 
    3 6 8 1 4 7 5 2 
    3 6 8 1 5 7 2 4 
    3 6 8 2 4 1 7 5 
    3 7 2 8 5 1 4 6 
    3 7 2 8 6 4 1 5 
    3 8 4 7 1 6 2 5 
    4 1 5 8 2 7 3 6 
    4 1 5 8 6 3 7 2 
    4 2 5 8 6 1 3 7 
    4 2 7 3 6 8 1 5 
    4 2 7 3 6 8 5 1 
    4 2 7 5 1 8 6 3 
    4 2 8 5 7 1 3 6 
    4 2 8 6 1 3 5 7 
    4 6 1 5 2 8 3 7 
    4 6 8 2 7 1 3 5 
    4 6 8 3 1 7 5 2 
    4 7 1 8 5 2 6 3 
    4 7 3 8 2 5 1 6 
    4 7 5 2 6 1 3 8 
    4 7 5 3 1 6 8 2 
    4 8 1 3 6 2 7 5 
    4 8 1 5 7 2 6 3 
    4 8 5 3 1 7 2 6 
    5 1 4 6 8 2 7 3 
    5 1 8 4 2 7 3 6 
    5 1 8 6 3 7 2 4 
    5 2 4 6 8 3 1 7 
    5 2 4 7 3 8 6 1 
    5 2 6 1 7 4 8 3 
    5 2 8 1 4 7 3 6 
    5 3 1 6 8 2 4 7 
    5 3 1 7 2 8 6 4 
    5 3 8 4 7 1 6 2 
    5 7 1 3 8 6 4 2 
    5 7 1 4 2 8 6 3 
    5 7 2 4 8 1 3 6 
    5 7 2 6 3 1 4 8 
    5 7 2 6 3 1 8 4 
    5 7 4 1 3 8 6 2 
    5 8 4 1 3 6 2 7 
    5 8 4 1 7 2 6 3 
    6 1 5 2 8 3 7 4 
    6 2 7 1 3 5 8 4 
    6 2 7 1 4 8 5 3 
    6 3 1 7 5 8 2 4 
    6 3 1 8 4 2 7 5 
    6 3 1 8 5 2 4 7 
    6 3 5 7 1 4 2 8 
    6 3 5 8 1 4 2 7 
    6 3 7 2 4 8 1 5 
    6 3 7 2 8 5 1 4 
    6 3 7 4 1 8 2 5 
    6 4 1 5 8 2 7 3 
    6 4 2 8 5 7 1 3 
    6 4 7 1 3 5 2 8 
    6 4 7 1 8 2 5 3 
    6 8 2 4 1 7 5 3 
    7 1 3 8 6 4 2 5 
    7 2 4 1 8 5 3 6 
    7 2 6 3 1 4 8 5 
    7 3 1 6 8 5 2 4 
    7 3 8 2 5 1 6 4 
    7 4 2 5 8 1 3 6 
    7 4 2 8 6 1 3 5 
    7 5 3 1 6 8 2 4 
    8 2 4 1 7 5 3 6 
    8 2 5 3 1 7 4 6 
    8 3 1 6 2 5 7 4 
    8 4 1 3 6 2 7 5

#### 总结

    利用回溯法可以遍历所有的子空间然后求解问题,关键是要求出判断合法的函数和选取值的空间
    然后利用循环和递归遍历整个搜索空间
    