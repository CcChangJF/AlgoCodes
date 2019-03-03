#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int res = INT_MAX;
    for (int c = 1; c < k; ++c) {
        if (0 == n % c) {
            int x = n / c;
            x = x * k + c;
            // if (8 == x) {
            //     cout << x << " " << i << " " << c << endl;
            // }
            res = min(res, x);
        }
    }
    
    cout << res << endl;
    return 0;
}