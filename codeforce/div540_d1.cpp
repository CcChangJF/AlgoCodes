#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 200003;
int nums[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    scanf("%d %d", &n, &m);
    ll total = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &nums[i]);
        total += nums[i];
    }
    if (total < m) {
        printf("-1\n");
    }
    else if (total == m) {
        printf("%d\n", n);
    }
    else {
        sort(nums, nums + n, greater<int>());
        // for (int i = 0; i < n; ++i) {
        //     printf("%d ", nums[i]);
        // }
        // printf("\n");
        ll cur = 0;
        int p = 0;
        int ans = 0;
        ll k = 0;
        while(p < n && cur < m) {
            ++ans;
            int cnt = 0;
            while(p < n && cur < m && total - m >= k + cnt) {
                // printf("p = %d, cur = %d, cnt = %d, k = %d\n", p, cur, cnt, k);
                if (0 >= nums[p] - cnt) { break; }
                k += cnt;
                cur += (nums[p] - cnt);
                ++cnt;
                ++p;
            }
            // printf("p = %d\n", p);
        }
        printf("%d\n", ans);
    }


    return 0;
}