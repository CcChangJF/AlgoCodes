#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int N = 21;
int graph[N][N];
const int maxN = (1 << N);
int dp[maxN][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }
    int all = (1 << n);
    for (int i = 0; i < all; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j] = INT_MAX / 2;
        }
    }
    dp[0][0] = 0;
    for(int i = 1; i < all; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i & (1 << j)) > 0) {
                for (int k = 0; k < n; ++k) {
                    dp[i][j] = min(dp[i ^ (1 << j)][k] + graph[k][j], dp[i][j]);
                }
            }
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << dp[all - 1][n - 1] << endl;

    return 0;
}