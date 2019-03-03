
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

typedef long long ll;

using namespace std;

ll power(ll a, ll b, int p) {
    ll ans = 1 % p;
    while(0 != b) {
        if (1 == (b & 1)) { ans = ans * a % p;}
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int m, n;
        cin >> m >> n;
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ll a,b;
            cin >> a >> b;
            ans = (ans + power(a, b, m)) % m;
        }
        cout << ans << endl;
    }
    return 0;
}