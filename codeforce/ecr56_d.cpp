
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <ctime>
#include <string.h>

using namespace std;
typedef long long ll;

const int maxN = 300005;
const int MOD = 998244353;


vector<int> graph[maxN];
int mark[maxN];
int power[maxN];
int n, m; 
ll ans = 1LL;
int sz, subsz;

// 1 is odd, 2 is even
bool bfs() {
    for (int node = 1; node <= n; ++node) {
        if (0 != mark[node]) { continue;}
        if (0 == graph[node].size()) {
            ans = (ans * 3) % MOD;
            continue;
        }
        queue<int> q;
        // dp[node] = 1;
        mark[node] = 2;
        q.push(node);
        int total = 1;
        int count = 0;
        while(!q.empty()) {
            int cur = q.front();
            int odd = mark[cur];
            q.pop();
            for (int i = 0; i < graph[cur].size(); ++i) {
                int v = graph[cur][i];
                if (0 == mark[v]) {
                    ++total;
                    q.push(v);
                    mark[v] = 2 / odd;
                    if (1 == mark[v]) { ++count;}
                   
                }
                else if (mark[v] != 2 / odd) {
                    return false;
                }
            }
        }
        ans = (ans * (power[count] + power[total - count])) % MOD;
        // cout << "cur node: " << node << ", " << ans << endl;
    }
    return true;
}

bool dfs(int node, int c = 1) {
    mark[node] = c;
    if (1 == c) { ++subsz; }
    ++sz;
    bool flag = true;
    for (int i = 0; i < graph[node].size(); ++i) {
        int v = graph[node][i];
        if (0 == mark[v]) {
            flag = flag && dfs(v, 2 / c);
            if (!flag) { return flag;}
        }
        else if (mark[v] == c) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    power[0] = 1;
    for (int i = 1; i < maxN / 2; ++i) {
        power[i] = (power[i - 1] * 2) % MOD;
    }
    cin >> t;
    while (t--) {
        // memset(dp, 0, sizeof(dp));
        // memset(mark, 0, sizeof(mark));
        // memset(graph, 0, sizeof(graph));
        for (int i = 1; i <= n; ++i) {
            mark[i] = 0;
            graph[i].clear();
        }
        cin >> n >> m;
        // for (int i = 0; i < n; ++i) {
        //     cout << graph[i].size() << endl;
        // }
        for(int i = 0; i < m; ++i) {
            int u,v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        ans = 1LL;
        if (!bfs()) {
            ans = 0LL;
        }
        // for (int node = 1; node <= n; ++node) {
        //     if (0 != mark[node]) {continue;}
        //     sz = 0;
        //     subsz = 0;
        //     if (!dfs(node, 1)) {
        //         ans = 0LL;
        //         break;
        //     }
        //     ans = (ans * ((power[subsz] + power[sz - subsz]) % MOD)) % MOD;
        // }
        cout << ans << endl;

    }

    return 0;
}