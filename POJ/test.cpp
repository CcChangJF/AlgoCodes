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
    int n = 5;
    int comb = (1 << 3) - 1;
    // cout << comb << endl;
    int all = 1 << n;
    while(comb < all) {
        cout << bitset<10>(comb) << endl;
        int x = comb & -comb;
        int y = comb + x;
        comb = ((comb & ~y) / x >> 1) | y;
    }

    return 0;
}