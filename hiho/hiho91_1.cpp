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
    string str;
    cin >> str;
    int last[28];
    int n = str.length();
    for (int i = 0; i < n; ++i) {
        last[str[i] - 'a'] = i;
    }
    int ans = 0;
    int end = 0;
    while(end < n) {
        ++ans;
        int start = end;
        while(start <= end) {
            end = max(end, last[str[start] - 'a']);
            ++start;
        }
        ++end;
    }
    cout << ans << endl;

    return 0;
}