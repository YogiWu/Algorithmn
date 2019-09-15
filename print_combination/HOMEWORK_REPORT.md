### HOMEWORK REPORT

---

#### 个人信息

 姓名 | 学号 
 :---: | :---:
 吴宇杰 | 19215028
 
#### 题目内容
 
    给定一个数组，输出数组所有数字的全部组合
    
#### 解题思路

    利用递归的思路将原问题分解，
    因为第n-1个数的组合情况与第n个数无关
    在第n个数考虑取与不取这两种情况，可将原问题分解成对应的取与不取n-1子问题
    
#### 实现代码

```c++
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
```

#### 测试样例

    输入: 3
    输出:

    3
    2
    23
    1
    13
    12
    123

#### 总结

    利用递归将问题分解是解决有递推关系问题的好方法，需找到递推关系然后考虑其递归解法