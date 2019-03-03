
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
    return;
}

int power(int a, int n) {
    int ans = 1;
    while(0 != n) {
        if (1 == (n & 1)) { ans = ((ll)ans * a) % MOD; }
        a = (ll)a * a % MOD;
        n >>= 1;
    }
    return ans;
}

int getSum(int a, int b) {
    if (0 == a) { return 0;}
    if (0 == b) { return 1;}
    int t = getSum(a, (b - 1) / 2);
    int cur = power(a, (b + 1) / 2);
    t = (t + t * cur % MOD) % MOD;
    if (0 == (b & 1)) {
        t = t + power(a, b) % MOD;
    }
    return t;
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