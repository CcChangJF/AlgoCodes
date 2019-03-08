#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 200005;
int a[N], b[N];

int gcd(int a, int b) {
    return 0 == b ? a : gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }
    int ans = 0;
    int any = 0;
    map<pii, int> m;
    for (int i = 0; i < n; ++i) {
        if (0 == a[i]) {
            if (0 == b[i]) { ++any; }
        }
        else {
            if (a[i] < 0) { a[i] = -a[i]; b[i] = -b[i];}
            int d = gcd(abs(a[i]), abs(b[i]));
            ++m[pii(a[i] / d, b[i] / d)];
        }
    }
    for (auto c : m) {
        ans = max(ans, c.second);
    }
    cout << ans + any << endl;
    return 0;
}