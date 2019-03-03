
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
const int M = (1 << 13);
int dp[M][N][N];
ll times[M][N][N];
int graph[N][N];
int dis[N][N];
int vals[N];

int getOnes(int s) {
    int cnt = 0;
    while(0 != s) {
        ++cnt;
        s = s & s - 1;
    }
    return cnt;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> vals[i];
            sum += vals[i];
        }
        for (int i = 0; i < m; ++i) {
            int u,v;
            cin >> u >> v;
            --u;
            --v;
            graph[u][v] = 1;
            graph[v][u] = 1;
            dis[u][v] = dis[v][u] = vals[u] * vals[v];
        }

        
        if (1 == n) {
            cout << vals[0] << " 1" << endl;
            return 0;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (1 == graph[i][j] && i != j) {
                    dp[1 << i | 1 << j][i][j] = vals[i] * vals[j];
                    dp[1 << i | 1 << j][j][i] = vals[i] * vals[j];
                    times[1 << i | 1 << j][i][j] = 1;
                    times[1 << i | 1 << j][j][i] = 1;
                }
            }
        }

        int all = (1 << n);
        for (int i = 1; i < all; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i & 1 << j) == 0) { continue;}
                for (int k = 0; k < n; ++k) {
                    if ((i & (1 << k)) == 0 || 0 == graph[k][j]) { continue; }
                    // if (getOnes(i) < 2) { continue;}
                    // else if (getOnes(i) == 2) {
                    //     dp[i][k][j] = dis[k][j];
                    //     times[i][k][j] = 1;
                    //     times[i][j][k] = 1;
                    //     continue;
                    // }
                    for (int t = 0; t < n; ++t) {
                        if ((i & 1 << t) == 0 || 0 == graph[t][j] || 0 == graph[t][k]) { continue;}
                        int curVal = dp[i ^ 1 << j][t][k] + (vals[t] * vals[k] * vals[j]);
                        if (curVal > dp[i][k][j]) {
                            dp[i][k][j] = curVal;
                            times[i][k][j] = times[i ^ 1 << j][t][k];
                        }
                        else if (curVal == dp[i][k][j]) {
                            times[i][k][j] += times[i ^ 1 << j][t][k];
                        }
                        // dp[i][k][j] = max(dp[i][k][j], dp[i - 1][i ^ (1 << j)][k] 
                        //     + (vals[t] * vals[k] * vals[j]));

                    }
                }
            }
        }
        // for (int i = 0; i < all; ++i) {
        //     cout << bitset<4>(i) << ":" << endl;
        //     for (int j = 0; j < n; ++j) {
        //         for (int k = 0; k < n; ++k) {
        //             cout << dp[i][j][k] << ":" << times[i][j][k] << "\t";
        //         }
        //         cout << endl;
        //     }
        //     cout << endl;
        // }

        int maxSum = 0;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[all - 1][i][j] > maxSum) {
                    maxSum = dp[all - 1][i][j];
                    cnt = times[all - 1][i][j];
                }
                else if (maxSum == dp[all - 1][i][j]) {
                    cnt += times[all - 1][i][j];
                }
            }
        }
        if ( 0 == maxSum) { cout << "0 0" << endl;}
        else {        
            cout << maxSum + sum << " " << cnt / 2 << endl;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                graph[i][j] = 0;
            }
        }

        for (int k = 0; k < all; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dp[k][i][j] = 0;
                    times[k][i][j] = 0;
                }
            }
        }
    }
    return 0;
}