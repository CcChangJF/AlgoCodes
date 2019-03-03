#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 500003;
int nums[N];
int aux[N];
int aux1[N];

void merge(int s, int m, int e) {
    for (int i = s; i < e; ++i) {
        aux1[i] = aux[i];
    }
    int cnt = s;
    int p = m;
    while(s < m || p < e) {
        if (p >= e || (s < m && aux1[s] <= aux1[p])) {
            aux[cnt++] = aux1[s++];
        }
        else {
            aux[cnt++] = aux1[p++];
        }
    }
    return;
}

bool isOK(int l, int r, int m, ll k) {
    int pairs = min(m, (r - l) >> 1);
    ll spd = 0;
    for (int i = 0; i < pairs; ++i) {
        int dx = aux[r - 1 - i] - aux[i + l];
        spd += dx * dx;
    }
    if (spd <= k) { return true; }
    return false;
}

int calc(int start, int n, int m, ll k) {
    if (start + 1 >= n) { return n;}
    // cout << "start: " << start << endl;
    int l = start;
    int len = 1;
    int r = l + 1;
    //double expand
    while(isOK(start, r, m, k)) {
        // merge
        for (int i = start; i < r; ++i) {
            nums[i] = aux[i];
        }
        if (r == n) { return n; }
        l = r;
        r = start + len;
        if (r > n) { r = n; }
        sort(aux + l, aux + r);
        merge(start, l, r);
        len <<= 1;
        // for (int i = 0; i < n; ++i) {
        //     cout << nums[i] << " ";
        // }
        // cout << endl;
        // for (int i = 0; i < n; ++i) {
        //     cout << aux[i] << " ";
        // }
        // cout << endl;
        // cout << "double: " << start << ", " << l << ", " << r << endl;
    }
    // cout << l << ", " << r << endl;
    //binary reduce
    while(len > 1) {
        len >>= 1;
        if (l + len > n) { continue; }
        for (int i = l; i < r; ++i) { aux[i] = nums[i]; }
        int mid = l + len;
        sort(aux + l, aux + l + len);
        merge(start, l, mid);
        if (isOK(start, mid, m, k)) {
            l = mid;
            for (int i = start; i < mid; ++i) {
                nums[i] = aux[i];
            }
        }
        else {
            r = mid;
        }
    }
    return l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,m;
        ll k;
        scanf("%d %d %lld", &n, &m, &k);
        for(int i = 0; i < n; ++i) {
            scanf("%d", &nums[i]);
        }
        int ans = 0;
        int r = 0;
        //init aux
        for (int i = 0; i < n; ++i) {
            aux[i] = nums[i];
        }
        while(r < n) {
            ++ans;
            r = calc(r, n, m, k);
            // cout << "r = " << r << endl;
        }
        cout << ans << endl;
    }

    return 0;
}