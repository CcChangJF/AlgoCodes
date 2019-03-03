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

bool isOK(int l, int r, int m, ll k) {
    // printf("l = %d, r = %d, m = %d\n", l, r, m);
    // for (int i = l; i < r; ++i) {
    //     cout << aux[i] << " ";
    // }
    // cout << endl;
    int pairs = min(m, r - l >> 1);
    ll spd = 0;
    for (int i = 0; i < pairs; ++i) {
        ll dx = aux[r - 1 - i] - aux[i + l];
        spd += dx * dx;
    }
    if (spd <= k) { return true;}
    else { return false; }
}

void merge(int l, int mid, int r) {
    if (l + 1 >= r) { return; }
    int p = l;
    int q = mid;
    int cnt = l;
    for (int i = l; i < r; ++i) {
        aux1[i] = aux[i];
    }
    while(p < mid || q < r) {
        if (q >= r || (p < mid && aux1[p] <= aux1[q])) { aux[cnt++] = aux1[p++]; }
        else { aux[cnt++] = aux1[q++]; }
    }
    return;
}

int calc(int start, int n, int m, ll k) {
    if (start + 1 >= n) { return n; }
    int l = start;
    int p = 1;
    int r = l + p;
    while(isOK(start, r, m, k)) {
        // printf("l = %d, p = %d, r = %d\n", l, p, r);
        for (int i = start; i < r; ++i) { nums[i] = aux[i]; }
        if (r == n) { return n;}
        p <<= 1;
        l = r;
        r = min(l + p, n);
        sort(aux + l, aux + r);
        merge(start, l, r);
    }
    for (int i = start; i < r; ++i) { aux[i] = nums[i]; }
    // cout << start << ", " << l << ", " << r << endl;
    while(p > 1) {
        p >>= 1;
        if (l + p >= n) { continue; }
        // int mid = l + r >> 1;
        sort(aux + l, aux + l + p);
        merge(start, l, l + p);
        if (isOK(start, l + p, m, k)) { 
            for (int i = start; i < l + p; ++i) { nums[i] = aux[i]; }
            l = l + p; 
        }
        else { 
            for (int i = start; i < l + p; ++i) { aux[i] = nums[i]; }
            // r = mid; 
        }
    }


    // while (l < r) {
    //     int mid = ((l + r) / 2.0 + 0.5);
    //     sort(aux + l, aux + mid);
    //     merge(start, l, mid);
    //     if (isOK(start, mid, m, k)) {
    //         for (int i = start; i < mid; ++i) { nums[i] = aux[i]; }
    //         l = mid;
    //     }
    //     else {
    //         for (int i = start; i < mid; ++i) { aux[i] = nums[i]; }
    //         r = mid;
    //     }
    // }
    return l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // ifstream cin("in.txt");
    // freopen("in.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,m;
        ll k;
        scanf("%d %d %lld", &n, &m, &k);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &nums[i]);
        }
        for (int i = 0; i < n; ++i) {
            aux[i] = nums[i];
        }
        int ans = 0;
        int end = 0;
        while(end < n) {
            ++ans;
            end = calc(end, n, m, k);
            // cout << "end: " << end << endl;
        }
        cout << ans << endl;
    }

    return 0;
}