
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
#include <cmath>

typedef long long ll;

using namespace std;

const int MOD = 9901;
const int N = 10000;
int fac[N][2];
// bool prime[50000000];

void factorize(int a) {
    if (a < 2) { return; }
    int cnt = 0;
    for (int i = 2; i * i <= a; ++i) {
        if (0 == a % i) {
            fac[cnt][0] = i;
            while(0 == a % i) {
                a = a / i;
                ++fac[cnt][1];
            }
            ++cnt;
        }
    }
    if ( 1 != a) {
        fac[cnt][0] = a;
        ++fac[cnt][1];
    }
    // cout << cnt << endl;
    return;
}

ll mul(ll a, ll b, ll m) {
    if (0 == a || 0 == b) { return 0;}
    ll ans = 0;
    while( 0 != b) {
        if (1 == (b & 1)) { ans = (ans + a) % m; }
        a = (a * 2) % m;
        b >>= 1;
    }
    return ans;
}

ll power(ll a, ll n, ll m) {
    // cout << a << " " << n << " " << m << endl;
    ll ans = 1 % m;
    while(0 != n) {
        if (1 == (n & 1)) { ans = mul(ans, a, m); }
        a = mul(a, a, m);
        n >>= 1;
    }
    return ans;
}

ll getSum(ll a, ll b) {
    ll t = power(a, b + 1, (ll)MOD * (a - 1));
    // cout << a << " " << b << " " << t << " " << tmp << endl;
    return (t - 1 + (ll)MOD * (a - 1)) / (a - 1);
}

int main() {
    int a,b;
    cin >> a >> b;
    factorize(a);
    ll ans = 1;
    for (int i = 0; ; ++i) {
        if(0 == fac[i][0]) { break;}
        // cout << fac[i][0] << " " << fac[i][1] << endl;
        ans = (ans * getSum(fac[i][0], fac[i][1] * b)) % MOD;
    }
    cout << ans << endl;
    return 0;
}