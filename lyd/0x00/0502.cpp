#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int N = 100005;
int rowCnt[N];
int colCnt[N];
// int aux[N];
ll sum[N];

ll calMove(int cnt[N], int n, int aver) {
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + cnt[i - 1] - aver;
    }
    sort(sum + 1, sum + n + 1);
    ll res = 0;
    for (int i = 1; i <= n / 2; ++i) {
        res += sum[n - i + 1] - sum[i];
    }
    return res;
}

int main() {
    cout << INT_MAX << endl;
    ios::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n, m, t;
    cin >> n >> m >> t;
    // n = m = t = 100000;
    for (int i = 0; i < t; ++i) {
        int u,v;
        cin >> u >> v;
        // u = rand() % n;
        // v = rand() % m;
        ++rowCnt[u - 1];
        ++colCnt[v - 1];
    }
    ll ans = 0;
    int flag = 0;
    if (0 == t % n) {
        flag = flag | 1;
        ans = ans + calMove(rowCnt, n, t / n);
    }
    // cout << "row: " << ans << endl;
    if (0 == t % m) {
        flag = flag | 2;
        ans = ans + calMove(colCnt, m, t / m);
    }
    // cout << flag << endl;
    string res = "";
    switch(flag) {
        case 0:
            res = "impossible";break;
        case 1:
            res = "row";break;
        case 2:
            res = "column";break;
        case 3:
            res = "both";break;
    }
    if (0 == flag) {
        cout << res << endl;
    }
    else {
        cout << res << " " << ans << endl;
    }
    return 0;
}