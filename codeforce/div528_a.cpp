#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int end = s.length() - 1;
    int start = 0;
    vector<char> ans;
    if (1 == s.length() % 2) {
        ans.push_back(s[start++]);
    }
    while(end >= start) {
        ans.push_back(s[end--]);
        if (end >= start) {
            ans.push_back(s[start++]);
        }
    }
    for (int i = ans.size() - 1; i >= 0; --i) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}