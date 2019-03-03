
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>


using namespace std;

// int a[10];

int main() {
    for (int n = 180;;++n) {
        if ((n - 2) * 180 % n == 0 &&  179 == (n - 2) * 180 / n) {
            cout << n << endl;
            break;
        }
    }

    return 0;
}