
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <ctime>
#include <string.h>

using namespace std;

const int maxN = 100005;
int nums[maxN];
int n;
int res[maxN];
int colors[maxN];
int counts[maxN];


int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    int color = 1;
    for (int i = 0; i < n; ++i) {
        int &curColor = colors[nums[i]];
        if (0 == curColor || counts[curColor] >= n - nums[i]) {
            curColor = color++;
        }
        res[i] = curColor;
        ++counts[curColor];
        // cout << i << " " << res[i] << endl;
    }
    bool flag = true;
    for (int i = 0; i < n; ++i) {
        if (n - nums[i] != counts[res[i]]) {
            flag = false;
            break;
        }
    }

    if (flag) {
        cout << "Possible" << endl;
        for (int i = 0; i < n; ++i) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "Impossible" << endl;
    }

    return 0;
}