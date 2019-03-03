#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int N = 100005;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    // ll ans = 0;
    set<ll> ans;
    int cnt = 0;
    for (int i = sqrt(n); i > 0; --i) {
        if (0 == n % i) {
            ans.insert((ll)(1 + n - (n - 1) % i) * n / i / 2);
            int t = n / i;
            ans.insert((ll)(1 + n - (n - 1) % t) * n / t / 2);
        }

    }
    // sort(ans, ans + cnt);
    // for (int i = 0; i < cnt; ++i) {
    //     cout << ans[i] << " ";
    // }
    for ( auto i : ans) {
        cout << i << " ";
    }
    cout << endl;


    return 0;
}