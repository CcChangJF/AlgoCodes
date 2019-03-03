
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <bitset>
#include <cmath>
#include <climits>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;
const int maxN = 100003;

#define lson(x) ((x) << 1)
#define rson(x) ((x) << 1 | 1)

ll sum[maxN << 2];
int add[maxN << 2];
int nums[maxN];

void pushUp(int pos) {
    sum[pos] = sum[lson(pos)] + sum[rson(pos)];
}

void build(int pos, int l, int r) {
    add[pos] = 0;
    if (l == r - 1) {
        sum[pos] = nums[l];
    }
    else {
        int mid = l + r >> 1;
        build(lson(pos), l, mid);
        build(rson(pos), mid, r);
        pushUp(pos);
    }
    return; 
}

void pushDown(int pos, int ln, int rn) {
    if (0 != add[pos]) {
        add[lson(pos)] += add[pos];
        add[rson(pos)] += add[pos];
        sum[lson(pos)] += (ll)add[pos] * ln;
        sum[rson(pos)] += (ll)add[pos] * rn;
        add[pos] = 0;
        return;
    }
}

void update(int pos, int a, int b, int c, int l, int r) {
    if (b <= l || a >= r) { return; }
    else if (a <= l && r <= b) {
        sum[pos] += (r - l) * c;
        add[pos] += c;
    }
    else {
        int mid = l + r >> 1;
        pushDown(pos, mid - l, r - mid);
        if (a < mid) { update(lson(pos), a, b, c, l, mid); }
        if (b >= mid) { update(rson(pos), a, b, c, mid, r); }
        pushUp(pos);
    }
    return;
}

ll query(int pos, int a, int b, int l, int r) {
    if (b <= l || a >= r) { return 0; }
    else if (a <= l && r <= b) { return sum[pos]; }
    else {
        int mid = l + r >> 1;
        pushDown(pos, mid - l, r - mid);
        ll ans = 0;
        if (a < mid) { ans += query(lson(pos), a, b, l, mid); }
        if (b >= mid) { ans += query(rson(pos), a, b, mid, r); }
        return ans;
    }
}

int main() {
    int n,q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &nums[i]);
    }
    build(1, 1, n + 1);
    for (int i = 0; i < q; ++i) {
        char c;
        int a, b, d;
        scanf(" %c", &c);
        if ('C' == c) {
            scanf("%d %d %d", &a, &b, &d);
            update(1, a, b + 1, d, 1, n + 1);
        }
        else {
            scanf("%d %d", &a, &b);
            printf("%lld\n", query(1, a, b + 1, 1, n + 1));
        }
    }
    return 0;
}