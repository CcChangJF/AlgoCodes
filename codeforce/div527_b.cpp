#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    int res = 0;
    for (int i = 1; i < n; i = i + 2) {
        res += nums[i] - nums[i - 1];
    }
    cout << res << endl;

    return 0;
}