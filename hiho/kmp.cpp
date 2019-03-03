#include <bits/stdc++.h>

using namespace std;

const int N = 10001;
int nxt[N];

void pattern(string &pat) {
    int lenP = pat.length();
    int len = 0;
    int p = 1;
    nxt[0] = 0;
    while(p < lenP) {
        if (pat[p] == pat[len]) {
            ++len;
            nxt[p] = len;
            ++p;
        }
        else {
            if (0 == len) {
                nxt[p] = 0;
                ++p;
            }
            else {
                len = nxt[len - 1];
            }
        }
    }
    return;
}

int kmp(string &p, string &s) {
    pattern(p);
    int lenP = p.length();
    int lenS = s.length();
    int is = 0;
    int ip = 0;
    int ans = 0;
    while(is < lenS) {
        if (p[ip] == s[is]) {
            ++ip;
            ++is;
        }
        else {
            if (0 == ip) {
                ++is;
            }
            else {
                ip = nxt[ip - 1];
            }
        }

        if (ip == lenP) {
            ++ans;
            ip = nxt[ip - 1];
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    string s,p;
    while(t--) {
        cin >> p >> s;
        cout << kmp(p, s) << endl;
    }
    
    return 0;
}