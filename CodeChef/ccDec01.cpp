#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int powers[9] = {0, 1, 10, 100, 1000, 10000,100000, 1000000, 10000000};
const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int len = 0;
        int tmp = n;
        while(0 != tmp) {
            ++len; 
            tmp = tmp / 10;
        }
        // cout << "len: " << len << endl;
        if (len <= 1) {
            cout << n << endl;
        }
        else {
            // cout << "n: " << n << endl;
            ll ans = n % MOD;
            tmp = len;
            while(--tmp > 0) {
                int firstDig = n / powers[len];
                n = (n - firstDig * powers[len]) * 10 + firstDig;
                // cout << firstDig << " " << n << endl;
                ans = (ans * powers[len + 1] + n) % MOD;
            }
            cout << ans << endl;
        }
    }


    return 0;
}