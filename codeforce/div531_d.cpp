#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;
int cnt[3];
int cur[3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        int t = s[i] - '0';
        ++cnt[t];
    }
    vector<int> ans(n, 0);
    for (int i = 0; i < n; ++i) {
        int t = s[i] - '0';
        // ++cur[t];
        switch(t) {
            case 0:
            if (cur[t] < n / 3) { ++cur[t]; ans[i] = t; }
            else {
                if (cnt[1] < n / 3) {
                    ans[i] = 1;
                    ++cnt[1];
                    ++cur[1];
                }
                else {
                    ans[i] = 2;
                    ++cnt[2];
                    ++cur[2];
                }
            }
            break;
            case 1:
            if (cnt[1] > n / 3 && cnt[0] < n / 3) {
                ans[i] = 0;
                --cnt[1];
                ++cnt[0];
                ++cur[0];
            }
            else if (cnt[1] > n / 3 && cnt[0] >= n / 3) {
                if (cur[1] < n / 3) { ++cur[t]; ans[i] = t;}
                else {
                    ans[i] = 2;
                    ++cnt[2];
                    --cnt[1];
                    ++cur[2];
                }
            }
            else {
                ans[i] = t;
                ++cur[t];
            }
            break;
            case 2:
            if (cnt[2] > n / 3) {
                if (cnt[0] < n / 3) {
                    ans[i] = 0;
                    ++cnt[0];
                    --cnt[2];
                    ++cur[0];
                }
                else {
                    ans[i] = 1;
                    ++cnt[1];
                    --cnt[2];
                    ++cur[1];
                }
            }
            else {
                ans[i] = 2;
                ++cur[2];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i];
    }
    cout<< endl;


    return 0;
}