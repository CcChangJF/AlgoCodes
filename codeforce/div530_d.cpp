#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;

const int N = 100003;
int par[N];
int s[N];
vector<int> tree[N];
int ans[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    scanf("%d", &n);
    par[1] = 1;
    for (int i = 1; i < n; ++i) {
        // ans[i] = -1;
        scanf("%d", &par[i + 1]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &s[i]);
    }
    memset(ans, 0, sizeof(ans));
    ans[1] = s[1];
    int minSum = 0;
    for (int i = 2; i <= n; ++i) {
        tree[par[i]].push_back(i);
    }
    // cout << ans[1] << endl;
    // for (int i = 1; i <= n; ++i) {
    //     cout << tree[i].size() << endl;
    // }

    for (int i = 2; i <= n; ++i) {
        if (0 == tree[i].size()) { continue; }
        // cout << i << endl;
        if (-1 != s[i]) { continue; }
        // if (-1 != ans[i]) { continue; }
        // int p = par[i];
        int g = par[i];
        int val = INF;
        for (int j = 0; j < tree[i].size(); ++j) {
            val = min(val, s[tree[i][j]] - s[g]);
        }
        if (val < 0) {
            cout << -1 << endl;
            return 0;
        }
        ans[i] = val;
        for (int j = 0; j < tree[i].size(); ++j) {
            ans[tree[i][j]] = s[tree[i][j]] - s[g] - val;
        }
    }
    ll res = 0;
    for (int i = 1; i <= n; ++i) {
        // cout << ans[i] << endl;
        res += ans[i];
    }
    cout << res << endl;
    return 0;
}