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
    for (int i = 0; i < q; ++i) {
        int l1,r1,l2,r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (l1 > l2) {
            cout << max(l2 + 1, l1) << " " << l2 << endl;
        }
        else {
            cout << l1 << " " << max(l1 + 1, l2) << endl;
        }
    }

    return 0;
}