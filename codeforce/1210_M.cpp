
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

const int maxN = 100001;
// bool colors[maxN];
int nums[maxN];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    // memset(colors, 0, sizeof(colors));
    int maxLen = 0;
    int start = 0;
    for (int i = 1; i < n; ++i) {
        if (nums[i] == nums[i - 1]) {
            maxLen = max(maxLen, i - start);
            start = i;
        }
    }
    maxLen = max(maxLen, n - start);
    cout << maxLen << endl;
    return 0;
}