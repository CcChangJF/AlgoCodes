#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int N = 100005;
int nums[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    cin >> nums[0];
    map<int, ll> m;
    vector<int> big;
    int lar = nums[0];
    for (int i = 1; i < n; ++i) {
        cin >> nums[i];
        // if (0 == m.count(nums[i])) {
        //     big.push_back(nums[i]);
        // }
        lar = max(lar, nums[i]);
        ++m[nums[i]];
    }
    // sort(big.begin(), big.end());
    ll ans = 0;
    // int end = big.size() - 1;
    int cur = lar;
    while(nums[0] + m[cur] <= cur && m[cur] * y - m[cur] * x <= x) {
        // cout << cur << " " << m[cur] << " " << nums[0] << " " << ans << endl;
        ans = ans + m[cur] * y;
        nums[0] += m[cur];
        m[cur - 1] = m[cur - 1] + m[cur];
        --cur;
    }
    if (y < x) {
        ans = ans + (cur - nums[0] + 1) * y;
    }
    else {
        ans = ans + (cur - nums[0] + 1) * x;
    }
    // ans = ans + (cur - nums[0] + 1) * x;
    cout << ans << endl;

    return 0;
}