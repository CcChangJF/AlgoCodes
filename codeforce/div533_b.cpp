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
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = 0;
    int index = 0;
    int cnt[28];
    memset(cnt, 0, sizeof(cnt));
    if (1 == k) {
        for (int i = 0; i < n; ++i) {
            ++cnt[s[i] - 'a'];
        }
        
    }
    else {
        index = 1;
        int cur = 1;
        while(index < n) {
            if (s[index] == s[index - 1]) {
                ++cur;
                if (cur == k) {
                    cur = 0;
                    ++cnt[s[index] - 'a'];
                }
            }
            else {
                cur = 1;
            }
            ++index;
        }
    }
    for (int i = 0; i < 28; ++i) {
        if (cnt[i] > ans) { ans = cnt[i]; }
    }
    cout << ans << endl;

    return 0;
}