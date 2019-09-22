//
// Created by yogi on 2019/9/22.
//

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

string padZero (string s, int size) {
    int pad_num = size - s.size();

    while(pad_num != 0) {
        s = '0' + s;
        pad_num--;
    }
    return s;
}

int multiply (string s1, string s2) {
    int size = s1.size() > s2.size() ? s1.size() : s2.size();

    if (size == 1) {
        return stoi(s1) * stoi(s2);
    }

    size = size % 2 ? size+1 : size ;

    s1 = padZero(s1, size);
    s2 = padZero(s2, size);

    int a = stoi(s1.substr(0, size/2));
    int b = stoi(s1.substr(size/2));
    int c = stoi(s2.substr(0, size/2));
    int d = stoi(s2.substr(size/2));

    int ac = multiply(to_string(a), to_string(c));
    int bd = multiply(to_string(b) ,to_string(d));
    int cross_mul = multiply(to_string(a+b), to_string(c+d));

    return ac*pow(10, size) + (cross_mul - ac - bd)*pow(10,  size/2) + bd;
}

int main () {
    string s1, s2;

    cout << "first number:";
    cin >> s1;

    cout << "second number:";
    cin >> s2;

    cout << multiply(s1, s2);

    return 0;
}
