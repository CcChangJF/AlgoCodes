
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
#include <bitset>

typedef long long ll;

using namespace std;

ll ans[13];
ll ans3[13];

int main() {
    ans3[1] = 1;
    // cout << "hello" << endl;
    for (int i = 2; i < 13; ++i) {
        ans3[i] = 2 * ans3[i - 1] + 1;
    }

    memset(ans, 0x3f, sizeof(ans));
    ans[0] = 0;
    ans[1] = 1;
    ans[2] = 3;
    ans[3] = 5;
    for (int i = 4; i < 13; ++i) {
        // cout << i << endl;
        for (int j = 1; j < i; ++j) {
            ans[i] = min(ans[i], 2 * ans[j] + ans3[i - j]);
        }
    }
    for (int i = 1; i < 13; ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}