#include <iostream>

using namespace std;

int main() {
    int a = 1 >> 2;
    a = a << 2;
    cout << to_string(a) ;
    return 0;
}