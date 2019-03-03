#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll power(int a, int b, int p) {
    if (0 == b) { return 1LL % p;}
    else {
        ll res = power(a, b/2, p);
        if (0 == res) { return 0;}
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
    int t;
    cin >> t;
    while(t--) {
        int m, n; 
        cin >> m >> n;
        ll res = 0;
        for (int i = 0; i < n; ++i) {
            int a,b;
            cin >> a >> b;
            res += power(a, b, m);
        }
        cout << (res % m) << endl;
    }
    return 0;
}