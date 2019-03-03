#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    // cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int> > cnt(n);
    vector<string> s(2 * n - 2);
    for (int i = 0; i < 2 * n - 2; ++i) {
        cin >> s[i];
        cnt[s[i].length()].push_back(i);
    }

    vector<char> pre;
    vector<char> suf;
    vector<char> ans(2 * n - 2);
    string a = s[cnt[1][0]] + s[cnt[n - 1][0]];
    string b = s[cnt[n - 1][1]] + s[cnt[1][1]];

    string c = s[cnt[1][0]] + s[cnt[n - 1][1]];
    string d = s[cnt[n - 1][0]] + s[cnt[1][1]];
    if (a == b || c == d) {
        pre.push_back(s[cnt[1][0]][0]);
        ans[cnt[1][0]] = 'P';
        suf.push_back(s[cnt[1][1]][0]);
        ans[cnt[1][1]] = 'S';
    }
    else {
        suf.push_back(s[cnt[1][0]][0]);
        ans[cnt[1][0]] = 'S';
        pre.push_back(s[cnt[1][1]][0]);
        ans[cnt[1][1]] = 'P';
    }
    
    for (int i = 2; i < n; ++i) {
        bool flag = true;
        for (int j = 0; j < i - 1; ++j) {
            if (pre[j] != s[cnt[i][0]][j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            pre.push_back(s[cnt[i][0]][i - 1]);
            ans[cnt[i][0]] = 'P';
            suf.push_back(s[cnt[i][1]][0]);
            ans[cnt[i][1]] = 'S';
        }
        else {
            suf.push_back(s[cnt[i][0]][0]);
            ans[cnt[i][0]] = 'S';
            pre.push_back(s[cnt[i][1]][i - 1]);
            ans[cnt[i][1]] = 'P';
        }


        // if (pre[i - 2] == s[cnt[i][0]][i - 2]) {
        //     pre.push_back(s[cnt[i][0]][i - 1]);
        //     ans[cnt[i][0]] = 'P';
        //     suf.push_back(s[cnt[i][1]][0]);
        //     ans[cnt[i][1]] = 'S';
        // }
        // else if (pre[i - 2] == s[cnt[i][1]][i - 2]) {
        //     pre.push_back(s[cnt[i][1]][i - 1]);
        //     ans[cnt[i][1]] = 'P';
        //     suf.push_back(s[cnt[i][0]][0]);
        //     ans[cnt[i][0]] = 'S';
        // }
        // cout << string(pre.begin(), pre.end()) << " " << string(suf.begin(), suf.end()) << endl;

        // else if (suf[i - 2] == s[cnt[i][0]][i - 1]) {
        //     suf.push_back(s[cnt[i][0]][0]);
        //     ans[cnt[i][0]] = 'S';
        //     pre.push_back(s[cnt[i][1]][i - 1]);
        //     ans[cnt[i][1]] = 'P';
        // }
        // else {
        //     suf.push_back(s[cnt[i][1]][0]);
        //     ans[cnt[i][0]] = 'S';
        //     pre.push_back(s[cnt[i][0]][i - 1]);
        //     ans[cnt[i][1]] = 'P';
        // }
    }
    for (int i = 0; i < 2 * n - 2; ++i) {
        cout << ans[i];
    }
    cout << endl;




    return 0;
}