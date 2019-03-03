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
    string pat;
    cin >> pat;
    int k;
    cin >> k;
    int flakes = 0;
    int canes = 0;
    int len = pat.length();
    for (int i = 0; i < pat.length(); ++i) {
        if ('?' == pat[i]) { ++canes; }
        if ('*' == pat[i]) { ++flakes; }
    }
    if (0 == canes && 0 == flakes) {
        if (len == k) {
            cout << pat << endl;
        }
        else {
            cout << "Impossible" << endl;
        }
    }
    else if (0 == flakes) {
        if (k < len - 2 * canes || k > len - canes)  {
            cout << "Impossible" << endl;
        }
        else {
            string ans = "";
            int cnt = 0;
            int i = 0;
            for (i = 0; i < len; ++i) {
                if (cnt == 2 * canes - (len - k)) { break; }
                if ('?' == pat[i]) { 
                    ++cnt; 
                }
                else {
                    ans.push_back(pat[i]);
                }
            }
            for (; i < len; ++i) {
                if ('?' == pat[i]) {
                    ans.pop_back();
                }
                else {
                    ans.push_back(pat[i]);
                }
            }
            cout << ans << endl;
        }
    }
    else  {
        if (k < len - 2 * (flakes + canes)) {
            cout << "Impossible" << endl;
        }
        else {
            string ans = "";
            int last = len - 1;
            while(last >= 0 && '*' != pat[last]) { --last; }
            int index = 0;
            for (int i = 0; i < len; ++i) {
                if ('?' == pat[i] || '*' == pat[i]) {
                    ans.pop_back();
                    if ('*' == pat[i]) { index = ans.size(); }
                }
                else {
                    ans.push_back(pat[i]);
                }
            }
            string add = string(k - (len - 2 * (flakes + canes)), pat[last - 1]);
            // cout << add << ", " << pat[last - 1] << ", " << k - (len - 2 * (flakes + canes)) << endl;
            if ("" != add) {
                ans.insert(ans.begin() + index, add.begin(), add.end());
            }
            cout << ans << endl;
        }
    }
    return 0;
}