#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int N = 21;
int graph[N][N];
bool mark[N];
int ans = INT_MAX;
void dfs(int node, int n, int total, int sum) {
    if (sum + graph[node][n - 1] >= ans) { return; }
    // cout << node << " " << sum << " " << total << endl;
    if (total == n - 1 && 0 != graph[node][n-1]) {
        ans = min(ans, sum + graph[node][n-1]);
        return;
    }
    else {
        mark[node] = true;
        for (int i = 0; i < n - 1; ++i) {
            if (!mark[i] && 0 != graph[node][i]) {
                dfs(i, n, total + 1, sum + graph[node][i]);
            }
        }
        mark[node] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            cin >> graph[row][col];
        }
    }
    dfs(0, n, 1, 0);
    cout << ans << endl;

    return 0;
}