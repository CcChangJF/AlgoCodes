
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

typedef long long ll;

using namespace std;


struct edge{
    int dest;
    ll cost;
};

const int maxN = 300005;

vector<edge> graph[maxN];
ll dis[maxN];
ll gas[maxN];
int n;
ll ans = 0;

void dfs(int node, int par, ll cost) {
    pair<int, ll> first = make_pair(0L, 0L);
    pair<int, ll> sec = make_pair(0L, 0L);
    for (int i = 0; i < graph[node].size(); ++i) {
        edge e = graph[node][i];
        if (par != e.dest) {
            dfs(e.dest, node, e.cost);
            if (dis[e.dest] > sec.second) { 
                sec.first = e.dest; 
                sec.second = dis[e.dest];
            }
            if (sec.second > first.second) {
                swap(first, sec);
            }
        }
    }
    dis[node] = gas[node] + max(first.second, 0LL) - cost;
    ll curDis = gas[node] + max(first.second, 0LL) + max(sec.second, 0LL);
    ans = max(ans, curDis);
}

int main() {
    memset(dis, 0, sizeof(dis));
    while( cin >> n) {
        for (int i = 1; i <= n; ++i) {
            cin >> gas[i];
        }
        for (int i = 1; i < n; ++i) {
            int u, v, c;
            cin >> u >> v >> c;
            graph[u].push_back({v, c});
            graph[v].push_back({u, c});
        }
        ans = gas[1];
        dfs(1, 0, 0);
        cout << ans << endl;
        memset(dis, 0, sizeof(dis));
        for (int i = 1; i <= n; ++i) {
            graph[i].clear();
        }
    }
    return 0;
}