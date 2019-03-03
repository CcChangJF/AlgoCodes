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
    int a,b;
    int u1,w1,u2,w2;
    cin >> a >> b;
    cin >> u1 >> w1 >> u2 >> w2;
    if (w1 < w2) {
        swap(w1, w2);
        swap(u1, u2);
    }
    int w = a + (w1 + b) * (b - w1 + 1) / 2;
    w = w - u1;
    if (w <= 0) { w = 0; }
    w += (w1 - 1 + w2) * (w1 - w2) / 2;
    w = w - u2;
    if (w <= 0) { w = 0; }
    w = w + (w2 - 1) * (w2) / 2;
    cout << w << endl;

    return 0;
}