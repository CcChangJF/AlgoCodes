
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

const int N = 105;
const int M = 10;
const int maxSta = 65;
int dp[N][maxSta][maxSta];
bool legal[N][maxSta];
int states[maxSta];

bool isLegal(int n) {
    if ((n << 1 & n) > 0 || (n << 2 & n) > 0) {
        return false;
    }
    else {
        return true;
    }
}

bool isLegalState(int s, int m, string &geo) {
    for (int i = 0; i < m; ++i) {
        if (0 < (s & 1 << i) && geo[m - 1 - i] != 'P') {
            return false;
        }
    }
    return true;
}

// bool isConflict(int s1, int s2) {
//     if ((s1 << 1 & s2) > 0 || (s1 << 2 & s2) > 0 || 
//         (s1 & s2 << 1) > 0 || (s1 & s2 << 2) > 0 ||
//         (s1 & s2) > 0) {
//         return true;
//     }
//     return false;
// }

int getCans(int n) {
    int cnt = 0;
    while(0 != n) {
        ++cnt;
        n = n & n - 1;
    }
    return cnt;
}

int main() {

    // cout << endl << "count: " << count << endl;

    int n,m;
    cin >> n >> m;
    vector<string> geo(n);
    for (int i = 0; i < n; ++i) {
        cin >> geo[i];
    }

    int all = 0;
    for (int i = 0; i < (1 << m); ++i) {
        if (isLegal(i)) {
            states[all++] = i;
        }
    }
    if (0 == m || 0 == n) {
        cout << 0 << endl;
        return 0;
    }

    int res = 0;
    for (int i = 0; i < all; ++i) {
        if (isLegalState(states[i], m, geo[0])) {
            legal[0][i] = true;
            dp[0][0][i] = getCans(states[i]);
            res = max(res, dp[0][0][i]);
            // cout << bitset<10>(states[i]) << ":" << dp[0][0][states[i]] << "\t";
        }
    }
    // for (int i = 0; i < all; ++i) {
    //     int curS = states[i];
    //     int curCans = getCans(curS);
    //     if (isLegalState(curS, m, geo[1])) {
    //         for (int j = 0; j < all; ++j) {
    //             int lastS = states[j];
    //             if (legal[0][lastS] && !isConflict(curS, lastS)) {
    //                 dp[1][lastS][curS] = max(dp[1][lastS][curS], dp[0][0][lastS] + curCans);
    //             }
    //         }
    //     }
    // }

    // cout << endl;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < all; ++j) {
            int curS = states[j];
            if (isLegalState(curS, m, geo[i])) {
                legal[i][j] = true;
                int curCans = getCans(curS);
                // cout << bitset<10>(curS) << "\t";
                for (int k = 0; k < all; ++k) {
                    int lastS = states[k];
                    if (!legal[i - 1][k] || (curS & lastS) > 0) {continue;}
                    // cout << bitset<10>(curS) << " , " <<  bitset<10>(lastS) << endl;
                    if (1 == i) {
                        // cout << bitset<10>(lastS) << endl;
                        dp[i][k][j] = max(dp[i][k][j], dp[i - 1][0][k] + curCans);
                        // cout << bitset<10>(curS) << " , " <<  bitset<10>(lastS) << " " << dp[i][lastS][curS] << endl;
                        res = max(res, dp[i][k][j]);
                        continue;
                    }
                    // cout << i << " " << j << " " << k << endl;
                    for (int t = 0; t < all; ++t) {
                        int lastTwoS = states[t];
                        if (!legal[i - 2][t] || (curS & lastTwoS) > 0) {continue;}
                        // cout << bitset<10>(curS) << " , " <<  bitset<10>(lastS) << " , " <<  bitset<10>(lastTwoS) << " " << dp[i][lastS][curS] << endl;
                        dp[i][k][j] = max(dp[i][k][j], 
                            dp[i-1][t][k] + curCans);
                        res = max(res, dp[i][k][j]);
                    }
                }    
            }
        }
    }
    cout << res << endl;
    return 0;
}