
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
#include <cmath>

typedef long long ll;

using namespace std;

const int N = 14;
int graph[N][N];
int dp[1 << N][N][N];
ll cnt[1 << N][N][N];
int vals[N];


int main() {
    int t;
    cin >> t;
    while(t--) {
        memset(dp, 0, sizeof(dp));
        memset(cnt, 0, sizeof(cnt));
        memset(graph, 0, sizeof(graph));
        int n,m;
        cin >> n >> m;
        int sumVal = 0;
        for (int i = 0; i < n; ++i) {
            cin >> vals[i];
            sumVal += vals[i];
        }
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            graph[u][v] = 1;
            graph[v][u] = 1;
        }
        if (1 == n) {
            cout << vals[0] << " 1" << endl;
            continue;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && 0 != graph[i][j]) {
                    int s = (1 << i | 1 << j);
                    dp[s][i][j] = vals[i] * vals[j];
                    dp[s][j][i] = vals[i] * vals[j];
                    cnt[s][i][j] = 1;
                    cnt[s][j][i] = 1;
                }
            }
        }

        int all = 1 << n;
        // for (int i = 0; i < all; ++i) {
        //     cout << bitset<4>(i) << ": " << endl;
        //     for (int j = 0; j < n; ++j) {
        //         for (int k = 0; k < n; ++k) {
        //             cout << dp[i][k][j] << "\t";
        //         }
        //         cout << endl;
        //     }
        //     cout << endl;
        // }

        for (int i = 0; i < all; ++i) {
            for (int j = 0; j < n; ++j) {
                if (0 == (i & 1 << j)) { continue; }
                for (int t = 0; t < n; ++t) {
                    if (0 == graph[t][j] || 0 == (i & 1 << t)) { continue;}
                    for (int k = 0; k < n; ++k) {
                        if (0 == (i & 1 << k) || 0 == graph[k][t] || 0 == dp[i ^ 1 << j][k][t]) { continue; }
                        int curVal = dp[i ^ 1 << j][k][t] + vals[t] * vals[j] + 
                            graph[j][k] * vals[t] * vals[j] * vals[k];
                        if (curVal > dp[i][t][j]) {
                            dp[i][t][j] = curVal;
                            cnt[i][t][j] = cnt[i ^ 1 << j][k][t];
                        }
                        else if (curVal == dp[i][t][j]) {
                            cnt[i][t][j] += cnt[i ^ 1 << j][k][t];
                        }
                    }
                }
            }
        }


        long long duplicate = 0;
        int maxVal = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (maxVal < dp[all - 1][i][j]) {
                    maxVal = dp[all - 1][i][j];
                    duplicate = cnt[all - 1][i][j];
                }
                else if (maxVal == dp[all - 1][i][j]) {
                    duplicate += cnt[all - 1][i][j];
                }
            }
        }
        if (0 == maxVal) {
            cout << "0 0" << endl;
        }
        else {
            cout << maxVal + sumVal << " " << duplicate / 2 << endl;
        }
    }
    return 0;
}