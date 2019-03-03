
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

const int N = 12;
const int maxTot = 600;
const int MOD = 100000000;

int dp[N][maxTot];
int states[maxTot];
int board[N];

bool isStateLegal(int s) {
    return ((s & s << 1) == 0);
}

bool isStateFit(int s, int curBoard) {
    return ((s & curBoard) == s);
}


int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        board[i] = 0;
        for (int j = 0; j < m; ++j) {
            int val;
            cin >> val;
            if (1 == val) {
                board[i] += (1 << j);
            }
        }
        // cout << board[i] << "\t";
    }

    int all = 0;
    int maxAll = 1 << m;
    for (int j = 0; j < maxAll; ++j) {
        if (isStateLegal(j)) {
            states[all++] = j;
            // cout << bitset<4>(states[all - 1]) << "\t";
        }
    }
    // cout << endl << all << endl;

    for (int j = 0; j < all; ++j) {
        if (isStateFit(states[j], board[0])) {
            dp[0][j] = 1;
        }
        else {
            dp[0][j] = 0;
        }
    }

    // for (int j = 0; j < all; ++j) {
    //     if (0 != dp[0][j]) {
    //         cout << bitset<4>(states[j]) << ":" << dp[0][j] << "\t";
    //     }
    // }
    // cout << endl;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < all; ++j) {
            if (!isStateFit(states[j], board[i])) { continue; }
            for (int k = 0; k < all; ++k) {
                if (!isStateFit(states[k], board[i - 1]) 
                    || (states[k] & states[j]) > 0) { continue; }
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
                // cout << bitset<4>(states[j]) << "," << bitset<4>(states[k]) << ":" << dp[i][j] << "\t";
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