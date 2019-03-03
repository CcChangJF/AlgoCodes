
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

class edge{
public:
    int from, to, cost;
    edge(int from = 0, int to = 0, int cost = 0) {
        this -> from = from;
        this -> to = to;
        this -> cost = cost;
    }
};

const int maxN = 300001;
vector<vector<int> > graph;
edge edges[maxN];
int auxGraph[maxN];
bool mark[maxN];

ll dp[maxN];
// int bestNode[maxN];

ll ans = 0;
ll gas[maxN];
int n;

void dfs(int u) {
    mark[u] = true;
    for (int i = 0; i < graph[u].size(); ++i) {
        edge e = edges[graph[u][i]];
        int v = (u == e.from) ? e.to : e.from;
        if (!mark[v]) {
            auxGraph[v] = u;
            dfs(v);
        }
    }
    dp[u] = max(dp[u], gas[u]);
    int maxChild = -1;
    ll maxVal = -1;
    int secChild = -1;
    ll secVal = -1;
    for (int i = 0; i < graph[u].size(); ++i) {
        edge e = edges[graph[u][i]];
        int v = (e.from == u) ? e.to : e.from;
        if (auxGraph[u] == v) {
            continue;
        }
        ll curVal = gas[u] + dp[v] - e.cost;
        // cout << u << " , " << v << " . dp: " << dp[v] << " , cost: " << e.cost << " " << curVal << endl;
        if (maxVal < curVal) {
            maxVal = curVal;
            maxChild = v;
            dp[u] = max(dp[u], maxVal);
        }
    }

    if (-1 != maxChild) {
        for (int i = 0; i < graph[u].size(); ++i) {
            edge e = edges[graph[u][i]];
            int v = (e.from == u) ? e.to : e.from;
            if (auxGraph[u] == v || maxChild == v) {
                continue;
            }
            ll curVal = gas[u] + dp[v] - e.cost;
            if (secVal < curVal) {
                secVal = curVal;
                secChild = v;
            }
        }
    }
    ans = max(ans, dp[u]);
    if (-1 != secChild) {
        // cout << "max: " << maxChild << " : " << maxVal  << ", sec: " << secChild << ", " << secVal << endl;
        ans = max(ans, secVal + maxVal - gas[u]);
    }
    // cout << "u : " << u << " | " << dp[u] << " | " << ans << endl;
    return;
}

int main() {
    while(cin >> n) {
        memset(dp, 0, sizeof(dp));
        // memset(bestNode, 0, sizeof(bestNode));
        memset(mark, 0, sizeof(mark));
        graph = vector<vector<int> >(n + 1, vector<int>());
        for (int i = 0; i < n; ++i) {
            cin >> gas[i + 1];
        }
        for (int i = 1; i < n; ++i) {
            edge e;
            cin >> e.from >> e.to >> e.cost;
            edges[i] = e;
            graph[e.from].push_back(i);
            graph[e.to].push_back(i);
        }
        ans = 0;
        auxGraph[1] = 1;
        dfs(1);
        cout << ans << endl;
    }
    return 0;
}