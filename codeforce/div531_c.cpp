#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 101;
int nums[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,x,y;
    cin >> n >> x >> y;
    int cntx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        if (nums[i] <= x) {
            ++cntx;
        }
    }
    if (x > y) {
        cout << n << endl;
    }
    else {
        cout << (cntx + 1) / 2 << endl;
    }

    return 0;
}