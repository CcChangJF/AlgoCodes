#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int N = 100005;
int nums[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    ll ans = 0;
    sort(nums, nums + n);
    for (int i = 0; i < n / 2; ++i) {
        ans += nums[n - 1 - i] - nums[i];
    }
    cout << ans << endl;

    return 0;
}