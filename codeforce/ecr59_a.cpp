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
    int q;
    cin >> q;
    while(q--) {
        int n;
        string s;
        cin >> n >> s;
        if (n == 2 && s[1] <= s[0]) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
            cout << 2 << endl;
            cout << s[0] << " " << s.substr(1, n) << endl;
        }
    }


    return 0;
}