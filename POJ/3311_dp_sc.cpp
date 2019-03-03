
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

const int N = 15;
const int M = (1 << N);
int dp[M][N];
int graph[N][N];
int dis[N][N];

int main() {
    int n;
    while(cin >> n && 0 != n) {
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                cin >> graph[i][j];
            }
        }

        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                dis[i][j] = INT_MAX / 2;
            }
        }

        for (int k = 0; k <= n; ++k) {
            for (int i = 0; i <= n; ++i) {
                for (int j = 0; j <= n; ++j) {
                    dis[i][j] = min(dis[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
        for (int i = 0; i <= n; ++i) {
            dis[i][n + 1] = dis[i][0];
            dis[n + 1][i] = dis[0][i];
        }

        // for (int i = 0; i <= n + 1; ++i) {
        //     for (int j = 0; j <= n + 1; ++j) {
        //         cout << dis[i][j] << "\t";
        //     }
        //     cout << endl;
        // }

        int all = (1 << n + 2);

        for (int i = 0; i < all; ++i) {
            for (int j = 0; j <= n + 1; ++j) {
                dp[i][j] = INT_MAX / 2;
            }
        }
        dp[0][0] = 0;

        for (int i = 1; i < all; ++i) {
            if (0 == (i & 1)) { continue;}
            for (int j = 0; j <= n + 1; ++j) {
                if ((i & 1 << j) > 0) {
                    for (int k = 0; k <= n + 1; ++k) {
                        if ((i & 1 << k) > 0) {
                            dp[i][j] = min(dp[i][j], dp[i ^ 1 << j][k] + dis[k][j]);
                        }
                    }
                }
            }
        }

        // for (int i = 0; i < all; ++i ) {
        //     cout << bitset<5>(i) << ": ";
        //     for (int j = 0; j <= n + 1; ++j) {
        //         cout << (dp[i][j] == INT_MAX/2 ? -1 : dp[i][j]) << "\t";
        //     }
        //     cout << endl;
        // }
        cout << dp[all - 1][n + 1] << endl;
    }
    return 0;
}