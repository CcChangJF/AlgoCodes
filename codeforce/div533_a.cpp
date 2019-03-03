#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1001;
int nums[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int minv = 101;
    int maxv = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        if (nums[i] < minv) { minv = nums[i]; }
        if (nums[i] > maxv) { maxv = nums[i]; }
    }
    int bestt = 0;
    int bestans = INF;
    for (int i = minv; i <= maxv; ++i) {
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            int tmp = min(abs(nums[j] - i), abs(nums[j] - i + 1));
            tmp = min(tmp, abs(nums[j] - i - 1));
            ans += tmp;
        }
        if (ans < bestans) {
            bestans = ans;
            bestt = i;
        }
    }
    cout << bestt << " " << bestans << endl;
    // sort(nums, nums + n);
    // int t = 0;
    // if (1 == (n & 1)) { t = nums[n / 2]; }
    // else {
    //     t = ((nums[n / 2] + nums[n / 2 + 1]) / 2.0 + 0.5);
    // }
    // int ans = 0;
    // for (int i = 0; i < n; ++i) {
    //     int tmp = min(abs(nums[i] - t), abs(nums[i] - t + 1));
    //     tmp = min(tmp, abs(nums[i] - t - 1));
    //     // cout << i << " " << tmp << endl;
    //     ans += tmp;
    //     // cout << i << " " << ans << endl;
    // }
    // cout << t << " " << ans << endl;
    return 0;
}