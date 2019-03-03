
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>


using namespace std;



int main() {
    int x;
    while (cin >> x) {
        int a = 1;
        int b = 1;
        bool flag = false;
        for (; b <= x; ++b) {
            for (a = b; a <= x; a += b) {
                if (a * b > x && a / b < x) {
                    cout << a << " " << b << endl;
                    flag = true;
                    break;
                }
            }
            if (flag) { break;}
        }
        if (!flag) {
            cout << -1 << endl;
        }
    }
    return 0;
}