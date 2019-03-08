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
    int h1,m1,h2,m2;
    scanf("%d:%d", &h1, &m1);
    scanf("%d:%d", &h2, &m2);
    if (h2 < h1) {
        h1 += 24;
    }
    if ((h1 % 2) != (h2 % 2)) {
        m2 += 60;
    }
    int m3 = (m1 + m2) >> 1;
    int h3 = ((h1 + h2) >> 1 % 24) + m3 / 60;
    m3 %= 60;
    printf("%02d:%02d\n", h3, m3);
    return 0;
}