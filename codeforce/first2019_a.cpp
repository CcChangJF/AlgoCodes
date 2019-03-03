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
    string t;
    cin >> t;
    // vector<string> hand = vector<string>(5, "");
    bool flag = false;
    for (int i = 0; i < 5; ++i) {
        string cur;
        cin >> cur;
        if (cur[0] == t[0] || cur[1] == t[1]) {
            flag = true;
        }
    }
    cout << (flag ? "YES" : "NO") << endl;

    return 0;
}