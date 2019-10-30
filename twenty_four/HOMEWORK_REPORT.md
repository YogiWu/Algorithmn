### HOMEWORK REPORT

---

#### 个人信息

 姓名 | 学号 
 :---: | :---:
 吴宇杰 | 19215028
 
#### 题目内容

    求解四张卡片通过加减乘除得到24的方法 
    
#### 解题思路

    利用回溯法遍历整个解空间暴力求解
    
#### 实现代码

```c++
// main.cpp
#include <vector>
#include <unordered_map>
#include "array_utils.h"
#include "backtrack.cpp"

using namespace std;


vector<int> cardList;
unordered_map<string, int (*)(int, int)> opList;

int add(int a, int b) {
    return a+b;
}

int sub(int a, int b) {
    return a-b;
}

int mul(int a, int b) {
    return a*b;
}

int divv(int a, int b) {
    if (b==0 || a%b != 0) return -1;
    return a/b;
}

int main () {
    cardList = ArrayUtils::genrateRandomVector(4, 1, 14);
    ArrayUtils::printVector(cardList);

    opList["+"] = add;
    opList["-"] = sub;
    opList["*"] = mul;
    opList["/"] = divv;

    Backtrack::findTwentyFour(cardList, opList);

    return 0;
}

// backtrack.cpp
#include <vector>
#include <unordered_map>
#include "BST_utils.h"

using namespace std;

namespace Backtrack{
    typedef BSTUtils<string>::BSTNode BSTNode;
    BSTNode *root;
    vector<int> res;
    vector<BSTNode*> cardList;
    unordered_map<string, int (*)(int, int)> opList;

    void printRes (BSTUtils<string>::BSTNode* root) {
        if (root->left == NULL && root->right == NULL) {
            cout << root->key;
        } else {
            cout << "(";
            printRes(root->left);
            cout << root->key;
            printRes(root->right);
            cout << ")";
        }
//        BSTUtils<string>::LDR(root, [](BSTNode *node) { cout << node->key; }, [](int hookType) {
//            switch (hookType) {
//                case 0:
//                    cout << "(";
//                    break;
//                case 3:
//                    cout << ")";
//                    break;
//            }
//        });
    }

    int getRes (BSTUtils<string>::BSTNode *rt) {
        if (!rt->left && !rt->right) {
            return stoi(rt->key);
        } else {
            return opList[rt -> key](getRes(rt->left), getRes(rt->right));
        }
    }

    void backtrack (vector<BSTNode*> &ls, vector<int> &res) {
        if (ls.size() == 1) {
            if (getRes(ls[0]) == 24) {
                printRes(ls[0]);
                cout << endl;
            }
        } else {
            for (int i = 0; i < ls.size(); ++i) {
                for (int j = i+1; j < ls.size(); ++j) {
                    int left, right;
                    for (auto &op:opList) {
                        if (res[i] > res[j]) {
                            left = i, right = j;
                        } else {
                            right = i, left = j;
                        }

                        int ans = op.second(res[left], res[right]);
                        if (ans != -1) {
                            auto rootNode = new BSTNode(op.first);

                            rootNode->left = ls [left];
                            rootNode->right = ls[right];

                            vector<BSTNode*> subls;
                            vector<int> subres;

                            for (int k = 0; k < ls.size(); ++k) {
                                if (k != left && k != right) {
                                    subls.push_back(ls[k]);
                                    subres.push_back(res[k]);
                                }
                            }

                            subls.push_back(rootNode);
                            subres.push_back(ans);
                            backtrack(subls, subres);
                            subls.clear();
                            subres.clear();

                            delete(rootNode);
                            rootNode = NULL;
                        }
                    }
                }
            }
        }
    }

    void findTwentyFour(vector<int> cl, unordered_map<string, int(*) (int, int)> ol) {
        const int ans = 24;

        for(auto &num:cl) {
            cardList.push_back(BSTUtils<string>::generateBSTNode(to_string(num)));
            res.push_back(num);
        }
        opList = ol;

        backtrack(cardList, res);
    }
}
```

#### 测试样例

    输入：
    1  10  12  5
    
    输出：
    ((12*(10/1))/5)
    (12*((10/1)/5))
    ((12*(10*1))/5)
    (12*((10*1)/5))
    ((12/1)*(10/5))
    (((12/1)*10)/5)
    ((12*1)*(10/5))
    (((12*1)*10)/5)
    ((12*10)/(5/1))
    (12*(10/(5/1)))
    ((12*10)/(5*1))
    (12*(10/(5*1)))
    ((12*10)/(5/1))
    ((12*10)/(5*1))
    (((12*10)/1)/5)
    (((12*10)*1)/5)
    (((12*10)/5)/1)
    (((12*10)/5)*1)
    ((12/1)*(10/5))
    ((12*1)*(10/5))
    (12*((10/5)/1))
    (12*((10/5)*1))
    ((12*(10/5))/1)
    ((12*(10/5))*1)

#### 总结

    利用回溯法可以遍历所有的子空间然后求解问题,关键是要求出判断合法的函数和选取值的空间
    然后利用循环和递归遍历整个搜索空间
    
    这道题还利用了将大数放置于左边小数放置于右边以到达去重和保证合法解的目的
    