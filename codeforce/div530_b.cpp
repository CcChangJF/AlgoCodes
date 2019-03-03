#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int minSum = INF;
    int cur = 0;
    for (int i = 1; i * i <= n; ++i) {
        cur = i + n / i;
        if (0 != n % i) { ++cur; }
        if (minSum > cur) { minSum = cur;}
    }
    cout << minSum << endl;

    return 0;
}