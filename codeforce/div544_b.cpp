#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 200005;
int nums[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &nums[i]);
    }

    multiset<int> m;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        auto t = m.find(nums[i] % k);
        if (m.end() != t) {
            ++ans;
            m.erase(t);
        }
        else {
            m.insert((k - (nums[i] % k)) % k);
        }
    }
    printf("%d\n", ans << 1);

    return 0;
}