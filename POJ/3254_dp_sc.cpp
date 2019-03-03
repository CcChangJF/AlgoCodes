
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

const int N = 13;
const int MOD = 100000000;
int board[N][N];
const int maxTot = 400;
int dp[N][maxTot];
int states[maxTot];

bool isLegal(int n) {
    if ((n & n << 1) > 0) { return false; }
    return true;
}

bool isStateLegal(int s, int m, int row) {
    for (int i = 0; i < m; ++i) {
        if (0 < (s & 1 << i) && board[row][m - 1 - i] != 1) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    int all = 0;
    for (int i = 0; i < (1 << m); ++i) {
        if (isLegal(i)) {
            states[all++] = i;
        }
    }

    for (int j = 0; j < all; ++j) {
        if (isStateLegal(states[j], m, 0)) {
            dp[0][j] = 1;
        }
        else {
            dp[0][j] = 0;
        }
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < all; ++j) {
            if (!isStateLegal(states[j], m, i)) { continue;}
            for (int k = 0; k < all; ++k) {
                if (!isStateLegal(states[k], m, i - 1) || (states[j] & states[k]) > 0) { continue; }
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
            }
        }
    }
    int ans = 0;
    for (int j = 0; j < all; ++j) {
        ans = (ans + dp[n - 1][j]) % MOD;
    }

    cout << ans << endl;

    return 0;
}