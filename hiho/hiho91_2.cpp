#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 100003;
int nums[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    scanf("%d", &n);
    int minVal = INF;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &nums[i]);
        if (nums[i] < minVal) { minVal = nums[i]; }
        ans += nums[i];
    }
    for (int i = 0; i < n; ++i) {
        ans += minVal * nums[i];
    }
    ans -= minVal * minVal;
    cout << ans << endl;



    return 0;
}