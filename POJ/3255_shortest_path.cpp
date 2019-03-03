
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

const int N = 5003;
struct Edge{
    int to,cost;
};

vector<Edge> graph[N];
int dis[N][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,r;
    cin >> n >> r;
    for (int i = 0; i < r; ++i) {
        int u,v,c;
        // cin >> u >> v >> c;
        scanf("%d%d%d", &u, &v, &c);
        Edge e1 = {v, c};
        graph[u].push_back(e1);
        e1.to = u;
        graph[v].push_back(e1);
    }
    memset(dis, 0x3f, sizeof(dis));
    dis[1][0] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(pii(0, 1));
    while(!pq.empty()) {
        pii cur = pq.top();
        pq.pop();
        int v = cur.second;
        // cout << "dis: " << dis[v][0] << ", " << cur.first << endl;
        if (dis[v][1] < cur.first) { continue; }
        // cout << v << endl;
        for (int i = 0; i < graph[v].size(); ++i) {
            Edge e = graph[v][i];
            int curDis = cur.first + e.cost;
            if (dis[e.to][1] > curDis) {
                dis[e.to][1] = curDis;
                if (dis[e.to][1] < dis[e.to][0]) {
                    swap(dis[e.to][1], dis[e.to][0]);
                }
                pq.push(pii(curDis, e.to));
                // cout << e.to << "|" << dis[e.to][0] << endl;
            }
        }

    }
    cout << dis[n][1] << endl;

    return 0;
}