#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 100003;
int nums[N];
int exist[N];
int ans[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &nums[i]);
    }
    int cnt = 0;
    int end = 0;
    // int start = 0;
    while(end < m) {
        // cout << cnt << endl;
        if (0 == exist[nums[end++]]++) {
            ++cnt;
        }
        if (n == cnt) {
            // cout <<"hello: " << end << endl;
            // cnt = 0;
            ans[end - 1] = 1;
            for (int i = 1; i <= n; ++i) {
                --exist[i];
                if (0 == exist[i]) { --cnt;}
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        cout << ans[i];
    }
    cout << endl;

    return 0;
}