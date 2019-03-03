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
    int x = 0;
    int y = 1;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        x = max(x, nums[i]);
    }
    unordered_set<int> d;
    for (int i = 0; i < n; ++i) {
        if (0 != x % nums[i] || 0 != d.count(nums[i])) {
            y = max(y, nums[i]);
        }
        else {
            d.insert(nums[i]);
        }
        // cout << y << endl;
    }
    cout << x << " " << y << endl;

    return 0;
}