#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
const int N = 200003;
int nums[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    // cin >> n;
    scanf("%d", &n);
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &nums[i]);
        cnt[nums[i]] = i;
    }
    ll ans = 1;
    int end = 0;
    bool flag = true;
    while(end < n) {
        int start = end;
        while(start <= end) {
            end = max(end, cnt[nums[start]]);
            ++start;
        }
        ++end;
        if (!flag) ans = (ans << 1) % MOD;
        flag = false;
        
    }
    cout << ans << endl;


    return 0;
}