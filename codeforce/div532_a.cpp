#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;

const int N = 101;
int nums[N];
int aux[N];

int getVal(int n, int k, int b) {
    for (int i = 0; i < n; ++i) {
        if (0 == abs(i - b) % k) {
            aux[i] = 0;
        }
    }
    int s = 0;
    int t = 0;
    for (int i = 0; i < n; ++i) {
        if (1 == aux[i]) {
            ++t;
        }
        else if (-1 == aux[i]) {
            ++s;
        }
    }
    return abs(s - t);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    int ans = 0;
    for (int b = 1; b < n; ++b) {
        memcpy(aux, nums, sizeof(aux));
        for (int i = 0; i < n; ++i) {
            ans = max(ans, getVal(n, k, b));
        }
    }
    cout << ans << endl;
    return 0;
}