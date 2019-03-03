
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

const int N = 100003;
int nums[N];

class BinaryIndexedTree {
    vector<ll> arr;
    int n;
public:
    BinaryIndexedTree(int sz) {
        this -> n = sz + 1;
        arr = vector<ll>(n, 0);
        for (int i = 1; i < n; ++i) {
            add(i, nums[i]);
        }
    }

    int lowbit(int x) { return x & -x; }
    ll sum(int t) {
        ll res = 0;
        while(t > 0) {
            res += arr[t];
            t -= lowbit(t);
        }
        return res;
    }

    void add(int t, int upd) {
        while(t < n) {
            arr[t] += upd;
            t += lowbit(t);
        }
        return;
    }
};


int main() {
    int n,q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &nums[i]);
    }
    BinaryIndexedTree bit(n);
    for (int i = 0; i < q; ++i) {
        char c;
        int s,e,d;
        scanf(" %c", &c);
        if ('C' == c) {
            scanf("%d %d %d", &s, &e, &d);
            for (int i = s; i <= e; ++i) {
                bit.add(i, d);
            }
        }
        else {
            scanf("%d %d", &s, &e);
            ll ans = bit.sum(e);
            if (0 != s) { ans -= bit.sum(s - 1); }
            printf("%lld\n", ans);
        }
    }
    return 0;
}