#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll power(int a, int b, int p) {
    if (0 == b) { 
        return 1LL % p;
    }
    else {
        ll res = power(a, b / 2, p);
        res = res * res % p;
        if (1 == (b & 1)) {
            res = res * a % p;
        }
        return res;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b,p;
    cin >> a >> b >> p;
    ll res = 1LL;
    res = power(a, b, p);
    cout << res << endl;

    return 0;
}
