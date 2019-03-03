#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll mul(ll a, ll b, ll p) {
    ll ans = 0;
    while(0 != b) {
        if (1 == (b & 1)) {
            ans = (ans + a) % p;
        }
        a = a * 2 % p;
        b = (b >> 1);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a,b,p;
    cin >> a >> b >> p;
    ll ans = mul(a, b, p);
    cout << ans << endl;
    return 0;
}