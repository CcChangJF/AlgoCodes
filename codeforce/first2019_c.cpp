#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 100003;

void deal0(string &s) {
    stack<char> stk;
    for (int i = 0; i < s.length(); ++i) {
        if ('(' == s[i]) {
            stk.push(s[i]);
        }
        else {
            if (!stk.empty() && '(' == stk.top()) {
                stk.pop();
            }
            else {
                stk.push(s[i]);
            }
        }
    }
    // string res = "";
    s = "";
    while(!stk.empty()) {
        s.push_back(stk.top());
        stk.pop();
    }
    // cout << "s: " << s << endl;
    return;
}

bool deal(string &s) {
    for (int i = 1; i < s.length(); ++i) {
        if (s[i] != s[0]) {
            return false;
        }
    }

    string res = "";
    for (int i = s.length() - 1; i >= 0; --i) {
        if ('(' == s[i]) {
            res.push_back(')');
        }
        else {
            res.push_back('(');
        }
    }
    s = res;

    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; 
    cin >> n;
    // vector<string> strs(n, "");
    string str, tmp;
    multiset<string> sets;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> str;
        deal0(str);
        tmp = str;
        // cout << "s: " << str << endl;
        if (deal(str)) {
            // cout << "s: " << str << endl;
            if (0 != sets.count(tmp)) { 
                // cout << i << ", " << ans << ", " << tmp << endl;
                ++ans; 
                auto t = sets.find(tmp);
                sets.erase(t);
            }
            else {
                sets.insert(str);
            }
        }
    }
    cout << ans << endl;


    return 0;
}