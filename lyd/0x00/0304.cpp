#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int N = 100005;
int nums[N];
int dif[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll pos = 0;
    ll neg = 0;
    cin >> nums[0];
    dif[0] = nums[0];
    for (int i = 1; i < n;++i) {
        cin >> nums[i];
        dif[i] = nums[i] - nums[i - 1];
        if (dif[i] > 0) {
            pos += dif[i];
        }
        else {
            neg -= dif[i];
        }
    }
    cout << max(pos, neg) << endl;
    cout << abs(pos - neg) + 1 << endl;

    return 0;
}