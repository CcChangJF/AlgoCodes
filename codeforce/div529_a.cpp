#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    int n;
    cin >> n >> s;
    vector<char> res;
    int cnt = 0;
    int cur = 0;
    while (cur < n) {
        res.push_back(s[cur]);
        cur += ++cnt;
    }
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i];
    }
    cout << endl;


    return 0;
}