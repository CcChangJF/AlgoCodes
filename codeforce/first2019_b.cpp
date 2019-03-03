#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;

const int N = 15;
int nums[N];

bool isOK(int s, int n) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (0 == (s & 1 << i)) {
            ans += nums[i];
        }
        else {
            ans -= nums[i];
        }
    }
    return 0 == ans % 360;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    int all = 1 << n;
    bool flag = false;
    for (int i = 0; i < all; ++i) {
        if (isOK(i, n)) {
            flag = true;
            break;
        }
    }
    cout << (flag ? "YES" : "NO") << endl;
    return 0;
}