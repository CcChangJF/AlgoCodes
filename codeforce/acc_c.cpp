
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
typedef long long ll;
ll dp[20005];
ll nxt[20005];

const int MOD = 998244353;


int main() {
    int n,m,k;
    cin >> n >> m >> k;
    dp[0] = m;
    for (int row = 2; row <= n; ++row) {
        nxt[0] = m;
        for (int col = 1; col <= min(row, k); ++col) {
            nxt[col] = (dp[col] + dp[col - 1] * (m - 1)) % MOD;
            // cout << "col: " << col << ", " << nxt[col] << endl;
        }
        for (int i = 0; i <= k; ++i) {
            // cout << " , " << nxt[i];
            dp[i] = nxt[i];
            nxt[i] = 0;
        }
        // memset(nxt, 0, sizeof(nxt));
    }
    // for (int i = 0; i <= k; ++i) {cout << dp[i] << " ";}
    cout << dp[k] << endl;

    return 0;
}