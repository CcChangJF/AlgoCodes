
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

typedef struct edge{
    int dest;
    int k;
}edge;

const int maxN = 2000005;
vector<edge> graph[maxN];
bool mark[maxN];
vector<edge> keyOpen[maxN];

void bfs() {
    queue<int> q;
    q.push(1);
    mark[1] = true;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < graph[u].size(); ++i) {
            edge e = graph[u][i];
            if (!mark[e.dest] && (0 == e.k || mark[e.k])) {
                mark[e.dest] = true;
                q.push(e.dest);
                for (int j = 0; j < keyOpen[e.dest].size(); ++j) {
                    edge eOpen = keyOpen[e.dest][j];
                    if (mark[eOpen.dest] && !mark[eOpen.k]) {
                        mark[eOpen.k] = true;
                        q.push(eOpen.k);
                    }
                }
            }
        }
    }
    return;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back({v, c});
        if (0 != c) {
            keyOpen[c].push_back({u, v});
        }
    }
    bfs();
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (mark[i]) { ++ans;}
    }
    cout << ans << endl;
    return 0;
}