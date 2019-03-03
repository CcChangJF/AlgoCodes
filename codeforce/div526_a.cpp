
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

const int maxN = 101;
int nums[maxN];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    int minRes = INT_MAX;
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        for (int j = 0; j < n; ++j) {
            cur += (abs(i - j) + j + i) * nums[j] * 2;
        }
        minRes = min(minRes, cur);
    }
    cout << minRes << endl;
    return 0;
}