#include <bits/stdc++.h>

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

//将pos中保存的该区间的增量分别下发到左右子区间中
void pushDown(int pos, int ln, int rn) {
    if (0 != add[pos]) {
        add[lson(pos)] += add[pos];
        add[rson(pos)] += add[pos];
        sum[lson(pos)] += (ll)add[pos] * ln;
        sum[rson(pos)] += (ll)add[pos] * rn;
        add[pos] = 0;
    }
    return;
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
    ios::sync_with_stdio(false);
    cin.tie(0);



    return 0;
}