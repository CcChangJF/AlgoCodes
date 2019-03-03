#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int N = 200005;
int nums[N][2];
int res[N];
int mark[N];

void dfs(int cur, int &tot) {
    if (!mark[cur]) {
        mark[cur] = true;
        mark[nums[cur][0]] = true;
        dfs(nums[cur][1], tot);

        mark[nums][cur[0]] = false;
        mark[nums[cur][1]] = true;
        dfs(nums[cur][0], tot);
        res[tot--] = cur;
        // cout << res[tot + 1] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i][0] >> nums[i][1];
    }
    int tot = n;

    dfs(1, tot);
    for (int i = 1; i <= n; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}