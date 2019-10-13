### HOMEWORK REPORT

---

#### 个人信息

 姓名 | 学号 
 :---: | :---:
 吴宇杰 | 19215028
 
#### 题目内容
 
    给定多个矩阵，输出多个矩阵相成需要的最少乘法数
    
#### 解题思路

    从左边界到右边界依次尝试将原来的矩阵链分割成两段
    当前分割乘法数等于左边最少乘法数加上右边少乘法数加上左右两个矩阵相乘需要的运算数
    选取循环中最小的那个方案即为最少乘法数
    打印括号需要判断一下当前方案是由哪几个子方案相加得到的，即可递归打印出结果
 
#### 实现代码

```c++
#include <iostream>
#include <vector>
#include "array_utils.h"

using namespace std;

vector<vector<int>> dp;

vector<int> matrix;

int minMatrixMulti (int n) {
    int res, tmp;

    // i is the step
    for (int i=0; i<n; i++) {
        for (int j=0; i+j<n; j++) {
            if (i == 0) {
                res = 0;
            } else {
                res = -1;
                // k attempt to split the seq from j to i+j
                for (int k=j; k < i+j; k++) {
                    tmp = dp[j][k] + dp[k+1][i+j] + matrix[j] * matrix[k+1]*matrix[i+j+1];
                    if (res == -1) {
                        res = tmp;
                    } else if (tmp < res) res = tmp;
                }
            }

            dp[j][i+j] = res;
        }
    }
    ArrayUtils::printVector(dp);

    return dp[0][n-1];
}

void printRes (int l, int r) {
    if (l == r) {
        cout <<  l;
        return;
    }
    int k = l;
    while (k < r) {
        if (dp[l][k] + dp[k+1][r] + matrix[l] * matrix[k+1] * matrix[r+1] == dp[l][r]) {
            break;
        }
        k++;
    }
    cout << "(";
    printRes(l, k);
    cout << "*";
    printRes(k+1, r);
    cout << ")";
}

int main () {
    int n = 10;

    // generate n matrix row number and column number
    matrix = ArrayUtils::genrateRandomVector(n+1, 10, 100);
    ArrayUtils::printVector(matrix);

    for(int i=0; i<n; i++) {
        dp.push_back(vector<int>(n, 0));
    }

    cout << minMatrixMulti(n) << endl;

    printRes(0, n-1);

    return 0;
}
```

#### 测试样例

    输入：
    83 26 37 35 33 35 56 22 79 11 42 
    输出：
    166551
    ((0*(1*(2*(3*(4*(5*(6*(7*8))))))))*9)

#### 总结

    此题解题最重要的思路是找到分割办法
    将矩阵链分割成左右两段，即可利用左右两段的最优解来构造当前最优解，即存在最优子结构
    分割过程中显然存在很多重叠子问题
    所以满足动态规划条件，即可利用递推方程构造路线进行动态规划求解