//
// Created by yogi on 2019/10/28.
//
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
