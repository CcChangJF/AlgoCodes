#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int N = 101;
int nums[N];
bool mark[N];

void dfs(int cur, int n, int &res) {
    if (cur == n) {
        ++res;
        // for (int i = 0; i < n; ++i) {
        //     cout << nums[i] << " ";
        // }
        // cout << endl;
        return;
    }
    else {
        for (int i = 1; i <= n; ++i) {
            if (!mark[i] && (0 == cur || (i + nums[cur - 1]) & 1 == 1)) {
                mark[i] = true;
                nums[cur] = i;
                dfs(cur + 1, n, res);
                mark[i] = false;
            }
        }
        return;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int res;
    for (n = 1; n < 20; ++n) {
        res = 0;
        dfs(0, n, res);
        cout << res;
        cout << endl;
    }

    return 0;
}