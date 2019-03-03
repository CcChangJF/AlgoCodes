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

typedef long long ll;

using namespace std;

const int N = 20;
const int maxN = (1 << 20);
ll dp[N][maxN];

bool firstRow(int val, int m) {
    for (int i = 0; i < m; ++i) {
        if (0 != (val & (1 << i))) {
            if (i < m - 1 && (0 < (val & (1 << i + 1)))) {
                ++i;
            }
            else {
                return false;
            }
        }
    }
    return true;
}

bool remainRow(int last, int cur, int m) {
    for (int i = 0; i < m; ++i) {
        if (0 == (cur & (1 << i))) {
            if (0 == (last & (1 << i))) {
                return false;
            }
        }
        else {
            if (0 != (last & (1 << i))) {
                if (i < m - 1 && (0 < (cur & (1 << i + 1))) 
                    && (0 < (last & (1 << i + 1)))) {
                    ++i;
                }
                else {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while(cin >> n >> m, n != 0 && 0 != m) {
        if (n < m) {
            swap(n, m);
        }
        int all = (1 << m);
        for (int i = 0; i < all; ++i) {
            // cout << firstRow(i, m) << " ";
            if (firstRow(i, m)) {
                dp[0][i] = 1;
            }
        }
        // cout << endl;

        for (int row = 1; row < n; ++row) {
            for (int cur = 0; cur < all; ++cur) {
                for (int last = 0; last < all; ++last) {
                    if (remainRow(last, cur, m)) {
                        dp[row][cur] = (dp[row][cur] + dp[row - 1][last]);
                    }
                }
                // cout << dp[row][cur] << " ";
            }
            // cout << endl;
        }
        // cout << n << " " << m << endl;
        cout << dp[n - 1][all - 1] << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < all; ++j) {
                dp[i][j] = 0;
            }
            // memset(&dp[i][0], 0, all * sizeof(int));
        }
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < all; ++j) {
        //         cout << dp[i][j] << "\t";
        //     }
        //     cout << endl;
        // }
    }


    return 0;
}