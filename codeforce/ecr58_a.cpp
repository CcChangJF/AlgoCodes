#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int l,r,d;
        cin >> l >> r >> d;
        int ans = -1;
        if (d < l) {
            ans = d;
        }
        if (-1 == ans) {
            ans = (r / d + 1) * d;
        }
        cout << ans << endl;
    }


    return 0;
}