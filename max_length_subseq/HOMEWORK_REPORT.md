### HOMEWORK REPORT

---

#### 个人信息

 姓名 | 学号 
 :---: | :---:
 吴宇杰 | 19215028
 
#### 题目内容
 
    给定两个字符串，输出最长的公共子序列
    
#### 解题思路

    判断两个字符串第一个字符是否相等
    是返回两个字符串去掉第一个字符的子串结果加1
    否返回两个字符串依次去掉第一个字符的子串与另外一个字符串匹配的结果
    
#### 实现代码

```c++
// main.cpp
#include <iostream>
#include "dp.cpp"
#include "array_utils.h"

using namespace std;

int main () {
    int n = 20;

    string s1 = ArrayUtils::genrateRandomString(n);
    string s2 = ArrayUtils::randomSwap(s1, 20);

    cout << s1 << endl;
    cout << s2 << endl;

    cout << dp::LCS(s1, s2) << endl;

    return 0;
}

// dp.cpp
#include <iostream>
#include <vector>

using namespace std;

namespace dp{
    vector<vector<int>> dp;

    int LCS (string s1, string s2) {
        dp.clear();

        // make sure using less space
        if(s1.size() > s2.size()) { swap(s1, s2); }

        dp.push_back(vector<int>(s1.size(), 0));
        dp.push_back(vector<int>(s1.size(), 0));

        for (int i = 0; i < s1.size(); ++i) {
            if (i == 0) {
                dp[0][i] = s1[0] == s2[0];
            } else {
                dp[0][i] = dp[0][i-1] | s1[i] == s2[0];
            }
        }


        for (int i = 1; i < s2.size(); ++i) {
            dp[i % 2][0] = dp[(i+1) % 2][0] | s2[i] == s1[0];
            for (int j = 1; j < s1.size(); ++j) {
                dp[i % 2][j] = s1[j] == s2[i] ? dp[(i+1) % 2][j-1] + 1 : max(dp[(i+1) % 2][j], dp[i % 2][j - 1]);
            }
        }


        return dp[(s1.size()+1)%2][s1.size()-1];
    }
}

```

#### 测试样例

    输入：
    nlbmbcazwkhdqcxjofxj
    nlbdzcawbkhmqcxjxfoj
    
    输出：
    14

#### 总结

    最长公共子序列子问题由当前字符串的分割点状态决定
    当前分割两个字符相等，则子问题为去掉该字符的子串最长序列+1
    不相等，则子问题为两个字符串各自去掉分割字符再与对方匹配取最大值结果
    
    可以看出，无论是否相等，都可以利用到子问题的最优解，即有最优子结构
    而且也是明显有重复子问题，所以可以利用动态规划求解
    
    可以注意到，此题原问题利用的子问题都在原问题附近
    所以可以利用滚动更新压缩中间变量的存储空间
    