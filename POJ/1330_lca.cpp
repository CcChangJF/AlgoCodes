
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
#include <bitset>
#include <cmath>
#include <climits>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<int, long long> pil;
typedef std::pair<long long, long long> pll;

using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 10003;

vector<int> graph[N];
int depth[N];
int dis[N][32];
int maxDep = 0;

void bfs(int node) {
    queue<int> q;
    q.push(node);
    depth[node] = 1;
    dis[node][0] = node;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < graph[cur].size(); ++i) {
            int v = graph[cur][i];
            depth[v] = depth[cur] + 1;
            dis[v][0] = cur;
            q.push(v);
        }
    }
    return; 
}

void dfs(int node, int par) {
    depth[node] = depth[par] + 1;
    dis[node][0] = par;
    for (int i = 0; i < graph[node].size(); ++i) {
        int v = graph[node][i];
        if (v == par) { continue; }
        dfs(v, node);
    }
    return;
}

void initPar(int n) {
    for (int i = 0; i < n; ++i) {
        if (depth[i] > maxDep) { maxDep = depth[i]; }
    }
    int highBit = 0;
    while ( 0 != maxDep ) {
        ++highBit;
        maxDep >>= 1;
    }
    maxDep = highBit;

    for (int d = 1; d < maxDep; ++d) {
        for (int i = 1; i < n + 1; ++i) {
            dis[i][d] = dis[dis[i][d - 1]][d - 1];
        }
    }
    return;
}

int lca(int qu, int qv) {
    if (depth[qu] < depth[qv]) { swap(qu, qv); }
    int gap = depth[qu] - depth[qv];
    int cnt = 0;
    while(0 != gap) {
        if (1 == (gap & 1)) {
            qu = dis[qu][cnt];
        }
        gap >>= 1;
        ++cnt;
    }
    if (qu == qv) { return qu; }
    for (int i = maxDep - 1; i >= 0; --i) {
        if (dis[qu][0] == dis[qv][0]) { break; }
        if (dis[qu][i] != dis[qv][i]) {
            qu = dis[qu][i];
            qv = dis[qv][i];
        }
        // cout << i << ": " << qu << ", " << qv << endl;
    }
    return dis[qu][0];
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for (int i = 1; i < n + 1; ++i) { depth[i] = i;}
        for (int i = 1; i < n; ++i) {
            int u,v;
            cin >> u >> v;
            graph[u].push_back(v);
            depth[v] = u;
        }
        int qu,qv;
        cin >> qu >> qv;
        int root = 1;
        while(root != depth[root]) { root = depth[root]; }
        memset(depth, 0, sizeof(depth));
        maxDep = 0;
        // bfs(root);
        depth[root] = 0;
        dfs(root, root);
        initPar(n);

        cout << lca(qu, qv) << endl;

        for (int i = 1; i < n + 1; ++i) {
            graph[i].clear();
        }
        memset(depth, 0, sizeof(depth));
        memset(dis, 0, sizeof(dis));
    }
    return 0;
}