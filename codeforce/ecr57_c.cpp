#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // for (int n = 180;;++n) {
    //     if ((n - 2) * 180 % n == 0 &&  179 == (n - 2) * 180 / n) {
    //         cout << n << endl;
    //         break;
    //     }
    // }

    int t;
    cin >> t;
    while(t--) {
        int ang;
        cin >> ang;
        int ans = INT_MAX;
        for (int i = 1; i * i <= ang; ++i) {
            if (0 == ang % i) {
                if ((0 == (180 / i - 2) * 180 % ((180 / i - 2))) && ang <= (180 - 2 * i)) {
                    ans = min(ans, 180 / i);
                }
                if (0 == (180 / (ang / i) - 2) * 180 % ((180 / (ang / i) - 2)) && ang <= (180 - 2 * ang / i)) {
                    ans = min(ans, 180 * i / ang);
                }
            }
        }
        // cout << ans << endl;
        if (INT_MAX == ans || ang > (ll)(ans - 2) * 180 / ans) {
            ans = -1;
        }
        if (179 == ang) {
            ans = 360;
        }
        cout << ans << endl;
    }


    return 0;
}