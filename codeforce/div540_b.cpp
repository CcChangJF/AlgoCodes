#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 200003;
int nums[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    scanf("%d", &n);
    int sumOdd = 0;
    int sumEven = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &nums[i]);
        if (1 == (i & 1)) { sumEven += nums[i]; }
        else { sumOdd += nums[i]; }
    }
    int curOdd = 0;
    int curEven = 0;
    int laterOdd = 0;
    int laterEven = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        laterEven = sumEven - curEven;
        laterOdd = sumOdd - curOdd;
        if (1 == (i & 1)) {
            laterEven -= nums[i];
        }
        else {
            laterOdd -= nums[i];
        }
        if (curOdd + laterEven == curEven + laterOdd) { ++ans; }
        if (1 == (i & 1)) { curEven += nums[i]; }
        else { curOdd += nums[i]; }
    }
    cout << ans << endl;



    return 0;
}