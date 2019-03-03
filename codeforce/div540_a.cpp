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
    while(q--) {
        ll n;
        int a,b;
        cin >> n >> a >> b;
        ll ans = 0;
        if (2 * a <= b) {
            ans = n * a;
        }
        else {
            ans = (n >> 1) * b;
            if (1 == (n & 1)) { ans += a;}
        }
        cout << ans << endl;
    }


    return 0;
}