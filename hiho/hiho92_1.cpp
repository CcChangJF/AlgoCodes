#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1003;
int par[N];
char cs[N];
int indegree[N];

bool lessThan(string &a, string &b) {
    int len = min(a.length(), b.length());
    for (int i = 0; i < len; ++i) {
        if (a[i] == b[i]) { continue; }
        else { return a[i] < b[i]; }
    }
    if (len == a.length()) { return true; }
    else { return false; }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int p;
        cin >> cs[i] >> p;
        par[i] = p;
        ++indegree[p];
    }
    string best = "";
    for (int i = 1; i <= n; ++i) {
        if (0 != indegree[i]) { continue; }
        string cur = "";
        cur.push_back(cs[i]);
        int t = i;
        while(0 != par[t]) { cur += cs[par[t]]; t = par[t]; }
        if ("" == best) { best = cur; }
        else if (lessThan(cur, best)) { best = cur; }
    }
    cout << best << endl;


    return 0;
}