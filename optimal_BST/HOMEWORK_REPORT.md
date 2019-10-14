### HOMEWORK REPORT

---

#### 个人信息

 姓名 | 学号 
 :---: | :---:
 吴宇杰 | 19215028
 
#### 题目内容
 
    给定一串key和key的命中与不命中的概率，构造平均查找次数最少的二叉搜索树
    
#### 解题思路

    因为最优二叉搜索树的左右子树必然是最优二叉搜索树，所以有最优子结构
    构造思路是依次尝试讲各个节点作根，计算平均查找次数，然后选取最少的那个作为最优解
    以此来规划生成路线，实现动态规划算法
    
#### 实现代码

```c++
// main.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "array_utils.h"

#include "dp.cpp"

using namespace std;

int main ()
{
    const int n = 10;

    vector<int> keyList = ArrayUtils::genrateRandomVector(n, 0, 100);
    sort(keyList.begin(), keyList.end());

    ArrayUtils::printVector(keyList);

    vector<int> proList = ArrayUtils::genrateRandomVector(2*n+1, 0, 100);
    double total = accumulate(proList.begin(), proList.end(), 0);

    vector<double> keyProList;
    for (auto &x:proList) {
        keyProList.push_back(x/total);
    }

    ArrayUtils::printVector(keyProList);
    cout << accumulate(keyProList.begin(), keyProList.end(), 0.0) << endl;

    cout << dp::optimal_BST(keyList, keyProList) << endl;

    dp::print_BST();

    return 0;
}
// dp.cpp
#include <iostream>
#include <numeric>
#include <limits>
#include <vector>
#include "array_utils.h"
#include "BST_utils.h"

using namespace std;

namespace dp{
    vector<vector<double>> dp;
    vector<int> _keyList;
    vector<double> _keyProList;
    vector<double> _keyProSumList;

    double optimal_BST (const vector<int> &keyList, const vector<double> &keyProList) {
        dp = vector<vector<double>> (keyList.size(), vector<double >(keyList.size(),0.0));

        _keyList = keyList;
        _keyProList = keyProList;

        for (int i = 0; i < keyProList.size(); ++i) {
            _keyProSumList.push_back(accumulate(keyProList.begin(), keyProList.begin()+i+1, 0.0));
        }

        for (int i = 0; i < keyList.size(); ++i) {
            dp[i][i] = keyProList[2*i] + 2*keyProList[2*i+1] + keyProList[2*(i+1)];
        }

        for (int i = 1; i < keyList.size(); ++i) {
            for (int j = 0; i+j < keyList.size(); ++j) {
                if (i == 1) {
                    double left_root = dp[j][j] + dp[j+1][j+1] - keyProList[2*(j+1)] + keyProList[2*(j+1)+1] + keyProList[2*(j+2)];
                    double right_root = dp[j][j] + dp[j+1][j+1] + keyProList[2*j] + keyProList[2*j+1] - keyProList[2*(j+1)];

                    dp[j][i+j] = min(left_root, right_root);
                } else {
                    double minRes = numeric_limits<double>::max();

                    for (int k=j+1; k < i+j; ++k) {
                        minRes = min(minRes, dp[j][k-1] + dp[k+1][i+j] + _keyProSumList[2*(i+j+1)] - _keyProSumList[2*j-1]);
                    }

                    dp[j][i+j] = minRes;
                }
            }
        }

        return dp[0][keyList.size() - 1];
    }

    BSTUtils<int>::BSTNode* generateBST (int l, int r) {
        if (l == r) {
            return BSTUtils<int>::generateBSTNode(_keyList[l]);
        }

        if (l+1 == r) {
            double left_root = dp[l][l] + dp[r][r] - _keyProList[2*r] + _keyProList[2*r+1] + _keyProList[2*(r+1)];
            double right_root = dp[l][l] + dp[r][r] + _keyProList[2*l] + _keyProList[2*l+1] - _keyProList[2*(l+1)];

            bool left = dp[l][r] - left_root < dp[l][r] - right_root;
            BSTUtils<int>::BSTNode* root;

            if (left) {
                root = BSTUtils<int>::generateBSTNode(_keyList[l]);
                root->right = BSTUtils<int>::generateBSTNode(_keyList[r]);
            } else {
                root = BSTUtils<int>::generateBSTNode(_keyList[r]);
                root->left = BSTUtils<int>::generateBSTNode(_keyList[l]);
            }

            return root;
        }

        double minRes = numeric_limits<double>::max();
        int minKey = 0;
        for (int k = l+1; k<r; k++) {
            double res = dp[l][r] - dp[l][k-1] - dp[k+1][r] - _keyProSumList[2*(r+1)] + _keyProSumList[2*l - 1];

            if (res < minRes) {
                minRes = res;
                minKey = k;
            }
        }

        auto root = BSTUtils<int>::generateBSTNode(_keyList[minKey]);
        root->left = generateBST(l, minKey-1);
        root->right = generateBST(minKey+1, r);

        return root;
    }

    void print_BST () {
        auto root = generateBST(0, _keyList.size()-1);

        BSTUtils<int>::print_BST(root);
    }
}
```

#### 测试样例

    输入: 
    15 21 35 49 77 83 86 86 92 93
    0.061753 0.0268924 0.0896414 0.0587649 0.062749
    0.0258964 0.0398406 0.0258964 0.0717131 0.0358566 
    0.0109562 0.0677291 0.0667331 0.0288845 0.0816733
    0.0298805 0.061753 0.0229084 0.0667331 0.0348606 0.0288845
    输出:
    3.24203
    ((((()(15)(()(21)()))(35)(()(49)()))(77)(()(83)()))(86)(()(86)()))(92)(()(93)()) 

#### 总结

    可以利用一个存储和的数组优化计算速度
    查找最优解的根可以通过平行四边形法则加速

